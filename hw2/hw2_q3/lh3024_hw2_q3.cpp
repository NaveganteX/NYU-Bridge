#include <iostream>
using namespace std;

int main() {
    int days_John;
    int hours_John;
    int minutes_John;

    int days_Bill;
    int hours_Bill;
    int minutes_Bill;

    int total_days;
    int total_hours;
    int total_minutes;

    cout<<"Please enter the number of days John has worked"<<endl;
    cin>>days_John;

    cout<<"Please enter the number of hours John has worked"<<endl;
    cin>>hours_John;

    cout<<"Please enter the number of minutes John has worked"<<endl;
    cin>>minutes_John;

    cout<<"Please enter the number of days Bill has worked"<<endl;
    cin>>days_Bill;

    cout<<"Please enter the number of hours Bill has worked"<<endl;
    cin>>hours_Bill;

    cout<<"Please enter the number of minutes Bill has worked"<<endl;
    cin>>minutes_Bill;

    total_days = days_John + days_Bill;
    total_hours = hours_John + hours_Bill;
    total_minutes = minutes_John + minutes_Bill;

    total_days += total_hours / 24;

    total_hours = total_hours % 24;

    total_hours += total_minutes / 60;

    total_minutes = total_minutes % 60;

    cout<<"The total time both of them worked together is: "<<total_days<<" days, "<<total_hours<<" hours and "<<total_minutes<<" minutes.";

    return 0;
}
