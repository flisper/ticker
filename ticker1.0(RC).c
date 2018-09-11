#include <stdio.h>
int clock_calc(int, int);
void clock_output(int, int, int);

int main()
{
    int present_time, alarm_time;
    printf("ENTER PRESENT TIME: ");
    scanf("%d", &present_time);
    printf("\nENTER ALARM TIME: ");
    scanf("%d", &alarm_time);
    if (clock_calc(present_time,alarm_time)==1)
    {
        sleep(1);
        printf("\nALARM!!");
        return 0;
    }
}

int clock_calc(int present, int alarm)
{
    int present_h=present/10000, present_m=(present/100)%100, present_s=present%100;
    
    int alarm_h=alarm/10000, alarm_m=(alarm/100)%100, alarm_s=alarm%100;
    
    while (present_h!=alarm_h||present_m!=alarm_m||present_s!=alarm_s)   
    {
        if (present_s<=59)
        {
            clock_output(present_h, present_m, present_s);
            sleep(1);
            present_s=present_s+1;
        }
        if (present_h==23&&present_m==59&&present_s==60)
        {
            present_h=0;
            present_m=0;
            present_s=0;
        }
        if (present_s==60)
        {
            present_s=0;
            present_m=present_m+1;
        }
        if (present_m==60)
        {
            present_m=0;
            present_s=0;
            present_h=present_h+1;
        }
    }
    return 1;
}

void clock_output(hour, min, sec)
{
    if (hour<10)
    {
        printf("\n0%d:", hour);
    }
    else
    {
        printf("\n%d:", hour);
    }
    if (min<10)
    {
        printf("0%d:", min);
    }
    else 
    {
        printf("%d:",min);
    }
    if (sec<10)
    {
        printf("0%d", sec);
    }
    else
    {
        printf("%d", sec);
    }
}
