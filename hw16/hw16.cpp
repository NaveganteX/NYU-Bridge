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
public:
    void enqueue(T new_item) { data_vector.push_back(new_item); }
    T dequeue() {
        T item = data_vector[front];
        front += 1;
        return item;
    }
    T top() { return data_vector[front]; }
    bool isEmpty() { return data_vector.empty(); }
    int size() { return data_vector.size() - front; }
    void clear() {
        front = 0;
        data_vector.clear();
    }
};

int main() {
    ifstream inFile;
    openInputFile(inFile);
    balanceSymbol(inFile);

    cout << endl;

    Queue<int> q;
    for (int i = 0; i < 1000; ++i) {
        q.enqueue(i);
    }
    for (int j = 0; j < 100; ++j) {
        q.dequeue();
    }

    return 0;
}
