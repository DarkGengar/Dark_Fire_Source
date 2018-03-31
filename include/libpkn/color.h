#include "types.h"

#ifndef COLOR_H
#define COLOR_H


#define rgb5(r, g, b) (COLOR)(r | (g << 5) | (b << 10))

#define CLR_BLACK   rgb5(0, 0, 0)
#define CLR_WHITE   rgb5(255, 255, 255)
#define CLR_RED	    rgb5(255, 0, 0)
#define CLR_GREEN   rgb5(0, 255, 0)
#define CLR_BLUE    rgb5(0, 0, 255)


#endif //COLOR_H