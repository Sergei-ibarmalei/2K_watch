#include "time_engine.h"
#include <time.h>

typedef struct
{
        long int s_time;
        struct tm* m_time;
} ctime_t;


int te_get_current_sec()
{
        ctime_t ctime;
        ctime.s_time = time(NULL);
        ctime.m_time = localtime(&ctime.s_time);
        return ctime.m_time->tm_sec;
}

void te_get_current_time(times_t* current_time )
{
        int hour;
        int minute;
        int minute_left;
        int minute_right;
        int hour_left;
        int hour_right;
        

        ctime_t ctime;

        ctime.s_time = time(NULL);
        ctime.m_time = localtime(&ctime.s_time);

        minute = ctime.m_time->tm_min;
        if(minute / 10 == 0)
        {
                minute_left = 0;
                minute_right = minute;
        }
        else
        {
                minute_left = minute / 10;
                minute_right = minute % 10;
        }

        hour = ctime.m_time->tm_hour;
        if(hour / 10 == 0)
        {
                hour_left = 0;
                hour_right = hour;
        }
        else
        {
                hour_left = hour / 10;
                hour_right = hour % 10;
        }

        current_time->current_hour_left = hour_left;
        current_time->current_hour_right = hour_right;
        current_time->current_minute_left = minute_left;
        current_time->current_minute_right = minute_right;
}


time_changes_t te_fast_checking_time(times_t* current_time)
/* проверяем изменилась ли минута */
{
        ctime_t ctime;
        int min_;

        ctime.s_time = time(NULL);
        ctime.m_time = localtime(&ctime.s_time);
        min_ = ctime.m_time->tm_min;
        min_ = min_ % 10;

        if(current_time->current_minute_right != min_)
                return TIME_CHANGED;
        else return TIME_THE_SAME;
}

time_changes_t te_fast_checking_time_sec(int cur_sec)
{
        ctime_t ctime;
        ctime.s_time = time(NULL);
        ctime.m_time = localtime(&ctime.s_time);
        if( cur_sec != ctime.m_time->tm_sec)
                return TIME_CHANGED;
        else return TIME_THE_SAME;
}




void te_show_time_in_console(times_t* ct)
{
        printf("\n[%d  %d:%d  %d]\n",ct->current_hour_left,ct->current_hour_right,ct->current_minute_left,ct->current_minute_right);
}

void te_fill_work_digits_by_time(digit_t* digits,all_digits_t* alld,  times_t* cur_time, digit_lengths_t* dl)
{
        switch(cur_time->current_hour_right)
        {
                case 0:
                        {
                                digits->digit_hr = alld->zero.digit_hr;
                                dl->length_hr = ZERO_LENGTH; break;
                        }
                case 1:
                        {
                                digits->digit_hr = alld->one.digit_hr;
                                dl->length_hr = ONE_LENGTH;break;
                        }
                case 2:
                        {
                                digits->digit_hr = alld->two.digit_hr;
                                dl->length_hr = TWO_LENGTH;break;
                        }
                case 3:
                        {
                                digits->digit_hr = alld->three.digit_hr;
                                dl->length_hr = THREE_LENGTH;break;
                        }
                case 4:
                        {
                                digits->digit_hr = alld->four.digit_hr;
                                dl->length_hr = FOUR_LENGTH;break;
                        }
                case 5:
                        {
                                digits->digit_hr = alld->five.digit_hr;
                                dl->length_hr = FIVE_LENGTH;break;
                        }
                case 6:
                        {
                                digits->digit_hr = alld->six.digit_hr;
                                dl->length_hr = SIX_LENGTH;break;
                        }
                case 7:
                        {
                                digits->digit_hr = alld->seven.digit_hr;
                                dl->length_hr = SEVEN_LENGTH;break;
                        }
                case 8:
                        {
                                digits->digit_hr = alld->eight.digit_hr;
                                dl->length_hr = EIGHT_LENGTH;break;
                        }
                case 9:
                        {
                                digits->digit_hr = alld->nine.digit_hr;
                                dl->length_hr = NINE_LENGTH;break;
                        }
                default: {}
        }

        switch(cur_time->current_hour_left)
        {
                case 0:
                        {
                                digits->digit_hl = alld->zero.digit_hl;
                                dl->length_hl = ZERO_LENGTH;break;
                        }
                case 1:
                        {
                                digits->digit_hl = alld->one.digit_hl;
                                dl->length_hl = ONE_LENGTH;break;
                        }
                case 2:
                        {
                                digits->digit_hl = alld->two.digit_hl;
                                dl->length_hl = TWO_LENGTH;break;
                        }
                case 3:
                        {
                                digits->digit_hl = alld->three.digit_hl;
                                dl->length_hl = THREE_LENGTH;break;
                        }
                case 4:
                        {
                                digits->digit_hl = alld->four.digit_hl;
                                dl->length_hl = FOUR_LENGTH;break;
                        }
                case 5:
                        {
                                digits->digit_hl = alld->five.digit_hl;
                                dl->length_hl = FIVE_LENGTH;break;
                        }
                case 6:
                        {
                                digits->digit_hl = alld->six.digit_hl;
                                dl->length_hl = SIX_LENGTH;break;
                        }
                case 7:
                        {
                                digits->digit_hl = alld->seven.digit_hl;
                                dl->length_hl = SEVEN_LENGTH;break;
                        }
                case 8:
                        {
                                digits->digit_hl = alld->eight.digit_hl;
                                dl->length_hl = EIGHT_LENGTH;break;
                        }
                case 9:
                        {
                                digits->digit_hl = alld->nine.digit_hl;
                                dl->length_hl = NINE_LENGTH;break;
                        }
                default: {}
        }

        switch(cur_time->current_minute_right)
        {
                case 0:
                        {
                                digits->digit_mr = alld->zero.digit_mr;
                                dl->length_mr = ZERO_LENGTH;break;
                        }
                case 1:
                        {
                                digits->digit_mr = alld->one.digit_mr;
                                dl->length_mr = ONE_LENGTH;break;
                        }
                case 2:
                        {
                                digits->digit_mr = alld->two.digit_mr;
                                dl->length_mr = TWO_LENGTH;break;
                        }
                case 3:
                        {
                                digits->digit_mr = alld->three.digit_mr;
                                dl->length_mr = THREE_LENGTH;break;
                        }
                case 4:
                        {
                                digits->digit_mr = alld->four.digit_mr;
                                dl->length_mr = FOUR_LENGTH;break;
                        }
                case 5:
                        {
                                digits->digit_mr = alld->five.digit_mr;
                                dl->length_mr = FIVE_LENGTH;break;
                        }
                case 6:
                        {
                                digits->digit_mr = alld->six.digit_mr;
                                dl->length_mr = SIX_LENGTH;break;
                        }
                case 7:
                        {
                                digits->digit_mr = alld->seven.digit_mr;
                                dl->length_mr = SEVEN_LENGTH;break;
                        }
                case 8:
                        {
                                digits->digit_mr = alld->eight.digit_mr;
                                dl->length_mr = EIGHT_LENGTH;break;
                        }
                case 9:
                        {
                                digits->digit_mr = alld->nine.digit_mr;
                                dl->length_mr = NINE_LENGTH;break;
                        }
                default: {}
        }

        switch(cur_time->current_minute_left)
        {
                case 0:
                        {
                                digits->digit_ml = alld->zero.digit_ml;
                                dl->length_ml = ZERO_LENGTH;break;
                        }
                case 1:
                        {
                                digits->digit_ml = alld->one.digit_ml;
                                dl->length_ml = ONE_LENGTH;break;
                        }
                case 2:
                        {
                                digits->digit_ml = alld->two.digit_ml;
                                dl->length_ml = TWO_LENGTH;break;
                        }
                case 3:
                        {
                                digits->digit_ml = alld->three.digit_ml;
                                dl->length_ml = THREE_LENGTH;break;
                        }
                case 4:
                        {
                                digits->digit_ml = alld->four.digit_ml;
                                dl->length_ml = FOUR_LENGTH;break;
                        }
                case 5:
                        {
                                digits->digit_ml = alld->five.digit_ml;
                                dl->length_ml = FIVE_LENGTH;break;
                        }
                case 6:
                        {
                                digits->digit_ml = alld->six.digit_ml;
                                dl->length_ml = SIX_LENGTH;break;
                        }
                case 7:
                        {
                                digits->digit_ml = alld->seven.digit_ml;
                                dl->length_ml = SEVEN_LENGTH;break;
                        }
                case 8:
                        {
                                digits->digit_ml = alld->eight.digit_ml;
                                dl->length_ml = EIGHT_LENGTH;break;
                        }
                case 9:
                        {
                                digits->digit_ml = alld->nine.digit_ml;
                                dl->length_ml = NINE_LENGTH;break;
                        }
                default:{}
        }

}
