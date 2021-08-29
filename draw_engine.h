#ifndef DRAW_ENGINE_H
#define DRAW_ENGINE_H

#include "sdl_engine.h"
#include "alltype.h"

/*void de_draw_backs(sdlType* pmysdl, back_digit_t* backs);*/
/*void dre_draw_digits(sdlType* pmysdl, digit_t* digits, int nomber);*/
void dre_set_lengths(digit_lengths_t* dl, int hl, int hr, int ml, int mr);
void dre_draw_digits(sdlType* pmysdl, digit_t* digits, digit_lengths_t* dl,digit_screen_pos_t position, second_flash_t sflash );



#endif
