/******************************************************************
*                                                                 *
* Copyright (C) 2015-2017 by HxP Studio                           *
* This file is part of {Project}                              	  *
*                                                                 *
* {Project} is free software.                                     *
* You can redistribute or modify it under the terms               *
* of the GNU Lesser General Public License as published           *
* by the Free Software Foundation, either                         *
* version 3 of the License, or (at your option) any               *
* later version provided you include a copy of the                *
* licence and this header.                                        *
* See GNU GENERAL PUBLIC LICENSE for more details.                *
*                                                                 *
* {Project} is redistributed to help you with                     *
* your next projects, but WITHOUT ANY WARRANTY;                   *
* without even the implied warranty of                            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.            *
*                                                                 *
* You should have received a copy of                              *
* the GNU GENERAL PUBLIC LICENSE along with {Project}.            *
* If you not have a copy of the                                   *
* GNU GENERAL PUBLIC LICENSE see: http://www.gnu.org/licenses     *
*                                                                 *
******************************************************************/
 
/**
*  \file     template.c
*  \date     30 April 2017
*  \author   HunterxPokemon
*  \brief    template include
*
*  \details  This is a template file.
*/
#include "types.h"
#include "rom_functions.h"
#include "agb_debug.h"

#define LASTRESULT 0x800D

extern u16 *lastresult;

/**
*  \brief    Main Function
*  
*  \return   Return Nothing
*  
*  \details  nothing.
*/
void capsule_machine(void)
{
    // table of pokemon
    u16 poke_gen1_table[] = {50, 151, 5};
    // pokemon
    u16 poke;
    // random value for table
    u16 rand_value = get_random_change_seed() % 3;
    
    // generate random pokemon from table
    poke = poke_gen1_table[rand_value];
    // get offset of lastresult
    u16* value = var_access(LASTRESULT);
    // set lastresult to pokemon
    *value = poke;
    
    fade_screen(0xFFFFFFFF, 1, 16, 0, 0x0000);
}

// EOF
