#include <iostream>

int main() {
    int dollars;
    int cents;
    int quarters;
    int dimes;
    int nickels;

    std::cout << "Please enter your amount in the format of dollars and cents separated by a space:" << std::endl;
    std::cin >> dollars >> cents;

    quarters = (dollars * 4) + (cents / 25);
    cents %= 25;

    dimes = cents / 10;
    cents %= 10;

    nickels = cents / 5;
    cents %= 5;

    std::cout << dollars << " dollars and " << cents << " cents are: " << std::endl;
    std::cout << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, and " << cents << " pennies" << std::endl;

    return 0;
}