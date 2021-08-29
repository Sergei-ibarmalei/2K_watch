#include "color_engine.h"


void ce_get_grey(color_t* color)
{

        color->red = 0x2E;
        color->green = 0x2E;
        color->blue = 0x2E;
        color->alpha = 0xFF;
}




void ce_get_red(color_t* color)
{
        color->red = 0xFF;
        color->green = 0x0;
        color->blue = 0x0;
        color->alpha = 0x0;
}

