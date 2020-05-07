#include <iostream>
#include <list>
#include <string>
#include <fstream>
using namespace std;

void openInputFile(ifstream &inFile) {
    string filename;
    cout << "What filename would you like to open?" << endl;
    cin >> filename;
    inFile.open(filename);

    while (!inFile) {
        cout << "FILE FAILED TO OPEN!" << endl;
        cout << "What filename would you like to open?" << endl;
        cin >> filename;
        inFile.clear();
        inFile.open(filename);
    }
}

template <class T>
class Stack {
    list<T> data;
public:
    void push(T new_item) { data.push_front(new_item); }
    void pop() { return data.pop_front(); }
    T top() { return *data.begin(); }
    bool isEmpty() const { return data.size() == 0; }
    int size() const{ return data.size(); }
    void clear() { data.clear(); }
};

bool balanceSymbol() {
    ifstream inFile;
    openInputFile(inFile);

    Stack<char> stack;
    char letter;
    while (inFile >> letter) {
        if ((letter == '{') || (letter == '(') || (letter == '[')) {
            stack.push(letter);
        }
        if ((letter == '}') || (letter == ')') || (letter == ']')) {
            if (stack.isEmpty()) {
                cout << "Code is not balanced, unpaired '" << letter  << "'"<< endl;
                return false;
            } else {
                if ((letter == '}') && (stack.top() != '{')) {
                    cout << "Code is not balanced, unpaired '" << letter  << "'"<< endl;
                    return false;
                } else if ((letter == ')') && (stack.top() != '(')) {
                    cout << "Code is not balanced, unpaired '" << letter  << "'"<< endl;
                    return false;
                } else if ((letter == ']') && (stack.top() != '[')) {
                    cout << "Code is not balanced, unpaired '" << letter  << "'"<< endl;
                    return false;
                } else {
                    stack.pop();
                }
            }
        }
    }

    if (stack.size() != 0) {
        cout << "Code is not balanced, unpaired '" << stack.top() << "'" << endl;
        return false;
    } else {
        cout << "Code is balanced!" << endl;
        return true;
    }
}

int main() {
    cout << balanceSymbol();

    return 0;
}
