#ifndef DIGIT_ENGINE_H
#define DEGIT_ENGINE_H
#include "alltype.h"
#include "file_engine.h"
#include "color_engine.h"
#include "maintype.h"

program_status_t de_init_all_digits(all_digits_t* alld);
void de_init_digits_on_screen(digit_t* dos);
program_status_t de_init_back_digits(digit_t* bd);
void de_free_back_digits(back_digit_t* bd);
void de_free_all_digits(all_digits_t* alld);
void de_free_d(digit_t* digit);
program_status_t de_init_all_digits(all_digits_t* alld);


#endif
