#include <iostream>

int main() {
    int days_John;
    int hours_John;
    int minutes_John;

    int days_Bill;
    int hours_Bill;
    int minutes_Bill;

    int total_days;
    int total_hours;
    int total_minutes;

    std::cout << "Please enter the number of days John has worked" << std::endl;
    std::cin >> days_John;

    std::cout << "Please enter the number of hours John has worked" << std::endl;
    std::cin >> hours_John;

    std::cout << "Please enter the number of minutes John has worked" << std::endl;
    std::cin >> minutes_John;

    std::cout << "Please enter the number of days Bill has worked" << std::endl;
    std::cin >> days_Bill;

    std::cout << "Please enter the number of hours Bill has worked" << std::endl;
    std::cin >> hours_Bill;

    std::cout << "Please enter the number of minutes Bill has worked" << std::endl;
    std::cin >> minutes_Bill;

    total_days = days_John + days_Bill;
    total_hours = hours_John + hours_Bill;
    total_minutes = minutes_John + minutes_Bill;

    total_days += total_hours / 24;

    total_hours = total_hours % 24;

    total_hours += total_minutes / 60;

    total_minutes = total_minutes % 60;

    std::cout << "The total time both of them worked together is: " << total_days << " days, " << total_hours << " hours and " << total_minutes << " minutes.";

    return 0;
}
