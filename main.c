#include <stdio.h>
#include <time.h>
#include "sdl_engine.h"
#include "alltype.h"
#include "maintype.h"
#include "digit_engine.h"
#include "file_engine.h"
#include "draw_engine.h"
#include "time_engine.h"
#include "key_engine.h"



static sdlType mysdl;
static sdl_statusType sdl_status;

static digit_t back_digits;
static all_digits_t all_digits;
static digit_t  digits_on_screen;
static digit_lengths_t work_digit_lengths;
static digit_lengths_t back_digit_lengths;
static unsigned short second_flashing_count;
static times_t current_time;
static time_changes_t is_time_to_change;
static time_changes_t is_time_to_change_sec;
static int current_sec;

static program_status_t program_status;
static SDL_Event e;
static sdlType mysdl;
static second_flash_t sflash;


int main(int argc, char** argv)
{
        
        sflash = STOP_FLASH; /* not flashing seconds */
        second_flashing_count = 0; 
        te_get_current_time(&current_time);
        current_sec = te_get_current_sec();
#ifdef DEBUG
        te_show_time_in_console(&current_time);
#endif

        de_init_digits_on_screen(&digits_on_screen);

        program_status  = de_init_back_digits(&back_digits);
        if(program_status == APP_ABORT) return 1;

        dre_set_lengths(&back_digit_lengths, EIGHT_LENGTH,EIGHT_LENGTH,EIGHT_LENGTH, EIGHT_LENGTH);
        program_status = de_init_all_digits(&all_digits);
        if(program_status == APP_ABORT) return 1;

        te_fill_work_digits_by_time(&digits_on_screen,&all_digits, &current_time, &work_digit_lengths);

        sdl_status = sdl_init(&mysdl, "app", S_WIDTH, S_HEIGHT);
        if( sdl_status != SDL_STATUS_OK)
        {
                sdl_check_status(sdl_status);
                return 1;
        }
        program_status = APP_ON;
        while(program_status)
        {

                ke_check_key_pressing(&e, &program_status);

                sdl_clearscreen(&mysdl);
                if(sflash == STOP_FLASH)
                {
                        if((is_time_to_change_sec = te_fast_checking_time_sec(current_sec)) == TIME_CHANGED)
                        /* если изменилась одна секунда времени */
                        {
                                sflash = FLASHING;
                                current_sec = te_get_current_sec();
                        }
                }

                if(sflash == FLASHING) second_flashing_count ++;


                if( (is_time_to_change = te_fast_checking_time(&current_time)) == TIME_CHANGED)
                /* если изменилась одна минута */
                {
                        te_get_current_time(&current_time);
                        te_fill_work_digits_by_time(&digits_on_screen, &all_digits, &current_time, &work_digit_lengths);
                }

                dre_draw_digits(&mysdl, &back_digits,&back_digit_lengths, DIGIT_BACK, sflash); /* задний фон */
                dre_draw_digits(&mysdl, &digits_on_screen, &work_digit_lengths, DIGIT_NORMAL, sflash); /* рабочие цифры */
                SDL_RenderPresent(mysdl.gRenderer);

                if( (sflash == FLASHING) && (second_flashing_count > 10))
                /* моргаем только десять раз прохода главного цикла */
                {
                        sflash = STOP_FLASH;
                        second_flashing_count = 0;
                }
        }
        de_free_d(&back_digits);
        de_free_all_digits(&all_digits);
        
        return 0;
}


