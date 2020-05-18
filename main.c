#include <stdio.h>
#include "Date.h"
#include "PerpetualCalendar.h"

int main() {

	/*Date dateA, dateB;
	DateSet(&dateA, 2020, 1, 1);
	//DateYesterday(&dateB, &dateA);
	DateAddDays(&dateB, &dateA, 138);
	DatePrint(&dateB);
	*/
	/*Date dateA, dateB;
	DateSet(&dateA, 2018, 8, 7);
	DateSubDays(&dateB, &dateA,1000);
	DatePrint(&dateB);*/
	/*Date dateA, dateB;
	DateSet(&dateA, 2000, 1, 1);
	printf("%d\n",DateToWeekday(&dateA));
	DateSet(&dateA, 2001, 1, 1);
	printf("%d\n", DateToWeekday(&dateA));
	DateSet(&dateA, 1999, 1, 1);
	printf("%d\n", DateToWeekday(&dateA));*/
  
	for (int i = 1; i <= 12; ++i) {
		PerpetualCalendarPrintMonth(2020, i);
	}

	return 0;
}
