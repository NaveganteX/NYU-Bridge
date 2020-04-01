//Shallow Copy Example

#include <iostream>
using namespace std;

class Thing {
    int* value;
public:
    explicit Thing(int newVal = 0) :value(new int(newVal)) {}

    int getValue() const {
        return *value;
    }
};

int main() {
    Thing one(13);
    Thing two(28);

/* Below, we are copying one to two. What is really happening is we are copying the pointer 'one'
 * to the value of object "two".
 * Now, both objects one and two have the value 2, and the memory of where one was pointing to (with value 1)
 * will be a memory leak
 */
    cout << "Before shallow copy:" << endl;
    cout << one.getValue() << endl; // prints "13"
    cout << two.getValue() << endl; // prints "28"

    one = two; // assigns one's *value pointer to two's *value pointer

    cout << "--------------------" << endl;
    cout << "After shallow copy:" << endl;
    // one's *value now points to 28; no longer able to access original value 13 (memory leak)
    cout << one.getValue() << endl;
    cout << two.getValue() << endl;
    return 0;
}
