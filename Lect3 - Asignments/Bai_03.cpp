#include <iostream>

using namespace std;

const int CAPACITY = 1000;

class Queue {
private:
    int start, end;
    int data[CAPACITY];

public:
    Queue() {
        start = end = 0;
    }

    void push(int value) {
        if (end == CAPACITY) {
            cout << "Queue Overflow\n";
            return;
        }
        data[end++] = value;
    }

    void pop() {
        if (start == end) {
            cout << "Queue Underflow\n";
            return;
        }
        start++;
    }

    void show() {
        if (start == end) {
            cout << "Queue Empty\n";
            return;
        }
        for (int i = start; i < end; i++)
            cout << data[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);

    q.show();

    q.pop();
    q.show();

    return 0;
}
