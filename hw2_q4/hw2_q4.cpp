#include <iostream>

int main() {
    int num1, num2;

    std::cout << "Please enter two positive integers, separated by a space:" << std::endl;
    std::cin >> num1 >> num2;

    std::cout << num1 << " + " << num2 << " = " << num1 + num2 << std::endl;
    std::cout << num1 << " - " << num2 << " = " << num1 - num2 << std::endl;
    std::cout << num1 << " * " << num2 << " = " << num1 * num2 << std::endl;
    std::cout << num1 << " / " << num2 << " = " << ((double)num1) / num2 << std::endl;
    std::cout << num1 << " div " << num2 << " = " << num1 / num2 << std::endl;
    std::cout << num1 << " mod " << num2 << " = " << num1 % num2 << std::endl;

    return 0;
}
