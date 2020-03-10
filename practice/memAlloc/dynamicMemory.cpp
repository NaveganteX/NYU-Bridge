#include <iostream>
using namespace std;

int main() {
    int x = 5;
    int *ptr = nullptr;

    ptr = new int;
    cout << *ptr << endl;
    *ptr = x;

    cout << *ptr << endl;

    delete ptr;
    ptr = nullptr;

    return 0;
}
