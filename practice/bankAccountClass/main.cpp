#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int generate_Account_Number() {
    return (rand() % 100000000) + 1;
}

class BankAccount {
private:
    int bank_Account_Number;
    string account_Owner_Name;
    double balance;

public:
    BankAccount(string starting_Name, double starting_balance)
    : account_Owner_Name(starting_Name), balance(starting_balance), bank_Account_Number(generate_Account_Number()) {}

    string get_Owner_Name();
    void set_Owner_Name(string new_Name);
    double get_Balance();
    void set_Deposit(double deposit_Amount);
    void set_Withdrawal(double withdrawal_Amount);
    int get_Account_Number();
};

int main() {
    srand(time(NULL));
    cout << "Welcome to Hon's House of Guac!" << endl;
    BankAccount bank_Account_Lawrence("Lawrence", 100.94);

    cout << "Account Owner Name: " << bank_Account_Lawrence.get_Owner_Name() << endl;
    cout << "Account Number: " << bank_Account_Lawrence.get_Account_Number() << endl;

    bank_Account_Lawrence.set_Deposit(2300);
    cout << "Account Balance: $" << bank_Account_Lawrence.get_Balance() << endl;

    bank_Account_Lawrence.set_Withdrawal(988.74);

    return 0;
}

string BankAccount::get_Owner_Name() { return account_Owner_Name; }
void BankAccount::set_Owner_Name(string new_Name) { account_Owner_Name = new_Name; }
double BankAccount::get_Balance() { return balance; }
void BankAccount::set_Deposit(double deposit_Amount) { balance += deposit_Amount; }
void BankAccount::set_Withdrawal(double withdrawal_Amount) {
    if (balance < withdrawal_Amount) {
        cout << "Unfortunately you do not have enough in your account." << endl;
        cout << "Current Balance: $" << BankAccount::get_Balance() << endl;
    } else {
        cout << "Withdrawn amount: -$" << withdrawal_Amount << endl;
        balance -= withdrawal_Amount;
        cout << "New Balance: $" << BankAccount::get_Balance() << endl;
    }
}
int BankAccount::get_Account_Number() { return bank_Account_Number; }