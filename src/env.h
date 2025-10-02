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

#ifndef ENV_H
#define ENV_H

Env *new_env(Env *parent);
void env_set(Env *env, char *name, Value *val, bool is_const);
void env_update(Env *env, char *name, Value *val);
Value *env_get(Env *env, char *name);
void free_env(Env *env, bool recurse);
#endif
