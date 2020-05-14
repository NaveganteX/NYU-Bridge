#include <iostream>
#include <vector>
#include <string>
using namespace std;

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
    Queue<int> q;
    for (int i = 0; i < 300; ++i) {
        q.enqueue(i);
    }
    for (int j = 0; j < 100; ++j) {
        q.dequeue();
    }

    cout << "size: " << q.size() << endl;
    int size = q.size();
    for (int k = 0; k < size; ++k) {
        cout << q.dequeue() << " ";
    }

    return 0;
}
