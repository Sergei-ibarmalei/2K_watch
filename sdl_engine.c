#include "sdl_engine.h"
#include <stdio.h>


static int imgFlags = 0;

void sdl_check_status(sdl_statusType status)
{
  switch (status)
  {
    case SDL_STATUS_OK:
            break;
    case SDL_STATUS_ERROR_INIT:
            {
              printf("Warning: SDL initialization not enable, error\n");
              break;
            }
    case SDL_STATUS_ERROR_LINEARTEXTURE:
            {
              printf("Warning: Linear texture filtering not enable, error\n");
              break;
            }
    case SDL_STATUS_ERROR_WINDOWCREATION:
            {
              printf("Window could not be created, error\n");
              break;
            }
    case SDL_STATUS_ERROR_RENDERCREATION:
            {
              printf("Render could not be created, error\n");
              break;
            }
    case SDL_STATUS_ERROR_PNGLOADING:
            {
              printf("SDL image could not be initialize, error\n");
              break;
            }
     case SDL_STATUS_ERROR_TTFLOADING:
            {
              printf("SDL TTF could not be initialize, error\n");
              break;
            }
     default: {}


  }
}



sdl_statusType sdl_init(sdlType* psdl, char* name, int s_width, int s_height)
{
  sdl_statusType status = SDL_STATUS_OK;
  /* Инициализация SDL */
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    status = SDL_STATUS_ERROR_INIT;
  }
  else
  {
    /* Set texture filtering to linear */
    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
    {
      status = SDL_STATUS_ERROR_LINEARTEXTURE;
    }  
    /* Create widnow */
    psdl->gWindow = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                     s_width, s_height, SDL_WINDOW_SHOWN);
    /*psdl->gWindow = SDL_CreateWindow(SDL_NOFRAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                     s_width, s_height, SDL_WINDOW_SHOWN);*/
    /*psdl->gWindow = SDL_SetVideoMode(s_width, s_height,0,SDL_SWSURFACE|SDL_NOFRAME);*/

    /*      -------------------BORDER----------------------*/
    SDL_SetWindowBordered(psdl->gWindow, SDL_FALSE);

    if(!psdl->gWindow)
    {
      status = SDL_STATUS_ERROR_WINDOWCREATION;
    }
    else
    {
      /* Create render for window */
      psdl->gRenderer = SDL_CreateRenderer(psdl->gWindow, -1, SDL_RENDERER_ACCELERATED);
      if(!psdl->gRenderer)
      {
        status = SDL_STATUS_ERROR_RENDERCREATION;
      }
      else
      {
        /* Initialize render color */
        SDL_SetRenderDrawColor(psdl->gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        /* Initialize PNG loading */
        imgFlags = IMG_INIT_PNG;
        if(!(IMG_Init(imgFlags) & imgFlags))
        {
          status = SDL_STATUS_ERROR_PNGLOADING;
        } 
        if(TTF_Init() == -1)
        {
          status = SDL_STATUS_ERROR_TTFLOADING;
        }
      }
    }
  }

  return status;
}

void sdl_clearscreen(sdlType* pmysdl)
{
        SDL_SetRenderDrawColor(pmysdl->gRenderer, 0x0, 0x0, 0x0, 0xFF);
        SDL_RenderClear(pmysdl->gRenderer);
}


void sdl_make_rectangle(SDL_Rect* rect, plot_t* upleft, int w, int h)
{
        rect->x = upleft->x;
        rect->y = upleft->y;
        rect->w = w;
        rect->h = h;
}


