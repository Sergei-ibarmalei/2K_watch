#include "digit_engine.h"


void fill_digit_by_coord(box_t* , plot_t* coords, digit_position_t position, int arr_length, digit_screen_pos_t pos);
program_status_t init_digit(digit_t* digit, int nomber);
void free_d(digit_t* digit);



program_status_t de_init_back_digits(digit_t* bd)
{
        plot_t* tmp_digit_coords = NULL;
        bd->digit_hl = malloc(sizeof(box_t[EIGHT_LENGTH]));
        bd->digit_hr = malloc(sizeof(box_t[EIGHT_LENGTH]));
        bd->digit_ml = malloc(sizeof(box_t[EIGHT_LENGTH]));
        bd->digit_mr = malloc(sizeof(box_t[EIGHT_LENGTH]));

        tmp_digit_coords = fe_load_digit_coords(8, EIGHT_LENGTH);
        if(!tmp_digit_coords)
        {
                printf("\nCannot load ligit, abort.\n");
                return APP_ABORT;
        }
        else
        {
                fill_digit_by_coord(bd->digit_hl, tmp_digit_coords, HOUR_LEFT, EIGHT_LENGTH, DIGIT_BACK);
                fill_digit_by_coord(bd->digit_hr, tmp_digit_coords, HOUR_RIGHT, EIGHT_LENGTH, DIGIT_BACK);
                fill_digit_by_coord(bd->digit_ml, tmp_digit_coords, MINUTE_LEFT, EIGHT_LENGTH, DIGIT_BACK);
                fill_digit_by_coord(bd->digit_mr, tmp_digit_coords, MINUTE_RIGHT, EIGHT_LENGTH, DIGIT_BACK);
                return APP_OK;
        }

}

void fill_digit_by_coord(box_t* digit, plot_t* coords, digit_position_t position, int arr_length, digit_screen_pos_t pos)
{
        int digit_center_x;
        int digit_center_y;
        box_t* ptr_digit = &digit[0];
        plot_t* ptr_coord = &coords[0];

        switch (position)
        {
                case HOUR_LEFT:
                        {
                                digit_center_x = SCREEN_PAD_LEFT + (int)(DIGIT_WIDTH /2) - (int)(SCREEN_PAD_LEFT/2); 
                                digit_center_y = (int)S_HEIGHT/2;
                                break;
                        }
                case HOUR_RIGHT:
                        {
                                digit_center_x = SCREEN_PAD_LEFT+DIGIT_PAD+DIGIT_WIDTH + (int)(DIGIT_WIDTH/2) - (int)(SCREEN_PAD_LEFT/2);
                                digit_center_y = (int)S_HEIGHT/2;
                                break;
                        }
                case MINUTE_LEFT:
                        {
                                digit_center_x = SCREEN_PAD_LEFT+2*DIGIT_PAD+2*DIGIT_WIDTH + (int)(DIGIT_WIDTH/2) + (int)(SCREEN_PAD_LEFT/2);
                                digit_center_y = (int)S_HEIGHT/2;
                                break;
                        }
                case MINUTE_RIGHT:
                        {
                                digit_center_x = SCREEN_PAD_LEFT + 3*DIGIT_PAD+3*DIGIT_WIDTH +(int)(DIGIT_WIDTH/2) + (int)(SCREEN_PAD_LEFT/2);
                                digit_center_y = (int)S_HEIGHT/2;
                                break;
                        }
                default:{}
        }

        for(;;)
        {
                if(ptr_digit ==&digit[arr_length]) break;
                /*ptr_digit->box_upleft = *ptr_coord; 
                ptr_digit->box_upleft.x = digit_center_x + ptr_digit->box_upleft.x; 
                ptr_digit->box_upleft.y = digit_center_y + ptr_digit->box_upleft.y;
                ptr_digit->box_rectangle.x =ptr_digit->box_upleft.x;
                ptr_digit->box_rectangle.y = ptr_digit->box_upleft.y;
                ptr_digit->box_rectangle.w = ptr_digit->box_rectangle.h = SIDE;*/

                ptr_digit->box_rectangle.x = ptr_coord->x + digit_center_x;
                ptr_digit->box_rectangle.y = ptr_coord->y + digit_center_y;
                /*ptr_digit->box_rectangle.x += digit_center_x;
                ptr_digit->box_rectangle.y += digit_center_y;*/
                ptr_digit->box_rectangle.w = ptr_digit->box_rectangle.h = SIDE;


                switch(pos)
                {
                        case DIGIT_BACK:
                                {
                                        ce_get_grey(&ptr_digit->box_color);break;
                                }
                        case DIGIT_NORMAL:
                                {
                                        ce_get_red(&ptr_digit->box_color);break;
                                }
                }
                ptr_digit++;
                ptr_coord++;
        }

} 




program_status_t de_init_all_digits(all_digits_t* alld)
{
       
       program_status_t program_status;
       plot_t* tmp_digit_coords = NULL;
#ifdef DEBUG
       char* info = "(in function de_init_all_digits) Cannot allocate memory for digit: ";
#endif
       
       program_status = init_digit(&alld->one,1);
       if(program_status == APP_ABORT)
       {
#ifdef DEBUG
               printf("\n%s one\n", info);
#endif
               return program_status;
       } 
       else
       {
               tmp_digit_coords = fe_load_digit_coords(1, ONE_LENGTH);
       }
       if(!tmp_digit_coords)
       {
               printf("\nCannot load digit one, abort.\n");
               return APP_ABORT;
       }
       else
       {
               fill_digit_by_coord(alld->one.digit_hl, tmp_digit_coords, HOUR_LEFT, ONE_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->one.digit_hr, tmp_digit_coords, HOUR_RIGHT, ONE_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->one.digit_ml, tmp_digit_coords, MINUTE_LEFT, ONE_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->one.digit_mr, tmp_digit_coords, MINUTE_RIGHT, ONE_LENGTH, DIGIT_NORMAL);
                             
       }

       program_status = init_digit(&alld->two,2);
       if(program_status == APP_ABORT) 
       {
#ifdef DEBUG
               printf("\n%s two\n", info);
#endif
               return program_status;
       }
       else
       {
               tmp_digit_coords = fe_load_digit_coords(2, TWO_LENGTH);
       }
       if(!tmp_digit_coords)
       {
               printf("\nCannot load digit two, abort.\n");
               return APP_ABORT;
       }
       else
       {
               fill_digit_by_coord(alld->two.digit_hl, tmp_digit_coords, HOUR_LEFT, TWO_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->two.digit_hr, tmp_digit_coords, HOUR_RIGHT, TWO_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->two.digit_ml, tmp_digit_coords, MINUTE_LEFT, TWO_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->two.digit_mr, tmp_digit_coords, MINUTE_RIGHT, TWO_LENGTH, DIGIT_NORMAL);
                             
       }

       program_status = init_digit(&alld->three,3);
       if(program_status == APP_ABORT) 
       {
#ifdef DEBUG
               printf("\n%s three\n", info);
#endif
               return program_status;
       }
       else
       {
               tmp_digit_coords = fe_load_digit_coords(3, THREE_LENGTH);
       }
       if(!tmp_digit_coords)
       {
               printf("\nCannot load digit three, abort.\n");
               return APP_ABORT;
       }
       else
       {
               fill_digit_by_coord(alld->three.digit_hl, tmp_digit_coords, HOUR_LEFT, THREE_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->three.digit_hr, tmp_digit_coords, HOUR_RIGHT, THREE_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->three.digit_ml, tmp_digit_coords, MINUTE_LEFT, THREE_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->three.digit_mr, tmp_digit_coords, MINUTE_RIGHT, THREE_LENGTH, DIGIT_NORMAL);
                             
       }

       program_status = init_digit(&alld->four,4);
       if(program_status == APP_ABORT) 
       {
#ifdef DEBUG
               printf("\n%s four\n", info);
#endif
               return program_status;
       }
       else
       {
               tmp_digit_coords = fe_load_digit_coords(4, FOUR_LENGTH);
       }
       if(!tmp_digit_coords)
       {
               printf("\nCannot load digit four, abort.\n");
               return APP_ABORT;
       }
       else
       {
               fill_digit_by_coord(alld->four.digit_hl, tmp_digit_coords, HOUR_LEFT, FOUR_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->four.digit_hr, tmp_digit_coords, HOUR_RIGHT, FOUR_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->four.digit_ml, tmp_digit_coords, MINUTE_LEFT, FOUR_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->four.digit_mr, tmp_digit_coords, MINUTE_RIGHT, FOUR_LENGTH, DIGIT_NORMAL);
                             
       }

       program_status = init_digit(&alld->five,5);
       if(program_status == APP_ABORT) 
       {
#ifdef DEBUG
               printf("\n%s five\n", info);
#endif
               return program_status;
       }
       else
       {
               tmp_digit_coords = fe_load_digit_coords(5, FIVE_LENGTH);
       }
       if(!tmp_digit_coords)
       {
               printf("\nCannot load digit five, abort.\n");
               return APP_ABORT;
       }
       else
       {
               fill_digit_by_coord(alld->five.digit_hl, tmp_digit_coords, HOUR_LEFT, FIVE_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->five.digit_hr, tmp_digit_coords, HOUR_RIGHT, FIVE_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->five.digit_ml, tmp_digit_coords, MINUTE_LEFT, FIVE_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->five.digit_mr, tmp_digit_coords, MINUTE_RIGHT, FIVE_LENGTH, DIGIT_NORMAL);
                             
       }

       program_status = init_digit(&alld->six,6);
       if(program_status == APP_ABORT) 
       {
#ifdef DEBUG
               printf("\n%s six\n", info);
#endif
               return program_status;
       }
       else
       {
               tmp_digit_coords = fe_load_digit_coords(6, SIX_LENGTH);
       }
       if(!tmp_digit_coords)
       {
               printf("\nCannot load digit six, abort.\n");
               return APP_ABORT;
       }
       else
       {
               fill_digit_by_coord(alld->six.digit_hl, tmp_digit_coords, HOUR_LEFT, SIX_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->six.digit_hr, tmp_digit_coords, HOUR_RIGHT, SIX_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->six.digit_ml, tmp_digit_coords, MINUTE_LEFT, SIX_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->six.digit_mr, tmp_digit_coords, MINUTE_RIGHT, SIX_LENGTH, DIGIT_NORMAL);
                             
       }      

       program_status = init_digit(&alld->seven,7);
       if(program_status == APP_ABORT) 
       {
#ifdef DEBUG
               printf("\n%s seven\n", info);
#endif
               return program_status;
       }
       else
       {
               tmp_digit_coords = fe_load_digit_coords(7, SEVEN_LENGTH);
       }
       if(!tmp_digit_coords)
       {
               printf("\nCannot load digit seven, abort.\n");
               return APP_ABORT;
       }
       else
       {
               fill_digit_by_coord(alld->seven.digit_hl, tmp_digit_coords, HOUR_LEFT, SEVEN_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->seven.digit_hr, tmp_digit_coords, HOUR_RIGHT, SEVEN_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->seven.digit_ml, tmp_digit_coords, MINUTE_LEFT, SEVEN_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->seven.digit_mr, tmp_digit_coords, MINUTE_RIGHT, SEVEN_LENGTH, DIGIT_NORMAL);
                             
       }

       program_status = init_digit(&alld->eight,8);
       if(program_status == APP_ABORT) 
       {
#ifdef DEBUG
               printf("\n%s eight\n", info);
#endif
               return program_status;
       }
       else
       {
               tmp_digit_coords = fe_load_digit_coords(8, EIGHT_LENGTH);
       }
       if(!tmp_digit_coords)
       {
               printf("\nCannot load digit eight, abort.\n");
               return APP_ABORT;
       }
       else
       {
               fill_digit_by_coord(alld->eight.digit_hl, tmp_digit_coords, HOUR_LEFT, EIGHT_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->eight.digit_hr, tmp_digit_coords, HOUR_RIGHT, EIGHT_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->eight.digit_ml, tmp_digit_coords, MINUTE_LEFT, EIGHT_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->eight.digit_mr, tmp_digit_coords, MINUTE_RIGHT, EIGHT_LENGTH, DIGIT_NORMAL);
                             
       }

       program_status = init_digit(&alld->nine,9);
       if(program_status == APP_ABORT) 
        {
#ifdef DEBUG
               printf("\n%s nine\n", info);
#endif
               return program_status;
       }      
       else
       {
               tmp_digit_coords = fe_load_digit_coords(9, NINE_LENGTH);
       }
       if(!tmp_digit_coords)
       {
               printf("\nCannot load digit nine, abort.\n");
               return APP_ABORT;
       }
       else
       {
               fill_digit_by_coord(alld->nine.digit_hl, tmp_digit_coords, HOUR_LEFT, NINE_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->nine.digit_hr, tmp_digit_coords, HOUR_RIGHT, NINE_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->nine.digit_ml, tmp_digit_coords, MINUTE_LEFT, NINE_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->nine.digit_mr, tmp_digit_coords, MINUTE_RIGHT, NINE_LENGTH, DIGIT_NORMAL);
                             
       }
       
       program_status = init_digit(&alld->zero,0); 
       if(program_status == APP_ABORT) 
       {
#ifdef DEBUG
               printf("\n%s zero\n", info);
#endif
               return program_status;
       }
       else
       {
               tmp_digit_coords = fe_load_digit_coords(0, ZERO_LENGTH);
       }
       if(!tmp_digit_coords)
       {
               printf("\nCannot load digit zero, abort.\n");
               return APP_ABORT;
       }
       else
       {
               fill_digit_by_coord(alld->zero.digit_hl, tmp_digit_coords, HOUR_LEFT, ZERO_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->zero.digit_hr, tmp_digit_coords, HOUR_RIGHT, ZERO_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->zero.digit_ml, tmp_digit_coords, MINUTE_LEFT, ZERO_LENGTH, DIGIT_NORMAL);
               fill_digit_by_coord(alld->zero.digit_mr, tmp_digit_coords, MINUTE_RIGHT, ZERO_LENGTH, DIGIT_NORMAL);
                             
       }
       return APP_OK;

}

program_status_t init_digit(digit_t* digit, int nomber)
{
        switch(nomber)
        {
                case 1:
                        {
                                digit->digit_hl = malloc(sizeof(box_t) * ONE_LENGTH);
                                digit->digit_hr = malloc(sizeof(box_t) * ONE_LENGTH);
                                digit->digit_ml = malloc(sizeof(box_t) * ONE_LENGTH);
                                digit->digit_mr = malloc(sizeof(box_t) * ONE_LENGTH);
                                if( (digit->digit_hl==NULL)||(digit->digit_hr==NULL)||(digit->digit_ml==NULL)||(digit->digit_mr==NULL)) return APP_ABORT;
                                else return APP_OK;
                        }
                case 2:
                        {
                                digit->digit_hl = malloc(sizeof(box_t) * TWO_LENGTH);
                                digit->digit_hr = malloc(sizeof(box_t) * TWO_LENGTH);
                                digit->digit_ml = malloc(sizeof(box_t) * TWO_LENGTH);
                                digit->digit_mr = malloc(sizeof(box_t) * TWO_LENGTH);
                                if( (digit->digit_hl==NULL)||(digit->digit_hr==NULL)||(digit->digit_ml==NULL)||(digit->digit_mr==NULL)) return APP_ABORT;
                                else return APP_OK;

                        }
                case 3:
                        {
                                digit->digit_hl = malloc(sizeof(box_t) * THREE_LENGTH);
                                digit->digit_hr = malloc(sizeof(box_t) * THREE_LENGTH);
                                digit->digit_ml = malloc(sizeof(box_t) * THREE_LENGTH);
                                digit->digit_mr = malloc(sizeof(box_t) * THREE_LENGTH);
                                if( (digit->digit_hl==NULL)||(digit->digit_hr==NULL)||(digit->digit_ml==NULL)||(digit->digit_mr==NULL)) return APP_ABORT;
                                else return APP_OK;

                        }
                case 4:
                        {
                                digit->digit_hl = malloc(sizeof(box_t) * FOUR_LENGTH);
                                digit->digit_hr = malloc(sizeof(box_t) * FOUR_LENGTH);
                                digit->digit_ml = malloc(sizeof(box_t) * FOUR_LENGTH);
                                digit->digit_mr = malloc(sizeof(box_t) * FOUR_LENGTH);
                                if( (digit->digit_hl==NULL)||(digit->digit_hr==NULL)||(digit->digit_ml==NULL)||(digit->digit_mr==NULL)) return APP_ABORT;
                                else return APP_OK;

                        }
                case 5:
                        {
                                digit->digit_hl = malloc(sizeof(box_t) * FIVE_LENGTH);
                                digit->digit_hr = malloc(sizeof(box_t) * FIVE_LENGTH);
                                digit->digit_ml = malloc(sizeof(box_t) * FIVE_LENGTH);
                                digit->digit_mr = malloc(sizeof(box_t) * FIVE_LENGTH);
                                if( (digit->digit_hl==NULL)||(digit->digit_hr==NULL)||(digit->digit_ml==NULL)||(digit->digit_mr==NULL)) return APP_ABORT;
                                else return APP_OK;

                        }
                case 6:
                        {
                                digit->digit_hl = malloc(sizeof(box_t) * SIX_LENGTH);
                                digit->digit_hr = malloc(sizeof(box_t) * SIX_LENGTH);
                                digit->digit_ml = malloc(sizeof(box_t) * SIX_LENGTH);
                                digit->digit_mr = malloc(sizeof(box_t) * SIX_LENGTH);
                                if( (digit->digit_hl==NULL)||(digit->digit_hr==NULL)||(digit->digit_ml==NULL)||(digit->digit_mr==NULL)) return APP_ABORT;
                                else return APP_OK;

                        }
                case 7:
                        {
                                digit->digit_hl = malloc(sizeof(box_t) * SEVEN_LENGTH);
                                digit->digit_hr = malloc(sizeof(box_t) * SEVEN_LENGTH);
                                digit->digit_ml = malloc(sizeof(box_t) * SEVEN_LENGTH);
                                digit->digit_mr = malloc(sizeof(box_t) * SEVEN_LENGTH);
                                if( (digit->digit_hl==NULL)||(digit->digit_hr==NULL)||(digit->digit_ml==NULL)||(digit->digit_mr==NULL)) return APP_ABORT;
                                else return APP_OK;

                        }
                case 8:
                        {
                                digit->digit_hl = malloc(sizeof(box_t) * EIGHT_LENGTH);
                                digit->digit_hr = malloc(sizeof(box_t) * EIGHT_LENGTH);
                                digit->digit_ml = malloc(sizeof(box_t) * EIGHT_LENGTH);
                                digit->digit_mr = malloc(sizeof(box_t) * EIGHT_LENGTH);
                                if( (digit->digit_hl==NULL)||(digit->digit_hr==NULL)||(digit->digit_ml==NULL)||(digit->digit_mr==NULL)) return APP_ABORT;
                                else return APP_OK;

                        }
                case 9:
                        {
                                digit->digit_hl = malloc(sizeof(box_t) * NINE_LENGTH);
                                digit->digit_hr = malloc(sizeof(box_t) * NINE_LENGTH);
                                digit->digit_ml = malloc(sizeof(box_t) * NINE_LENGTH);
                                digit->digit_mr = malloc(sizeof(box_t) * NINE_LENGTH);
                                if( (digit->digit_hl==NULL)||(digit->digit_hr==NULL)||(digit->digit_ml==NULL)||(digit->digit_mr==NULL)) return APP_ABORT;
                                else return APP_OK;

                        }
                case 0:
                        {
                                digit->digit_hl = malloc(sizeof(box_t) * ZERO_LENGTH);
                                digit->digit_hr = malloc(sizeof(box_t) * ZERO_LENGTH);
                                digit->digit_ml = malloc(sizeof(box_t) * ZERO_LENGTH);
                                digit->digit_mr = malloc(sizeof(box_t) * ZERO_LENGTH);
                                if( (digit->digit_hl==NULL)||(digit->digit_hr==NULL)||(digit->digit_ml==NULL)||(digit->digit_mr==NULL)) return APP_ABORT;
                                else return APP_OK;

                        }
                default:{}
                        return APP_OK;

        }

}

void de_free_all_digits(all_digits_t* alld)
{
        de_free_d(&alld->one);
        de_free_d(&alld->two);
        de_free_d(&alld->three);
        de_free_d(&alld->four);
        de_free_d(&alld->five);
        de_free_d(&alld->six);
        de_free_d(&alld->seven);
        de_free_d(&alld->eight);
        de_free_d(&alld->nine);
        de_free_d(&alld->zero);
        
    
}

void de_free_d(digit_t* digit)
{
        free(digit->digit_hl);
        free(digit->digit_hr);
        free(digit->digit_ml);
        free(digit->digit_mr);
}

void de_init_digits_on_screen(digit_t* dos)
{
        dos->digit_hl = NULL;
        dos->digit_hr = NULL;
        dos->digit_ml = NULL;
        dos->digit_mr = NULL;
}


