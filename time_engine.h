#ifndef TIME_ENGINE_H
#define TIME_ENGINE_H

#include "alltype.h"

void te_get_current_time(times_t* current_time);
void te_fill_work_digits_by_time(digit_t* digits,all_digits_t* alld,  times_t* cur_time, digit_lengths_t* dl);
void te_show_time_in_console(times_t* ct);
time_changes_t te_fast_checking_time(times_t* current_time);
time_changes_t te_fast_checking_time_sec(int cur_sec);

int te_get_current_sec();


#endif
