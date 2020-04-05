#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;

class Money {
private:
    long all_cents;

public:
    friend Money operator+(const Money &amount1, const Money &amount2);
    friend Money operator-(const Money &amount1, const Money &amount2);
    friend Money operator-(const Money &amount);
    Money(long dollars, int cents);
    explicit Money(long dollars);
    Money();

    long getMoney() const { return all_cents; }

    void input(istream& ins);
    void output(ostream& outs);
};

int main() {
    Money your_amount, my_amount(10, 9), out_amount;
    cout << "Enter an amount of money: ";
    your_amount.input(cin);
    cout << "Your amount is ";
    your_amount.output(cout);
    cout << endl;
    cout << "My amount is ";
    my_amount.output(cout);
    cout << endl;
    return 0;
}

int digit_to_int(char c) {
    return (static_cast<int>(c) - static_cast<int>('0'));
}

Money operator +(const Money& amount1, const Money& amount2) {
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}
Money operator -(const Money& amount1, const Money& amount2) {
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}
Money operator -(const Money& amount) {
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}
Money::Money(long dollars, int cents) {
    if (dollars * cents < 0) {
        cout << "Illegal values for dollars and cents." << endl;
    } else {
        all_cents = (dollars * 100) + cents;
    }
}
Money::Money(long dollars) {
    all_cents = dollars * 100;
}
Money::Money() { all_cents = 0.00; }

void Money::input(istream& ins) {
    char one_char, decimal_point, digit1, digit2;
    long dollars;
    int cents;
    bool negative;

    ins >> one_char;
    if (one_char == ' ') {
        negative = true;
        ins >> one_char;
    } else {
        negative = false;
    }
    ins >> dollars >> decimal_point >> digit1 >> digit2;
    if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2)) {
        cout << "Error; illegal form form money" << endl;
        exit(1);
    }

    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);
    all_cents = dollars * 100 + cents;

    if (negative) {
        all_cents = -all_cents;
    }
}
void Money::output(ostream& outs) {
    long positive_cents, dollars, cents;
    positive_cents = labs(all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;

    if (all_cents < 0) {
        outs << "-$" << dollars << '.';
    } else {
        outs << "$" << dollars << '.';
    }

    if (cents < 10) {
        outs << '0';
    }

    outs << cents;
}


