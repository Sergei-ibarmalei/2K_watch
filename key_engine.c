#include "key_engine.h"

void ke_check_key_pressing(SDL_Event* e, program_status_t* program_status)
{
                 while (SDL_PollEvent(e) != 0)
                {
                        if(e->type == SDL_QUIT)
                                *program_status = APP_OFF;
                        else if(e->type == SDL_KEYDOWN)
                        {
                                switch(e->key.keysym.sym)
                                {
                                        case SDLK_q:
                                                {
                                                        *program_status = APP_OFF;
                                                        break;
                                                }
                                        default:{}
                                }
                        }
                        
                }       
}
