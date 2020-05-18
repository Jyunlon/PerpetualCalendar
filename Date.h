#pragma once

typedef struct Date {
	int year;
	int month;
	int day;
}Date;

void DatePrint(const Date *date);
void DateSet(Date *date,int year,int month,int day);

int DaysOfMonth(int isLeap, int i);
int IsLeapYear(int year);
int DaysDateFromYearStart(const Date *date);
int DaysYearStartBetweenYearStart(int start, int end);
int DaysDateBetweenDate(const Date *start, const Date *end);
void DateTomorrow(Date *after,const Date *before);
void DateYesterday(Date *after,const Date *before);
void DateAddDays(Date *after, const Date *before, int days);
void DateSubDays(Date *after, const Date *before, int days);
int WeekdayTomorrow(int weekday);
int WeekdayYesterday(int weekday);
int WeekdayAddDays(int weekday, int days);
int WeekdaySubDays(int weekday, int days);
int DateCompare(const Date *A, const Date *B);
int DateToWeekday(const Date *date);
