#include <iostream>

int main() {
    int quarters;
    int dimes;
    int nickels;
    int pennies;
    int dollars;
    int cents;
    int total;

    std::cout << "Please enter number of coins" << std::endl;

    std::cout << "# of quarters: " << std::endl;
    std::cin >> quarters;
    quarters *= 25;

    std::cout << "# of dimes:" << std::endl;
    std::cin >> dimes;
    dimes *= 10;

    std::cout << "# of nickels:" << std::endl;
    std::cin >> nickels;
    nickels *= 5;

    std::cout << "# of pennies:" << std::endl;
    std::cin >> pennies;

    total = quarters + dimes + nickels + pennies;

    dollars = total / 100;
    cents = total % 100;

    std::cout << "The total is " << dollars << " dollars and " << cents << " cents" << std::endl;

    return 0;
}
