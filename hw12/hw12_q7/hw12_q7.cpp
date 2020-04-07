#include <iostream>
#include <cstdlib>
#include <cctype>
#include <vector>
using namespace std;

class Money {
private:
    long all_cents;

public:
    Money(long dollars, int cents);
    explicit Money(long dollars);
    Money();

    friend Money operator +(const Money& amount1, const Money& amount2);
    friend Money operator -(const Money& amount1, const Money& amount2);
    friend Money operator -(const Money& amount);
    friend Money operator ++(const Money& amount);
    friend Money operator --(const Money& amount);
    friend bool operator <(const Money& amount1, Money& amount2);
    friend bool operator >(const Money& amount1, Money& amount2);
    friend bool operator ==(const Money& amount1, const Money& amount2);
    friend istream& operator >>(istream& ins, Money& amount);
    friend ostream& operator <<(ostream& outs, const Money& amount);

    double getValue() const;
    void setValue(double amount);

    void input(istream& ins);
    void output(ostream& outs);
};

class Check {
private:
    int check_number;
    double check_amount;
    bool is_cashed;
    Money check_money;

public:
    Check(int new_check_number, double new_check_amount, bool new_is_cashed)
    :check_number(new_check_number), check_amount(new_check_amount), is_cashed(new_is_cashed) {}

    void record_check_amount() {
        check_money.setValue(this->check_amount);
//        check_money.output(cout);
    };

    void getValue() const {
        cout << this->check_amount << endl;
    }
};

int main() {
    int end, check_number, check_cashed;
    double check_amount;
    bool end_input = false, cashed = true;
    vector<Check> check_vector;

//    Check test(334586, 13.45, true);
//    test.record_check_amount();
    while (end_input == false) {
        cout << "Please enter the check number, check amount and "
                "if check has been cashed or not (Yes: 1, No: 0). \nSeparate each info entry by a space." << endl;
        cin >> check_number >> check_amount >> check_cashed;
        if (check_cashed == 0) {
           cashed == false;
        } else {
            cashed == true;
        }
        cin.ignore();
        Check input(check_number, check_amount, cashed);
        check_vector.push_back(input);
        cout << "Would you like to enter another check? (Yes: 1, No: -1)" << endl;
        cin >> end;
        if (end == -1) {
            end_input = true;
        } else {
            end_input = false;
        }
        cin.ignore();
    }

    for (int i = 0; i < check_vector.size(); i++) {
        check_vector[i].getValue();
    }

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
Money operator ++(const Money& amount) {
    Money temp;
    temp.all_cents = amount.all_cents;
    return ++temp;
}
Money operator --(const Money& amount) {
    Money temp;
    temp.all_cents = amount.all_cents;
    return --temp;
}
Money operator -(const Money& amount) {
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}
bool operator ==(const Money& amount1, const Money& amount2) {
    return amount1.all_cents == amount2.all_cents;
}
bool operator <(const Money& amount1, Money& amount2) {
    return amount1.all_cents < amount2.all_cents;
}
bool operator >(const Money& amount1, Money& amount2) {
    return amount1.all_cents > amount2.all_cents;
}
istream& operator >>(istream& ins, Money& amount) {
    char one_char, decimal_point, digit1, digit2;
    long dollars;
    int cents;
    bool negative;

    ins >> one_char;
    if (one_char == '-') {
        negative = true;
        ins >> one_char;
    } else {
        negative = false;
    }

    ins >> dollars >> decimal_point >> digit1 >> digit2;
    if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2)) {
        cout << "Error, illegal for for money input" << endl;
        exit(1);
    }

    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);

    amount.all_cents = dollars * 100 + cents;
    if (negative) {
        amount.all_cents = -amount.all_cents;
    }
    return ins;
}
ostream& operator <<(ostream& outs, const Money& amount) {
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;

    if (amount.all_cents < 0) {
        outs << "- $" << dollars << '.';
    } else {
        outs << "$" << dollars << '.';
    }

    if (cents < 10) {
        outs << '0';
    }
    outs << cents;

    return outs;
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
        cout << "Error, illegal form for money input" << endl;
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
double Money::getValue() const { return all_cents * 0.01; }
void Money::setValue(double amount) { this->all_cents = amount * 100; }

//    Money your_amount, my_amount(10, 9), out_amount;
//    cout << "Enter an amount of money: ";
//    your_amount.input(cin);
//    cout << "Your amount is ";
//    your_amount.output(cout);
//    cout << endl;
//    cout << "My amount is ";
//    my_amount.output(cout);
//    cout << endl;
//    out_amount = -your_amount;
//    out_amount.output(cout);

//    Money amount[5], max;
//    int i;
//    cout << "Enter 5 amounts of money: " << endl;
//    cin >> amount[0];
//    max = amount[0];
//
//    for (i = 1; i < 5; i++) {
//        cin >> amount[i];
//        if (max < amount[i]) {
//            max = amount[i];
//        }
//    }
//
//    Money difference[5];
//    for (i = 0; i < 5; i++) {
//        difference[i] = max - amount[i];
//    }
//
//    cout << "The highest amount is " << max << endl;
//    cout << "The amounts and their differences from the largest are:" << endl;
//
//    for (i = 0; i < 5; i++) {
//        cout << amount[i] << " off by " << difference[i] << endl;
//    }



