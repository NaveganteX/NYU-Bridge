#include <iostream>
using namespace std;

int main() {
    int quarters;
    int dimes;
    int nickels;
    int pennies;
    int dollars;
    int cents;
    int total;

    cout<<"Please enter number of coins"<<endl;

    cout<<"# of quarters: "<<endl;
    cin>>quarters;
    quarters *= 25;

    cout<<"# of dimes:"<<endl;
    cin>>dimes;
    dimes *= 10;

    cout<<"# of nickels:"<<endl;
    cin>>nickels;
    nickels *= 5;

    cout<<"# of pennies:"<<endl;
    cin>>pennies;

    total = quarters + dimes + nickels + pennies;

    dollars = total / 100;
    cents = total % 100;

    cout<<"The total is "<<dollars<<" dollars and "<<cents<<" cents"<<endl;

    return 0;
}
