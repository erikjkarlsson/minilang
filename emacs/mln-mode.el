;;; mln-mode.el --- Major mode for editing .mln files -*- lexical-binding: t -*-

;; Copyright (C) 2026 blu3
;; Author: blu3
;; Version: 1.0
;; Package-Requires: ((emacs "24.3"))
;; Keywords: languages
;; URL: https://github.com/yourusername/mln-mode

;; This file is not part of GNU Emacs.

;; This program is free software; you can redistribute it and/or modify
;; it under the terms of the GNU General Public License as published by
;; the Free Software Foundation, either version 3 of the License, or
;; (at your option) any later version.

;; This program is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;; GNU General Public License for more details.

;; You should have received a copy of the GNU General Public License
;; along with this program.  If not, see <http://www.gnu.org/licenses/>.

;;; Commentary:

;; Major mode for editing .mln files (My Language Notation).
;; Provides syntax highlighting, indentation, and basic syntax checking.

;;; Code:

(defgroup mln nil
  "Major mode for editing .mln files."
  :group 'languages)

(defcustom mln-tab-width 2
  "Default tab width for MLN mode."
  :type 'integer
  :group 'mln)

(defcustom mln-indent-offset 2
  "Default indentation offset for MLN mode."
  :type 'integer
  :group 'mln)

;; Custom faces
(defface mln-keyword-face
  '((t (:inherit font-lock-keyword-face :weight bold)))
  "Face for MLN keywords."
  :group 'mln)

(defface mln-type-face
  '((t (:inherit font-lock-type-face :slant italic)))
  "Face for MLN types."
  :group 'mln)

(defface mln-operator-face
  '((t (:inherit font-lock-constant-face :weight bold)))
  "Face for MLN operators."
  :group 'mln)

(defface mln-builtin-face
  '((t (:inherit font-lock-builtin-face :weight bold)))
  "Face for MLN built-in functions."
  :group 'mln)

;; Syntax highlighting
(defvar mln-keywords
  '("if" "then" "else" "let" "in" "fun" "lambda" "const" "do" "end"
    "true" "false" "and" "or" "not")
  "MLN language keywords.")

(defvar mln-types
  '("int" "float" "bool" "string" "unit" "function")
  "MLN language types.")

(defvar mln-operators
  '("+" "-" "*" "/" "%" "=" "!=" "<" ">" "<=" ">=" ":=" "->" "::")
  "MLN language operators.")

(defvar mln-builtins
  '("print" "println" "read" "length" "head" "tail")
  "MLN built-in functions.")

(setq mln-font-lock-keywords
  `(;; Keywords
    (,(regexp-opt mln-keywords 'words) . 'mln-keyword-face)
    ;; Types
    (,(regexp-opt mln-types 'words) . 'mln-type-face)
    ;; Built-in functions
    (,(regexp-opt mln-builtins 'words) . 'mln-builtin-face)
    ;; Operators
    (,(regexp-opt mln-operators) . 'mln-operator-face)
    ;; Numbers
    ("\\_<[0-9]+\\_>\\|\\_<[0-9]+\\.[0-9]+\\_>" . font-lock-constant-face)
    ;; Strings
    ("\"\\.\\*\\?" . font-lock-string-face)
    ;; Comments
    ("#.*" . font-lock-comment-face)
    ;; Variables (lowercase identifiers)
    ("\\_<[a-z_][a-zA-Z0-9_]*\\_>" . font-lock-variable-name-face)
    ;; Constants (uppercase identifiers)
    ("\\_<[A-Z][A-Z0-9_]*\\_>" . font-lock-constant-face)
    ;; Function definitions
    ("\\(fun\\|let\\)\\s-+\\([a-zA-Z_][a-zA-Z0-9_]*\\)" 2 font-lock-function-name-face)
    ;; Lambda parameters
    ("lambda\\s-+\\([a-zA-Z_][a-zA-Z0-9_]*\\)" 1 font-lock-variable-name-face)))

;; Syntax table
(defvar mln-mode-syntax-table
  (let ((table (make-syntax-table)))
    ;; C++ style comments
    (modify-syntax-entry ?/ ". 124b" table)
    (modify-syntax-entry ?* ". 23" table)
    (modify-syntax-entry ?\n "> b" table)
    ;; String quotes
    (modify-syntax-entry ?\" "\"" table)
    ;; Parentheses
    (modify-syntax-entry ?\( "()" table)
    (modify-syntax-entry ?\) ")(" table)
    (modify-syntax-entry ?\{ "(}" table)
    (modify-syntax-entry ?\} "){" table)
    ;; Whitespace
    (modify-syntax-entry ?\s " " table)
    (modify-syntax-entry ?\t " " table)
    ;; Symbols
    (modify-syntax-entry ?_ "w" table)
    ;; Operators
    (modify-syntax-entry ?+ "." table)
    (modify-syntax-entry ?- "." table)
    (modify-syntax-entry ?= "." table)
    (modify-syntax-entry ?< "." table)
    (modify-syntax-entry ?> "." table)
    (modify-syntax-entry ?! "." table)
    table)
  "Syntax table for MLN mode.")

;; Indentation
(defun mln-calculate-indentation ()
  "Calculate the appropriate indentation for the current line."
  (save-excursion
    (beginning-of-line)
    (let ((indent 0)
          (containing-sexp (save-excursion
                             (mln-backward-up-list))))
      (when containing-sexp
        (goto-char containing-sexp)
        (setq indent (+ (current-indentation) mln-indent-offset)))
      indent)))

(defun mln-backward-up-list ()
  "Move backward out of any nested brackets/parens.
Return the position of the opening bracket/paren, or nil if at top level."
  (let ((pos (point)))
    (condition-case nil
        (progn
          (backward-up-list 1)
          (point))
      (scan-error
       (goto-char pos)
       nil))))

(defun mln-indent-line ()
  "Indent current line as MLN code."
  (interactive)
  (let* ((indent (mln-calculate-indentation))
         (pos (- (point-max) (point))))
    (indent-line-to indent)
    (when (> (- (point-max) pos) (point))
      (goto-char (- (point-max) pos)))))

;; Syntax checking
(defun mln-syntax-check ()
  "Perform basic syntax checking on the current buffer."
  (interactive)
  (save-excursion
    (goto-char (point-min))
    (let ((errors '()))
      ;; Check for unmatched parentheses
      (condition-case err
          (check-parens)
        (error (push (format "Unmatched parentheses: %s" (error-message-string err)) errors)))

      ;; Check for lines ending with operators
      (while (not (eobp))
        (when (looking-at ".*[+\\-*/%=]$")
          (push (format "Line %d: Line ends with operator" (line-number-at-pos)) errors))
        (forward-line))

      (if errors
          (message "Syntax errors found:\n%s" (mapconcat 'identity errors "\n"))
        (message "No syntax errors found.")))))

;; Keymap
(defvar mln-mode-map
  (let ((map (make-sparse-keymap)))
    (define-key map (kbd "C-c C-c") 'mln-syntax-check)
    (define-key map (kbd "C-c C-f") 'mln-format-buffer)
    map)
  "Keymap for MLN mode.")

;; Auto-mode alist
;;;###autoload
(add-to-list 'auto-mode-alist '("\\.mln\\'" . mln-mode))

;; Main mode function
;;;###autoload
(define-derived-mode mln-mode prog-mode "MLN"
  "Major mode for editing MLN files."
  :syntax-table mln-mode-syntax-table

  ;; Font locking
  (setq font-lock-defaults '(mln-font-lock-keywords nil t))

  ;; Indentation
  (setq tab-width mln-tab-width)
  (setq indent-tabs-mode nil)
  (set (make-local-variable 'indent-line-function) 'mln-indent-line)

  ;; Comment syntax
  (setq comment-start "# ")
  (setq comment-end "")

  ;; Other settings
  (setq mode-name "MLN")
  (setq major-mode 'mln-mode))

;; Utility functions
(defun mln-format-buffer ()
  "Format the current buffer."
  (interactive)
  (let ((start (point)))
    (indent-region (point-min) (point-max))
    (goto-char start)))

;; Menu
(easy-menu-define mln-mode-menu mln-mode-map
  "Menu for MLN mode."
  '("MLN"
    ["Check Syntax" mln-syntax-check t]
    ["Format Buffer" mln-format-buffer t]
    "---"
    ["Customize" (customize-group 'mln) t]))


(provide 'mln-mode)

;;; mln-mode.el ends here
