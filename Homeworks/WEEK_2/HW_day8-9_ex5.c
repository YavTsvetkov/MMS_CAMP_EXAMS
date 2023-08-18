#include <stdio.h>
#include <stdint.h>
#include <time.h>

typedef struct time{
    unsigned int month : 5;
    unsigned int day : 5; 
    unsigned int hours : 5;
    unsigned int minutes : 6;
    unsigned int seconds : 6;
    unsigned int year : 12; 
} MyTime;

int isLeapYear(MyTime t);
int totalDaysInYear(MyTime t);
void printMonth(MyTime t);
int secondsPassed(MyTime t);

int main(void)
{
    printf("Size of MyTime : %lu\n", sizeof(MyTime));

    MyTime t1 = {2, 14, 12, 30, 15, 2023};

    int totalDays = totalDaysInYear(t1);
    int totalSeconds = secondsPassed(t1);

    printf("Total days in year %d: %d\n", t1.year, totalDays);
    printf("Total seconds passed since January 1st, 1970: %d\n", totalSeconds);

    printf("Month: ");
    printMonth(t1);
    printf("\n");

    return 0;
}

int isLeapYear(MyTime t) {
    unsigned int year = t.year;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int totalDaysInYear(MyTime t)
{
    if (isLeapYear(t)){
        return 366;
    }
    else{
        return 365;
    }
}

int secondsPassed(MyTime t) {
    int seconds_per_year = 365 * 24 * 60 * 60; // non-leap years
    int seconds_passed = 0;

    for (unsigned int year = 1970; year < t.year; year++) {

        if(isLeapYear(t))
        {
            seconds_passed += seconds_per_year + 24 * 60 * 60;
        }
    }

    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(t)) {
        days_in_month[2] = 29;
    }

    for (unsigned int month = 1; month < t.month; month++) {
        seconds_passed += days_in_month[month] * 24 * 60 * 60;
    }

    seconds_passed += (t.day - 1) * 24 * 60 * 60;
    seconds_passed += t.hours * 60 * 60;
    seconds_passed += t.minutes * 60;
    seconds_passed += t.seconds;

    return seconds_passed;
}

void printMonth(MyTime t)
{
    unsigned int month = t.month;

    switch (month)
    {
    case 1:
        printf("January");
        break;
    case 2:
        printf("February");
        break;
    case 3:
        printf("March");
        break;
    case 4:
        printf("April");
        break;
    case 5:
        printf("May");
        break;
    case 6:
        printf("June");
        break;
    case 7:
        printf("July");
        break;
    case 8:
        printf("August");
        break;
    case 9:
        printf("September");
        break;
    case 10:
        printf("October");
        break;    
    case 11:
        printf("November");
        break;
    case 12:
        printf("December");
        break;
    }
}