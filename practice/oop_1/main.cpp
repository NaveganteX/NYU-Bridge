#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
//    constructor
    Date() :day(1), month(1), year(1) {}
//    if we want to define setMonth outside its class definition,
//    we need to declare function prototype inside
    void setMonth(int newMonth);

//  1. defining setYear member function
    void setYear(int newYear) { year = newYear; }

//  2. defining setDay member function
    void setDay(int newDay) {
        if (newDay >= 1 && newDay <= 31) {
            day = newDay;
        }
    }
// if you do not want your data to be changed by the function call,
// make the function a const function. (i.e. all accessor functions should be const-ified)
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    void printDate() const;

};

//  3. defining setMonth member function outside class def
void Date::setMonth(int newMonth) {
    if (newMonth >= 1 && newMonth <= 12) {
        month = newMonth;
    }
}

void Date::printDate() const {
    cout << day << "/" << month << "/" << year << endl;
}

int main() {
    Date aDay{};

    aDay.setDay(13);
    aDay.setMonth(3);
    aDay.setYear(2020);

    aDay.printDate();
    return 0;
}
