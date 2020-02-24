#include <iostream>
#include <string>
using namespace std;

int printMonthCalendar(int numOfDays, int startingDay);
bool isLeapYear(int year);
int printYearCalendar(int year, int startingDay);

int main() {
    int year = 0, first_day = 0;
    cout << "Please enter a year: ";
    cin >> year;

    cout << "Enter the first day of the month (1-Mon, 2-Tues): ";
    cin >> first_day;
    cout << endl;

    printYearCalendar(year, first_day);
    return 0;
}

int printMonthCalendar(int numOfDays, int startingDay) {
    cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun" << endl;

    for (int i = 1; i < startingDay; i++) {
        cout << "\t";
    }

    int dayCount = startingDay;
    for (int i = 1; i <= numOfDays; i++) {
        cout << i << "\t";
        if ((i + startingDay - 1) % 7 == 0) {
            if (i != numOfDays) {
                cout << endl;
            }
        }
        dayCount++;
        if (dayCount == 8) {
            dayCount = 1;
        }
    }

    return dayCount;
}

int printYearCalendar(int year, int startingDay) {
    int days_in_month = 0, offSet = 0;
    string month;

    for (int i = 1; i <= 12; i++) {
        if (i == 1) {
            month = "January";
            days_in_month = 31;
        } else if (i == 2) {
            month = "February";
            if (isLeapYear(year)) {
                days_in_month = 29;
            } else {
                days_in_month = 28;
            }
        } else if (i == 3) {
            month = "March";
            days_in_month = 31;
        } else if (i == 4) {
            month = "April";
            days_in_month = 30;
        } else if (i == 5) {
            month = "May";
            days_in_month = 31;
        } else if (i == 6) {
            month = "June";
            days_in_month = 30;
        } else if (i == 7) {
            month = "July";
            days_in_month = 31;
        } else if (i == 8) {
            month = "August";
            days_in_month = 31;
        } else if (i == 9) {
            month = "September";
            days_in_month = 30;
        } else if (i == 10) {
            month = "October";
            days_in_month = 31;
        } else if (i == 11) {
            month = "November";
            days_in_month = 30;
        } else if (i == 12) {
            month = "December";
            days_in_month = 31;
        }

        cout << month << " " << year << endl;
        if (i == 1) {
            offSet = printMonthCalendar(days_in_month, startingDay);
        } else {
            offSet = printMonthCalendar(days_in_month, offSet);
        }
        cout << endl;
        cout << endl;
    }
    return 0;
}

bool isLeapYear(int year) {
    if ((year % 4) != 0) {
        return false;
    } else if ((year % 100) != 0) {
        return true;
    } else if ((year % 400) != 0) {
        return false;
    }
    return true;
}