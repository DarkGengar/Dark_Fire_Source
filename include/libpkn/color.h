#include "types.h"

#ifndef COLOR_H
#define COLOR_H


typedef struct rgb{
	u16 red : 5;
	u16 green : 5;
	u16 blue : 5;
	u16 unused : 1;
} rgb;


typedef union color{
	
	u16 value;
	rgb rgb;
	
}color;

#endif //COLOR_H