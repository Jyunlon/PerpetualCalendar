#include "Date.h"
#include "PerpetualCalendar.h"
#include <stdio.h>

static const char *namesOfWeekday[8] = {
	"","一","二","三","四","五","六","天"
};

void PerpetualCalendarPrintMonth(int year, int month) {
	printf("%d-%d\n",year,month);
	for (int i = 1; i < 8; ++i) {
		printf("%s ",namesOfWeekday[i]);
	}
	printf("\n");
	Date start = { year,month,1 };
	int weekday = DateToWeekday(&start);
	for (int i = 0; i < weekday-1; ++i) {
		printf("   ");
	}
	int dayOfMonth = DaysOfMonth(IsLeapYear(year), month);
	for (int i = 1; i <= dayOfMonth;++i) {
		if (i < 10) {
			printf(" %d ", i);
		}
		else {
			printf("%d ", i);
		}
		if ((i + weekday) % 7 == 1) {
			printf("\n");
		}
	}
	printf("\n");
}
