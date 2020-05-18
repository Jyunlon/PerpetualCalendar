#include "Date.h"
#include <stdio.h>

static int daysOfMonth[2][13] = {
	{12,
	31,28,31,30,31,30,31,31,30,31,30,31},
	{12,
	31,29,31,30,31,30,31,31,30,31,30,31}
};

void DatePrint(const Date *date) {
	printf("%d-%d-%d\n", date->year, date->month, date->day);
}

void DateSet(Date *date,int year,int month,int day) {
	date->year = year; date->month = month; date->day = day;
}

int DaysOfMonth(int isLeap, int i) {
	return daysOfMonth[isLeap][i];
}

int IsLeapYear(int year) {
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int DaysDateFromYearStart(const Date *date) {
	int days = 0;
	int isLeap = IsLeapYear(date->year);
	for (int i = 1; i < date->month;++i) {
		days += daysOfMonth[isLeap][i];
	}
	days += date->day;
	return days;
}

int DaysYearStartBetweenYearStart(int start, int end) {
	int days = 0; int isLeap = 0;
	for (int i = start; i < end; ++i) {
		isLeap = IsLeapYear(i);
		days += (isLeap == 0 ? 365 : 366);
	}
	return days;
}

int DaysDateBetweenDate(const Date *start, const Date *end) {
	int days = 0;
	days += DaysDateFromYearStart(end);
	days += DaysYearStartBetweenYearStart(start->year, end->year);
	days -= DaysDateFromYearStart(start);
	return days;
}
void DateTomorrow(Date *after, const Date *before) {
	after->day = before->day + 1;
	int isLeap = IsLeapYear(before->year);
	int dayOfMonth = daysOfMonth[isLeap][before->month];
	if (after->day > dayOfMonth) {
		after->day = 1;
		after->month = before->month + 1;
		if (after->month > 12) {
			after->month = 1;
			after->year = before->year + 1;
		}
		else {
			after->year = before->year;
		}
	}
	else {
		after->month = before->month; after->year = before->year;
	}
}
void DateYesterday(Date *after, const Date *before) {
	after->day = before->day - 1;
	if (after->day < 1) {
		after->month = before->month - 1;
		if (after->month < 1) {
			after->month = 12;
			after->year = before->year - 1;
		}
		else {
			after->year = before->year;
		}
		int isLeap = IsLeapYear(after->year);
		int dayOfMonth = daysOfMonth[isLeap][after->month];
		after->day = dayOfMonth;
	}
	else {
		after->month = before->month; after->year = before->year;
	}
}
void DateAddDays(Date *after, const Date *before, int days){
	DateSet(after, before->year, before->month, before->day);
	for (int i = 0; i < days; ++i) {
		DateTomorrow(after, after);
	}
}
void DateSubDays(Date *after, const Date *before, int days) {
	DateSet(after, before->year, before->month, before->day);
	for (int i = 0; i < days; ++i) {
		DateYesterday(after, after);
	}
}
int WeekdayTomorrow(int weekday) {
	weekday += 1;
	if (weekday > 7) {
		weekday = 1;
	}
	return weekday;
}
int WeekdayYesterday(int weekday) {
	weekday -= 1;
	if (weekday < 1) {
		weekday = 7;
	}
	return weekday;
}
int WeekdayAddDays(int weekday, int days) {
	int r = weekday;
	for (int i = 0; i < days; ++i) {
		r = WeekdayTomorrow(r);
	}
	return r;
}
int WeekdaySubDays(int weekday, int days) {
	int r = weekday;
	for (int i = 0; i < days; ++i) {
		r = WeekdayYesterday(r);
	}
	return r;
}
int DateCompare(const Date *A, const Date *B) {
	if (A->year > B->year) {
		return 1;
	}
	else if (A->year < B->year) {
		return -1;
	}
	else {
		if (A->month > B->month) {
			return 1;
		}
		else if (A->month < B->month) {
			return -1;
		}
		else {
			if (A->day > B->day) {
				return 1;
			}
			else if (A->day < B->day) {
				return -1;
			}
			else {
				return 0;
			}
		}
	}
}
int DateToWeekday(const Date *date) {
	Date start = { 2000,1,1 };
	int compare = DateCompare(&start, date);
	if (compare == 0) {
		return 6;
	}
	else if (compare < 0) {
		int days = DaysDateBetweenDate(&start, date);
		int remain = days % 7;
		return WeekdayAddDays(6, remain);
	}
	else {
		int days = DaysDateBetweenDate(date, &start);
		int remain = days % 7;
		return WeekdaySubDays(6, remain);
	}
}
