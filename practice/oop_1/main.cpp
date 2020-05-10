#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
//    constructor that takes no arguments
//    Date() : day(1), month(1), year(1) {}

//    constructor that takes in three arguments
    Date(int newD, int newM, int newY) : day(newD), month(newM), year(newY) {}

//    if we want to define setMonth outside its class definition,
//    we need to declare function prototype inside
    void setMonth(int newMonth);

//  1. defining setYear member function
    void setYear(int newYear) { this -> year = newYear; }

//  2. defining setDay member function
    void setDay(int newDay) {
        if (newDay >= 1 && newDay <= 31) {
            day = newDay;
        }
    }

    void tomorrow(int currentDay) {
        day += 1;
    }
// if you do not want your data to be changed by the function call,
// make the function a const function. (i.e. all accessor functions should be const-ified)
    int getDay() const { return day; } //const guarantees that we will not modify the object calling getDay
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
    Date aDay(20, 6, 1991);
    aDay.printDate();

    aDay.setDay(13);
    aDay.setMonth(3);
    aDay.setYear(2020);
    aDay.printDate();

//    aDay.tomorrow(aDay.getDay());
//    cout << aDay.getDay() << endl;
    cout << aDay.getDay() + 1;
    aDay.printDate();
    return 0;
}
