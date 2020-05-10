#include <iostream>
#include <string>;
using namespace std;

// Pet is the base class
class Pet {
//    C++ classes default members (variables, funtions, etc.) to Private if you do not specify
//    so "name" and "petID" are private members of Pet class
//    (Structs, however, default unspecified members to public)
    string name;
    int petID;

public:
//    Pet class constructor
    Pet(int newID = 0) { petID = newID; }
    string getName() const { return name; }
    virtual void setName(string newName) { name = newName; }
    virtual void speak() const {
        cout << "bleat(?)" << endl;
    }

    int getPetID() { return petID; }
};

// Cat :public Pet line indicates Cat is a derived class of Pet class
class Cat :public Pet {
    double whiskerLength;
    int age;
    string color;

public:
    /*
     * because the petID is a private data member in the base class, so the only way to set petID is
     * to use base initialization list
     */

//    Cat class constructor
    Cat() :Pet(10000) {}
    void speak() const override {
        cout << "Meow!" << endl;
//        Pet::speak();
    }
    void setLength(double newLength) { whiskerLength = newLength; }
    double getLength() const { return whiskerLength; }

    void setAge(int newAge) { age = newAge; }
    int getAge() const { return age; }

    void setName(string newName) override {
        whiskerLength = 13;
        Pet::setName(newName);
    }

    string getColor() {
        return this->color;
    }

//return by reference (Cat& getColor()...) whenever the thing we are returning existed before the function
//when we return a temp variable created inside the function, we CANNOT the function cannot return by reference
    Cat& setColor(string colorInput) {
        color = colorInput;
        return *this;
    }
};

int main() {
    Cat simba;
    simba.setName("Simba");
    simba.setColor("ginger");
//    cout << simba.getName() << endl;
//    cout << simba.getLength() << endl;

//    simba.setLength(23);
//    cout << simba.getLength() << endl;
//    simba.speak();
//
//    Pet doge;
//    doge.setName("Pluto");
//    cout << doge.getName() << endl;
//    doge.speak();
//
//    simba.setAge(56);
//    cout << simba.getAge() << endl;
//
//    cout << simba.getPetID() << endl;
//    Pet rock;
//    rock.setName("Rocko");
//    cout << rock.getName() << endl;
//    cout << rock.getPetID() << endl;

    Cat *catPtr = &simba;
    cout << catPtr->getName() << endl; //"Simba"
    cout << (*catPtr).getName() << endl; //"Simba"
    cout << simba.getColor() << endl;

    return 0;
}
