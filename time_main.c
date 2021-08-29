/*
 * программа отсчитывает одну секунду и выводит сообщение на экран
 *
 */


#include <stdio.h>
#include <time.h>

static int sec_f;
static int sec_l;

int main(int argc, char** argv)
{
        long int s_time;
        struct tm* m_time;


        s_time = time(NULL);
        m_time = localtime(&s_time);
        sec_f = m_time->tm_sec;
        printf("sec: %d\n", sec_f);
        for(;;)
        {
                s_time = time(NULL);
                m_time = localtime(&s_time);
                sec_l = m_time->tm_sec;
                if(sec_l != sec_f)
                {
                        printf("One second pass\n");
                        s_time = time(NULL);
                        m_time = localtime(&s_time);
                        sec_f = m_time->tm_sec;
                }
        }
        /*printf("day: %d\n", m_time->tm_mday);*/
        

        return 0;
}


