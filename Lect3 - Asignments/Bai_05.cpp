#include <iostream>

using namespace std;

const int SIZE = 1000;

class Stack {
private:
    int top;
    int data[SIZE];

public:
    Stack() { top = -1; }

    void push(int val) {
        if (top >= SIZE - 1) {
            cout << "Overflow\n";
            return;
        }
        data[++top] = val;
    }

    void pop() {
        if (top < 0) {
            cout << "Underflow\n";
            return;
        }
        top--;
    }

    void show() {
        if (top < 0) {
            cout << "Empty\n";
            return;
        }
        for (int i = top; i >= 0; --i)
            cout << data[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.show();

    s.pop();
    s.show();

    return 0;
}
