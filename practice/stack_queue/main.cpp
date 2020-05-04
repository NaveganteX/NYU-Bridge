#include <iostream>
#include <list>
using namespace std;

template <class T>
class Stack {
    list<T> data;

public:
    void push(T new_item) { data.push_front(new_item); }
    T pop() { return data.pop_front(); }
    T top() { return *data.begin(); }
    bool isEmpty() const { return data.size() == 0; }
    int size() const{ return data.size(); }
    void clear() { data.clear(); }
};

template <class T>
class Queue {
    list<T> data;
public:
    void enqueue(T new_item) { data.push_back(new_item); }
    T dequeue() { return data.pop_front(); }
    T top() const { return *data.begin(); }
    bool isEmpty() { return data.size() == 0; }
    int size() { return data.size(); }
    void clear() { data.clear(); }
};


int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
