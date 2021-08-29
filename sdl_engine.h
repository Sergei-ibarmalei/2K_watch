#ifndef SDL_ENGINE_H
#define SDL_ENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "alltype.h"



sdl_statusType sdl_init(sdlType* psdl, char* name, int s_width, int s_height);
void sdl_check_status(sdl_statusType);
void sdl_clearscreen(sdlType* );
void sdl_make_rectangle(SDL_Rect* rect, plot_t* upleft, int w, int h);

#endif
