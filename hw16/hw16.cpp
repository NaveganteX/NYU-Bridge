#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <string>
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

bool balanceSymbol(ifstream &inFile) {
    Stack<char> stack;
    char symbol;
    while (inFile >> symbol) {
        if ((symbol == '{') || (symbol == '(') || (symbol == '[')) {
            stack.push(symbol);
        }
        if ((symbol == '}') || (symbol == ')') || (symbol == ']')) {
            if (stack.isEmpty()) {
                cout << "Code is not balanced, unpaired '" << symbol  << "'"<< endl;
                return false;
            } else {
                if ((symbol == '}') && (stack.top() != '{')) {
                    cout << "Code is not balanced, unpaired '" << symbol  << "'"<< endl;
                    return false;
                } else if ((symbol == ')') && (stack.top() != '(')) {
                    cout << "Code is not balanced, unpaired '" << symbol  << "'"<< endl;
                    return false;
                } else if ((symbol == ']') && (stack.top() != '[')) {
                    cout << "Code is not balanced, unpaired '" << symbol  << "'"<< endl;
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

template <class T>
class Queue {
    vector<T> data_vector;
    int front = 0;
    int end = data_vector.size() - 1;
public:
    void enqueue(T new_item) { data_vector.push_back(new_item); }
    T dequeue() {
        T item = data_vector[front];
        front += 1;
        return item;
    }
    bool isEmpty() { return data_vector.empty(); }
    int size() { return data_vector.size(); }
    void clear() { return data_vector.clear(); }
    int getFront() { return front; }
    int getEnd() { return end; }
};

int main() {
    ifstream inFile;
    openInputFile(inFile);
    cout << balanceSymbol(inFile);

    return 0;
}
