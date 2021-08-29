#include "file_engine.h"
#include <stdlib.h>
#include <string.h>

char* get_digit_name(int nomber);





plot_t* fe_load_digit_coords(int nomber, int length)
{
        FILE* file = NULL;
        int read_b;
        plot_t* tmp_coords = NULL;
        char* digit_name = get_digit_name(nomber); /* */
        if( strcmp(digit_name,"fake") == 0)
        {
#ifdef DEBUG
                printf("\ndigit_name = fake in fe_load_digit_coords func.\n");
#endif
                return NULL;
        }
        switch(nomber)
        {
                case 1:
                        {
                                tmp_coords = malloc(sizeof(plot_t[ONE_LENGTH]));
                                break;
                        }
                case 2:
                        {
                                tmp_coords = malloc(sizeof(plot_t[TWO_LENGTH]));
                                break;
                        }
                case 3:
                        {
                                tmp_coords = malloc(sizeof(plot_t[THREE_LENGTH]));
                                break;
                        }
                case 4:
                        {
                                tmp_coords = malloc(sizeof(plot_t[FOUR_LENGTH]));
                                break;
                        }
                case 5:
                        {
                                tmp_coords = malloc(sizeof(plot_t[FIVE_LENGTH]));
                                break;
                        }
                case 6:
                        {
                                tmp_coords = malloc(sizeof(plot_t[SIX_LENGTH]));
                                break;
                        }
                case 7:
                        {
                                tmp_coords = malloc(sizeof(plot_t[SEVEN_LENGTH]));
                                break;
                        }
                case 8:
                        {
                                tmp_coords = malloc(sizeof(plot_t[EIGHT_LENGTH]));
                                break;
                        }
                case 9:
                        {
                                tmp_coords = malloc(sizeof(plot_t[NINE_LENGTH]));
                                break;
                        }
                case 0:
                        {
                                tmp_coords = malloc(sizeof(plot_t[ZERO_LENGTH]));
                                break;
                        }
                default:{}
        }

        if((file = fopen(digit_name, "rb")) == NULL) 
        {
                free(tmp_coords);
#ifdef DEBUG
                printf("\nCannot open file %s in fe_load_digit_coords func.\n", digit_name);
#endif
                return NULL;
        }
        else
        {

                read_b = fread(tmp_coords, sizeof(tmp_coords[0]), length, file);
        }
        if( read_b != length)
        {
#ifdef DEBUG
                printf("\nread_b != length in fe_load_digit_coords func.\n");
#endif
                fclose(file);
                free(tmp_coords);
                return NULL;
        }
        else 
        {
                fclose(file);
                return tmp_coords;
        }
}

char* get_digit_name(int nomber)
{
        switch(nomber)
        {
                case 0:
                        {
                                return "zero";break;
                        }
                case 1:
                        {
                                return "one";break;
                        }
                case 2:
                        {
                                return "two";break;
                        }
                case 3:
                        {
                                return "three"; break;
                        }
                case 4:
                        {
                                return "four"; break;
                        }
                case 5:
                        {
                                return "five"; break;
                        }
                case 6:
                        {
                                return "six"; break;
                        }
                case 7:
                        {
                                return "seven"; break;
                        }
                case 8:
                        {
                                return "eight"; break;
                        }
                case 9:
                        {
                                return "nine"; break;
                        }
                default:
                        {
                                return "fake"; break;
                        }
        }
}



