/**
 * @file env.h
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

#ifndef ENV_H
#define ENV_H

#include <stdbool.h>


struct Value;
struct Env;

typedef struct Value Value;
typedef struct Env Env;


/**
 * @brief Represents a single name-to-value binding in a scope.
 */

typedef struct Binding {
    char *name;              /* The name of the variable. */
    Value *val;              /* The value it is bound to. */
    bool is_const;           /* A flag to indicate if the binding is immutable. */
    struct Binding *next;    /* Pointer to the next binding in the same scope. */
} Binding;



// Declare the new functions in 'env.h'
/**
 * @brief Increases the reference count of an environment.
 * @param env The environment to retain.
 */
 void env_retain(Env *env);

/**
 * @brief Decreases the reference count of an environment.
 * Frees the environment if the count drops to zero.
 * @param env The environment to release.
 */
 void env_release(Env *env);

/**
 * @brief Frees all bindings and the Env struct itself, without recursing up the parent chain.
 * This is the actual memory deallocation logic, now called by free_env.
 * @param env The environment to clean up.
 */
static void env_cleanup_bindings(Env *e);

/**
* @brief Create a new environment, inheriting from a parent env
* @param parent A parent enironment
**/

 Env *new_env(Env *parent);

/**
 * @brief Frees an environment. If ref_count is 0, it cleans up all resources.
 * If recurse is true, it frees parents (used for global/REPL cleanup).
 * If recurse is false, it only frees the current scope if its ref_count is 0.
 *
 * NOTE: For local scopes in 'eval', free_env(local, false) will be replaced
 * by env_release(local), which only calls cleanup if ref_count is 0.
 *
 * @param env The environment to free.
 * @param recurse Whether to free parent environments as well.
 */
 void free_env(Env *env, bool recurse);

/**
 * @brief Get a variable from environment.
 **/
 Value *env_get(Env *env, char *name);

/**
 * @brief Set a variable to a value in the environment
 **/
 void env_set(Env *env, char *name, Value *val, bool is_const);

/**
 * @brief Update the value of a variable in the environment
 **/
 void env_update(Env *env, char *name, Value *val);


#endif
