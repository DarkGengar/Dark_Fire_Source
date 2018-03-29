/******************************************************************
 *                                                                 *
 * Copyright (C) 2015-2017 by DarkGengar                           *
 * This file is part of Pokémon Dark Fire                          *
 *                                                                 *
 * Pokémon Dark Fire is free software.                             *
 * You can redistribute or modify it under the terms               *
 * of the GNU Lesser General Public License as published           *
 * by the Free Software Foundation, either                         *
 * version 3 of the License, or (at your option) any               *
 * later version provided you include a copy of the                *
 * licence and this header.                                        *
 * See GNU GENERAL PUBLIC LICENSE for more details.                *
 *                                                                 *
 * Pokémon Dark Fire is redistributed to help you with             *
 * your next projects, but WITHOUT ANY WARRANTY;                   *
 * without even the implied warranty of                            *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.            *
 *                                                                 *
 * You should have received a copy of                              *
 * the GNU GENERAL PUBLIC LICENSE along with Pokémon Dark Fire.    *
 * If you not have a copy of the                                   *
 * GNU GENERAL PUBLIC LICENSE see: http://www.gnu.org/licenses     *
 *                                                                 *
 ******************************************************************/
/**
 * @file     task.h
 * @date     25.03.2018
 * @author   DarkGengar <https://github.com/DarkGengar>
 * @brief    brief description
 *
 * @details  More Details
 */

/* -- Includes -- */
#include "types.h"

#ifndef TASK_H
#define TASK_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Task function.
 *
 * @param id The ID of the the current task
 */
typedef void (*TaskCallback)(u8 id);


/**
 * A short-lived background function with state.
 */
struct Task {
    TaskCallback function; /**< Function to run */
    boolean inuse;
    u8 prev;
    u8 next;
    u8 priority;
    s16 priv[16]; /**< State variables */
};

/**
 * All the tasks.
 */
extern struct Task tasks[16];

extern void tasks_init(void);

/**
 * Start a new task.
 *
 * @param func Function pointer
 * @return Task ID
 * @address{BPRE,0807741C}
 */
extern u8 task_add(TaskCallback func, u8 priority);

/**
 * Execute all active tasks once.
 */
extern void task_exec(void);


#ifdef __cplusplus
}
#endif

#endif /* TASK_H */


/* -- EOF -- */