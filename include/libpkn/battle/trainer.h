#include "types.h"

#ifndef TRAINER_H
#define TRAINER_H

typedef struct 
{
	u8 gender 	: 7;
	u8 encounter	: 1;
	
}gender_encounter;

typedef struct
{
	u8 unknown_field;
	u8 trainer_class_id;
	gender_encounter byte;
	u8 unknown_field_2;
	char name[12];
	u8 unknown_fields[24];
	
}trainer;

trainer* trainer_base = (trainer*)0x0823E998;

#endif //TRAINER_H