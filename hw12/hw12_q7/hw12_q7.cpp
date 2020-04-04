#include <iostream>
using namespace std;

class Money {
private:
    long all_cents;

public:
    friend Money operator +(const Money& amount1, const Money& amount2);
    friend Money operator -(const Money& amount1, const Money& amount2);
    friend Money operator -(const Money& amount);
    Money();
};

class Check {
    int check_Num;
    double check_Amount;
    bool cashed_Status;

public:
    Check()
};

int main() {

    return 0;
}

Money operator +(const Money& amount1, const Money& amount2) {
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
};

Money operator -(const Money& amount1, const Money& amount2) {
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
};
Money operator -(const Money& amount) {
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
};

