#include <iostream>
#include <string>
using namespace std;

int main() {
    int duration, hour, minutes;
    double rate, cost;
    string day;
    char colon;

    cout << "What day did your call start (Mo, Tu, We, Th, Fr, Sa, Su)? " << endl;
    cin >> day;

    cout << "What time did your call start (use 24-hour notation with space separating the hours, the colon and the minutes)? " << endl;
    cin >> hour >> colon >> minutes;

    cout << "How long was your call (in minutes)? " << endl;
    cin >> duration;

    if ((day != "Sa") && (day != "Su")) {
        if ((hour >= 8) && (hour <= 18)) {
            if ((hour == 18) && (minutes > 0)) {
                rate = .25;
            } else {
                rate = .40;
            }
        } else {
            rate = .25;
        }
    } else {
        rate = .15;
    }

    cost = duration * rate;
    cout << "The total cost for your call is: $" << cost;
    return 0;
}
