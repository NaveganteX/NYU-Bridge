#include <iostream>
using namespace std;

int printMonthCalendar(int numOfDays, int startingDay);
bool isLeapYear(int year);
int printYearCalendar(int year, int startingDay);

int main() {
//    call printYearCalendar: ask what year and what the first day of that year is
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

    for (int i = 1; i <= numOfDays; i++) {
        cout << i << "\t";
        if ((i + startingDay - 1) % 7 == 0) {
            cout << endl;
        }
    }

    return 0;
}

int printYearCalendar(int year, int startingDay) {
    int days_in_month = 0;
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

//        switch (i) {
//            case 1:
//                month = "January";
//                days_in_month = 31;
//                break;
//            case 2:
//                month = "February";
//                if (isLeapYear(year)) {
//                    days_in_month = 29;
//                } else {
//                    days_in_month = 28;
//                }
//                break;
//            case 3:
//                month = "March";
//                days_in_month = 31;
//                break;
//            case 4:
//                month = "April";
//                days_in_month = 30;
//                break;
//            case 5:
//                month = "May";
//                days_in_month = 31;
//                break;
//            case 6:
//                month = "June";
//                days_in_month = 30;
//                break;
//            case 7:
//                month = "July";
//                days_in_month = 31;
//                break;
//            case 8:
//                month = "August";
//                days_in_month = 31;
//                break;
//            case 9:
//                month = "September";
//                days_in_month = 30;
//                break;
//            case 10:
//                month = "October";
//                days_in_month = 31;
//                break;
//            case 11:
//                month = "November";
//                days_in_month = 30;
//                break;
//            case 12:
//                month = "December";
//                days_in_month = 31;
//                break;
//            default:
//                cout << endl;
//                break;
//        }

        cout << month << " " << year << endl;
        printMonthCalendar(days_in_month, startingDay);
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


