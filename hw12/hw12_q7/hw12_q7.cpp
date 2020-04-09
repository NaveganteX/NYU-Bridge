#include <iostream>
#include <cstdlib>
#include <cctype>
#include <vector>
using namespace std;

class Money {
private:
    long all_cents;

public:
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

    void recordCheckAmount() {
        check_money.setValue(this->check_amount);
    };

    Money getCheckMoney() {
        return check_money;
    }
    
    double getMoneyAmount(Money money_amount) {
        return money_amount.getValue();
    }
    double getValue() const {
        return check_amount;
    }

    bool getCashedStatus() const {
        return is_cashed;
    }

};

double sumCashedChecks(vector<Check>& check_vector);
double sumUncashedChecks(vector<Check>& check_vector);
double sumDeposits(vector<Money>& deposit_vector);
double calculatedBalance(double old_balance, double sum_deposits, double sum_uncashed_checks, double sum_cashed_checks);
double bankAccountBalance(double old_balance, double sum_deposits, double sum_cashed_checks);
double accountBalanceDifference(double bank_balance, double calculated_balance);

int main() {
    int end, check_number, check_cashed;
    double check_amount, deposit_amount;
    bool end_input, cashed = true;
    vector<Check> check_vector;
    vector<Money> deposit_vector;

    end_input = false;
    while (end_input == false) {
        cout << "Please enter the check number, check amount and "
                "if check has been cashed or not (Yes: 1, No: 0). \nSeparate each info entry by a space." << endl;
        cin >> check_number >> check_amount >> check_cashed;
        if (check_cashed == 0) {
           cashed = false;
        } else {
            cashed = true;
        }
        cin.ignore();
        Check input_check(check_number, check_amount, cashed);
        check_vector.push_back(input_check);
        cout << "Would you like to enter another check? (Yes: 1, No: -1)" << endl;
        cin >> end;
        if (end == -1) {
            end_input = true;
        } else {
            end_input = false;
        }
        cin.ignore();
    }
    double sum_cashed_checks;
    sum_cashed_checks = sumCashedChecks(check_vector);
    cout << "Sum of cashed checks: $" << sum_cashed_checks << endl;

    double sum_uncashed_checks;
    sum_uncashed_checks = sumUncashedChecks(check_vector);
    cout << "Sum of uncashed checks: $" << sum_uncashed_checks << endl;

    end = 0;
    end_input = false;
    while (end_input == false) {
        cout << "Please enter a deposit amount" << endl;
        cin >> deposit_amount;
        cin.ignore();
        deposit_amount *= 100;
        Money input_money(deposit_amount);
        deposit_vector.push_back(input_money);
        cout << "Would you like to enter another deposit amount? (Yes: 1, No: -1)" << endl;
        cin >> end;
        if (end == -1) {
            end_input = true;
        }
        cin.ignore();
    }
    double sum_deposits;
    sum_deposits = sumDeposits(deposit_vector);
    cout << "Sum of deposits: $" << sum_deposits << endl;

    double old_account_balance;
    cout << "Please enter your old account balance:" << endl;
    cin >> old_account_balance;
    old_account_balance *= 100;
    Money old_balance(old_account_balance);

    double new_account_balance;
    cout << "Please enter what your new account balance should be:" << endl;
    cin >> new_account_balance;
    new_account_balance *= 100;
    Money new_balance(new_account_balance);

    double calculated_account_balance;
    calculated_account_balance = calculatedBalance(old_balance.getValue(), sum_deposits, sum_uncashed_checks, sum_cashed_checks);
    cout << "Calculated Balance: $" << calculated_account_balance << endl;

    double bank_balance;
    bank_balance = bankAccountBalance(old_balance.getValue(), sum_deposits, sum_cashed_checks);
    cout << "Bank Balance: $" << bank_balance << endl;

    double balance_difference;
    balance_difference = accountBalanceDifference(calculated_account_balance, bank_balance);
    cout << "Balance Difference: $" << balance_difference << endl;
    return 0;
}

int digitToInt(char c) {
    return (static_cast<int>(c) - static_cast<int>('0'));
}
double sumCashedChecks(vector<Check>& check_vector) {
    double sum = 0;
    for (int i = 0; i < check_vector.size(); i++) {
        check_vector[i].recordCheckAmount();
        if (check_vector[i].getCashedStatus() == true) {
            sum += check_vector[i].getMoneyAmount(check_vector[i].getCheckMoney());
        }
    }
    return sum;
}
double sumUncashedChecks(vector<Check>& check_vector) {
    double sum = 0;
    for (int i = 0; i < check_vector.size(); i++) {
        check_vector[i].recordCheckAmount();
        if (check_vector[i].getCashedStatus() == false) {
            sum += check_vector[i].getMoneyAmount(check_vector[i].getCheckMoney());
        }
    }
    return sum;
}
double sumDeposits(vector<Money>& deposit_vector) {
    double sum;
    for (int i = 0; i < deposit_vector.size(); i++) {
        sum += deposit_vector[i].getValue();
    }
    return sum;
}
double calculatedBalance(double old_balance, double sum_deposits, double sum_uncashed_checks, double sum_cashed_checks) {
    return old_balance + sum_deposits - (sum_cashed_checks  + sum_uncashed_checks);
}
double bankAccountBalance(double old_balance, double sum_deposits, double sum_cashed_checks) {
    return old_balance + sum_deposits - sum_cashed_checks;
}
double accountBalanceDifference(double bank_balance, double calculated_balance) {
    return calculated_balance - bank_balance;
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

    cents = digitToInt(digit1) * 10 + digitToInt(digit2);

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
Money::Money(long dollars) { all_cents = dollars; }
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

    cents = digitToInt(digit1) * 10 + digitToInt(digit2);
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
double Money::getValue() const {
    double all_cents_double = all_cents * 0.01;
    return all_cents_double;
}
void Money::setValue(double amount) { this->all_cents = amount * 100; }