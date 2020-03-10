#include <iostream>
using namespace std;

int main() {
    int x = 5;
    int *ptr = 13;

    ptr = new int;
    cout << *ptr << endl;
    *ptr = x;

    cout << *ptr << endl;
    return 0;
}
