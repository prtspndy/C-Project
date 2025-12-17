//Pritesh Pandya 
//First project in C language
//Program to print a calender for a Year 2025
//Improve code formatting and comments
//Changes Date 17/12/2025
#include <stdio.h>
/*
 * Function: isLeapYear
 * --------------------
 * Checks whether the given year is a leap year or not.
 * A year is leap year if:
 * - It is divisible by 4 and not divisible by 100
 * - OR it is divisible by 400
 *
 * return: 1 if leap year, 0 otherwise
 */
int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    }
    return 0;
}

/*
 * Function: getDaysInMonth
 * -----------------------
 * Returns the number of days in a given month.
 * For February, it checks whether the year is a leap year.
 *
 * month: month number (1 to 12)
 * year : current year
 *
 * returns: number of days in the month
 */
int getDaysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0; // Invalid month
    }
}

/*
 * Function: printMonth
 * -------------------
 * Prints the calendar of a specific month.
 *
 * month     : month number (1 to 12)
 * year      : current year
 * startDay : pointer to the day on which the month starts
 *            (0 = Sunday, 1 = Monday, ..., 6 = Saturday)
 *
 * The function also updates startDay for the next month.
 */
void printMonth(int month, int year, int* startDay) {
    // Month name array
    const char* months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    // Print month header
    printf("\n---------- %s %d ----------\n", months[month - 1], year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    // Print intital spaces before the first day
    for (int i = 0; i < *startDay; i++) {
        printf("    ");
    }
    // Get total days in the current month
    int days = getDaysInMonth(month, year);
    // Print all days of the month
    for (int day = 1; day <= days; day++) {
        printf("%3d ", day); 
        // Move to next line after Saturday
        if ((*startDay + day) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
    // Update startday for the next month
    *startDay = (*startDay + days) % 7;
}

int main() {
    // Year for which calender will be printed
    int year = 2025;

    // Starting day of the year (0=Sunday)
    // 1 January 2025 starts on Wednesday so value = 3
    int startDay = 3;
    printf("Calendar for the Year %d\n", year);
    // Loop through all 12 months
    for (int month = 1; month <= 12; month++) {
        printMonth(month, year, &startDay);
    }
   return 0;
}
// Small Project complete

