#include <iostream>
#include <string>
using namespace std;

int main() {
    int duration, hour, minutes;
    string day;
    char colon;

    cout << "What day did your call start (Mo, Tu, We, Th, Fr, Sa, Su)? " << endl;
    cin >> day;

    cout << "What time did your call start (use 24-hour notation)? " << endl;
    cin >> hour >> colon >> minutes;

    cout << "How long was your call (in minutes)? " << endl;
    cin >> duration;
    return 0;
}
