/**
 * @file env.c
 * @beief Environment / State-handling
 * Copyright (c) 2026 blu3
 **/

 /************************************************************************** \
 *                                                                        *
 *  This program is free software: you can redistribute it and/or modify  *
 *  it under the terms of the GNU General Public License as published by  *
 *  the Free Software Foundation, version 3.                              *
 *                                                                        *
 *  This program is distributed in the hope that it will be useful, but   *
 *  WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU      *
 *  General Public License for more details.                              *
 *                                                                        *
 *  You should have received a copy of the GNU General Public License     *
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.  *
 *                                                                        *
\**************************************************************************/

#include "calc.h"
#include "env.h"
extern void free_value(Value *v);
extern int yylineno;

    /* ---------- Environment Implementation ---------- */
Env *new_env(Env *parent) {

    Env *e = calloc(1, sizeof(Env));

    if (!e) {

        fprintf(stderr, "Fatal: calloc failed in new_env\n");
        exit(EXIT_FAILURE);
    }
    e->parent = parent;
    e->bindings = NULL;
    return e;
}
void free_env(Env *env, bool recurse) {
    if (!env) return;

    Env *e = env;
    while (e) {
        Binding *b = e->bindings;
        while (b) {
            Binding *nxt = b->next;
            if (b->val) {
                /* use free_value to properly release nested resources */
                free_value(b->val);
                b->val = NULL;
            }
            if (b->name) {
                free(b->name);
                b->name = NULL;
            }
            free(b);
            b = nxt;
        }
        e->bindings = NULL;
        Env *next_env = e->parent;
        free(e);
        if (!recurse) break;
        e = next_env;
    }
}
void env_set(Env *env, char *name, Value *val, bool is_const) {
    Binding *b = malloc(sizeof(Binding));

    if (!b) {
        fprintf(stderr, "Line %d: Fatal, malloc failed for '%s' in env_set\n", yylineno, name);
        exit(EXIT_FAILURE);
    }

    b->name = dupstr(name);
    b->val = val;
    b->is_const = is_const;
    b->next = env->bindings;
    env->bindings = b;
}

Value *env_get(Env *env, char *name) {
    for (Env *e = env; e; e = e->parent) {
        for (Binding *b = e->bindings; b; b = b->next) {
            if (strcmp(b->name, name) == 0) {
                /* return a duplicate so caller owns the result and can free it */
                return dup_value(b->val);
            }
        }
    }
    fprintf(stderr, "Line %d: Error undefined variable '%s'\n", yylineno, name);
    return NULL;
}

void env_update(Env *env, char *name, Value *val) {
    for (Env *e = env; e; e = e->parent) {
        for (Binding *b = e->bindings; b; b = b->next) {
            if (strcmp(b->name, name) == 0) {
                if (b->is_const) {
                    fprintf(stderr, "Line %d: Error cannot assign to constant '%s'\n", yylineno, name);
                    return;
                }
                // NOTE: This leaks the old value b->val.
                // Proper memory management requires reference counting or a GC.
                if (b->val) {
                    free_value(b->val);
                }
                b->val = val;
                return;
            }
        }
    }
    fprintf(stderr, "Line %d: Error assignment to undefined variable '%s'\n", yylineno, name);
}
