#include <iostream>
#include <vector>
using namespace std;

class Money {
private:
    long all_cents;

public:
    explicit Money(long dollars);
    Money();

    double getValue() const;
    void setValue(double amount);
};

class Check {
private:
    Money check_money;
    int check_number;
    double check_amount;
    bool is_cashed;

public:
    Check(int new_check_number, double new_check_amount, bool new_is_cashed)
    :check_number(new_check_number), check_amount(new_check_amount), is_cashed(new_is_cashed) {}

    Money getCheckMoney();
    void recordCheckAmount();
    double getMoneyAmount(Money money_amount);
    double getValue() const;
    bool getCashedStatus() const;
};

double sumCashedChecks(vector<Check>& check_vector);
double sumUncashedChecks(vector<Check>& check_vector);
double sumDeposits(vector<Money>& deposit_vector);
double calculatedBalance(double old_balance, double sum_deposits, double sum_uncashed_checks, double sum_cashed_checks);
double bankAccountBalance(double old_balance, double sum_deposits, double sum_cashed_checks);
double accountBalanceDifference(double bank_balance, double calculated_balance);
void listCashedChecks(vector<Check> cashed_check_vector);
void listUncashedChecks(vector<Check> uncashed_check_vector);

int main() {
    int end, check_number, check_cashed;
    double check_amount, deposit_amount;
    bool end_input, cashed;
    vector<Check> check_vector;
    vector<Money> deposit_vector;

    end = 1;
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
        cout << "Would you like to enter another check? (Yes: 1, No: 0)" << endl;
        cin >> end;
        if (end == 0) {
            end_input = true;
        } else {
            end_input = false;
        }
        cin.ignore();
    }
    double sum_cashed_checks;
    sum_cashed_checks = sumCashedChecks(check_vector);

    double sum_uncashed_checks;
    sum_uncashed_checks = sumUncashedChecks(check_vector);

    end = 1;
    end_input = false;
    while (end_input == false) {
        cout << "Please enter a deposit amount" << endl;
        cin >> deposit_amount;
        cin.ignore();
        deposit_amount *= 100;
        Money input_money(deposit_amount);
        deposit_vector.push_back(input_money);
        cout << "Would you like to enter another deposit amount? (Yes: 1, No: 0)" << endl;
        cin >> end;
        if (end == 0) {
            end_input = true;
        } else {
            end_input = false;
        }
        cin.ignore();
    }
    double sum_deposits;
    sum_deposits = sumDeposits(deposit_vector);

    double old_account_balance;
    cout << "Please enter your old account balance:" << endl;
    cin >> old_account_balance;
    old_account_balance *= 100;
    Money old_balance(old_account_balance);

    cout << endl;
    cout << "Checkbook Summary:" << endl;
    cout << "------------------" << endl;
    cout << "Sum of cashed checks: $" << sum_cashed_checks << endl;
    cout << "Sum of uncashed checks: $" << sum_uncashed_checks << endl;
    cout << "Sum of deposits: $" << sum_deposits << endl;

    double calculated_account_balance;
    calculated_account_balance = calculatedBalance(old_balance.getValue(), sum_deposits, sum_uncashed_checks, sum_cashed_checks);
    cout << "New Calculated Balance: $" << calculated_account_balance << endl;

    double bank_balance;
    bank_balance = bankAccountBalance(old_balance.getValue(), sum_deposits, sum_cashed_checks);
    cout << "Bank Balance: $" << bank_balance << endl;

    double balance_difference;
    balance_difference = accountBalanceDifference(calculated_account_balance, bank_balance);
    cout << "Balance Difference: $" << balance_difference << endl;

    listCashedChecks(check_vector);
    listUncashedChecks(check_vector);

    return 0;
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
void listCashedChecks(vector<Check> cashed_check_vector) {
    cout << "Cashed Checks: ";
    for (int i = 0; i < cashed_check_vector.size(); i++) {
        if (cashed_check_vector[i].getCashedStatus() == true) {
            cout << "$" << cashed_check_vector[i].getValue() << " ";
        }
    }
    cout << endl;
}
void listUncashedChecks(vector<Check> uncashed_check_vector) {
    cout << "Uncashed Checks: ";
    for (int i = 0; i < uncashed_check_vector.size(); i++) {
        if (uncashed_check_vector[i].getCashedStatus() == false) {
            cout << "$" << uncashed_check_vector[i].getValue() << " ";
        }
    }
    cout << endl;
}

Money::Money(long dollars) { all_cents = dollars; }
Money::Money() { all_cents = 0.00; }
double Money::getValue() const {
    double all_cents_double = all_cents * 0.01;
    return all_cents_double;
}
void Money::setValue(double amount) { this->all_cents = amount * 100; }

Money Check::getCheckMoney() { return check_money; }
void Check::recordCheckAmount() { check_money.setValue(this->check_amount); }
double Check::getMoneyAmount(Money money_amount) { return money_amount.getValue(); }
double Check::getValue() const { return check_amount; }
bool Check::getCashedStatus() const { return is_cashed; }
