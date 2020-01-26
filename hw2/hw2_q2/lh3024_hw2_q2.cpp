#include <iostream>
using namespace std;

int main() {
    int dollars;
    int cents;
    int quarters;
    int dimes;
    int nickels;

    cout<<"Please enter your amount in the format of dollars and cents separated by a space:"<<endl;
    cin>>dollars>>cents;

    quarters = (dollars * 4) + (cents / 25);
    cents %= 25;

    dimes = cents / 10;
    cents %= 10;

    nickels = cents / 5;
    cents %= 5;

    cout<<dollars<<" dollars and "<<cents<<" cents are: "<<endl;
    cout<<quarters<<" quarters, "<<dimes<<" dimes, "<<nickels<<" nickels, and "<<cents<<" pennies"<<endl;

    return 0;
}