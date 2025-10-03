/**
 * @file env.c
 * @brief Environment / State-handling
 * Copyright (c) 2026 blu3
 **/

/**************************************************************************\
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

#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "ml.h"
#include "env.h"



extern int yylineno;

/* Environment Reference Counting Helpers */

/**
 * @brief Increases the reference count of an environment.
 * @param env The environment to retain.
 */
void env_retain(Env *env) {
    if (env) {
        env->ref_count++;
    }
}

/**
 * @brief Decreases the reference count of an environment.
 * Frees the environment if the count drops to zero.
 * @param env The environment to release.
 */
void env_release(Env *env) {
    if (!env) return;

    if (env->ref_count > 0) {
        env->ref_count--;
    }

    if (env->ref_count == 0) {
        free_env(env, false);
    }
}

/**
 * @brief Frees all bindings and the Env struct itself, without recursing up the parent chain.
 * @param e The environment to clean up.
 */
static void env_cleanup_bindings(Env *e) {
    if (!e) return;

    Binding *b = e->bindings;
    while (b) {
        Binding *nxt = b->next;
        if (b->val) {
            free_value(b->val);
        }
        if (b->name) {
            free(b->name);
        }
        free(b);
        b = nxt;
    }

    e->bindings = NULL;
    free(e);
    e = NULL;
}

/* ---------- Environment Implementation ---------- */

Env *new_env(Env *parent) {
    Env *e = calloc(1, sizeof(Env));

    if (!e) {
        fprintf(stderr, "Fatal: calloc failed in new_env\n");
        exit(EXIT_FAILURE);
    }
    e->parent = parent;
    e->bindings = NULL;
    e->ref_count = 1;
    return e;
}

/**
 * @brief Frees an environment.
 * @param env The environment to free.
 * @param recurse Whether to free parent environments as well.
 */
void free_env(Env *env, bool recurse) {
    if (!env) return;

    Env *e = env;
    while (e) {
        Env *next_env = e->parent;

        env_cleanup_bindings(e);

        if (!recurse) break;
        e = next_env;
    }
}

void env_set(Env *env, char *name, Value *val, bool is_const) {
    if (!env) {
        fprintf(stderr, "env_set: env is NULL\n");
        exit(EXIT_FAILURE);
    }

    Binding *b = malloc(sizeof(Binding));
    if (!b) {
        fprintf(stderr, "Line %d: Fatal, malloc failed for '%s' in env_set\n", yylineno, name);
        exit(EXIT_FAILURE);
    }

    // Use strdup to properly allocate and copy the string
    b->name = strdup(name);
    if (!b->name) {
        fprintf(stderr, "Line %d: Fatal, strdup failed for '%s' in env_set\n", yylineno, name);
        free(b);
        b = NULL;
        exit(EXIT_FAILURE);
    }

    b->val = val;
    b->is_const = is_const;
    b->next = env->bindings;
    env->bindings = b;
}

Value *env_get(Env *env, char *name) {
    for (Env *e = env; e; e = e->parent) {
        for (Binding *b = e->bindings; b; b = b->next) {
            // Add safety check for NULL name
            if (b->name && strcmp(b->name, name) == 0) {
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
            // Add safety check for NULL name
            if (b->name && strcmp(b->name, name) == 0) {
                if (b->is_const) {
                    fprintf(stderr, "Line %d: Error cannot assign to constant '%s'\n", yylineno, name);
                    return;
                }
                if (b->val) {
                    free_value(b->val);
                    b->val = NULL;
                }
                b->val = val;
                return;
            }
        }
    }
    fprintf(stderr, "Line %d: Error assignment to undefined variable '%s'\n", yylineno, name);
}
