#include "draw_engine.h"

void draw_digit(sdlType* pmysdl, box_t* digit_arr, int arr_length, digit_screen_pos_t position, second_flash_t sflash);


void draw_digit(sdlType* pmysdl, box_t* digit_arr, int arr_length, digit_screen_pos_t position, second_flash_t sflash)
{
        box_t* ptr = &digit_arr[0];
        for(;;)
        {
                if(ptr == &digit_arr[arr_length]) break;
                
                SDL_SetRenderDrawColor(pmysdl->gRenderer, ptr->box_color.red,ptr->box_color.green,ptr->box_color.blue,
                                ptr->box_color.alpha);
                switch(position)
                {
                        case DIGIT_BACK:
                                {
                                        if(sflash == FLASHING)
                                                SDL_RenderFillRect(pmysdl->gRenderer, &ptr->box_rectangle);
                                        else
                                                SDL_RenderDrawRect(pmysdl->gRenderer, &ptr->box_rectangle);
                                        break;
                                }
                        case DIGIT_NORMAL:
                                {
                                        SDL_RenderFillRect(pmysdl->gRenderer, &ptr->box_rectangle);break;
                                }
                        default:{}
                }
                /*SDL_RenderDrawRect(pmysdl->gRenderer, &ptr->box_rectangle);*/
                /*SDL_RenderFillRect(pmysdl->gRenderer, &ptr->box_rectangle);*/
                ptr++;
        }
}

void dre_draw_digits(sdlType* pmysdl, digit_t* digits, digit_lengths_t* dl,digit_screen_pos_t position,second_flash_t sflash )
{

        draw_digit(pmysdl, digits->digit_ml, dl->length_ml, position, sflash); /* рисуем минуты левый сегмент */
        draw_digit(pmysdl, digits->digit_mr, dl->length_mr, position, sflash); /* рисуем минуты правый сегмент*/
        
        if( (dl->length_hr == ZERO_LENGTH) && (dl->length_hl == ZERO_LENGTH) )
        /* если часы по нулям, то отрисовываем и выходим */
        {
                draw_digit(pmysdl, digits->digit_hl, dl->length_hl, position, sflash);
                draw_digit(pmysdl, digits->digit_hr, dl->length_hr, position, sflash);
                return;
        }

        draw_digit(pmysdl, digits->digit_hr, dl->length_hr, position, sflash); /* рисуем часы правый сегмент в любом случае */
        if(dl->length_hl == ZERO_LENGTH) return; /* если в часах левая позиция 0, то выходим не отрисовывая */
        else
              draw_digit(pmysdl, digits->digit_hl, dl->length_hl, position, sflash); /* рисуем часы левый сегмент */

}

void dre_set_lengths(digit_lengths_t* dl, int hl, int hr, int ml, int mr)
{
        dl->length_hl = hl;
        dl->length_hr = hr;
        dl->length_ml = ml;
        dl->length_mr = mr;
}
