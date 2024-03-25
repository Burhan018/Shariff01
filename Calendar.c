#include <stdio.h>

// Function to find the day of the week for a given date
int dayOfWeek(int d, int m, int y) {
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

// Function to print the calendar
void printCalendar(int year, int month) {
    // Array containing number of days in each month
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Check for leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29;
    
    // Print the header
    printf("   ----- Calendar for %d/%d -----\n", month, year);
    printf("   Sun Mon Tue Wed Thu Fri Sat\n");
    
    // Get the day of the week for the first day of the month
    int day = dayOfWeek(1, month, year);
    
    // Print leading spaces
    for (int i = 0; i < day; i++)
        printf("    ");
    
    // Print the days of the month
    for (int i = 1; i <= daysInMonth[month - 1]; i++) {
        printf("%5d", i);
        if (++day > 6) {
            printf("\n");
            day = 0;
        }
    }
    printf("\n");
}

int main() {
    int year, month;
    printf("Enter the year: ");
    scanf("%d", &year);
    printf("Enter the month (1-12): ");
    scanf("%d", &month);

    printCalendar(year, month);

    return 0;
}
