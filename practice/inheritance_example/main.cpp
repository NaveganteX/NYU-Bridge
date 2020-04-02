#include <iostream>
using namespace std;

// Pet is the base class
class Pet {
    string name;
    int petID;

public:
    Pet(int newID = 0) { petID = newID; }
    string getName() const { return name; }
    virtual void setName(string newName) { name = newName; }
    virtual void speak() const {}
};

// Cat is a Pet; it is a derived class
class Cat :public Pet {
    double whiskerLength;

public:
    /*
     * because the petID is a private data member in the base class, so the only way to set petID is
     * to use base initialization list
     */
    Cat() :Pet(10000) {}
    void Cat::speak() const {
        cout << "Meow!" << endl;
        Pet::speak();
    }
    void setLength(double newLength) { whiskerLength = newLength; }
    double getLength() const { return whiskerLength; }
    void Cat::setName(string newName) {
        whiskerLength = 0;
        Pet::setName(newName);
    }
    Cat& operator = (const Pet&);
};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
