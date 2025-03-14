#include <iostream>
using namespace std;

struct Node {
    char value;
    Node* previous;

    Node(char c) {
        value = c;
        previous = nullptr;
    }
};

class Stack {
public:
    Node* topNode = nullptr;

    void push(char c) {
        Node* newElement = new Node(c);
        newElement->previous = topNode;
        topNode = newElement;
    }

    char top() {
        if (topNode == nullptr) return '\0';
        return topNode->value;
    }

    void pop() {
        if (topNode != nullptr) {
            Node* temp = topNode;
            topNode = topNode->previous;
            delete temp;
        }
    }

    bool isEmpty() {
        return topNode == nullptr;
    }
};

bool isValid(string s) {
    Stack bracketStack;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            bracketStack.push(c);
        } else {
            if (bracketStack.isEmpty()) return false;
            char topChar = bracketStack.top();
            if ((c == ')' && topChar == '(') ||
                (c == ']' && topChar == '[') ||
                (c == '}' && topChar == '{')) {
                bracketStack.pop();
            } else {
                return false;
            }
        }
    }
    return bracketStack.isEmpty();
}

int main() {
    string inputString;
    cin >> inputString;
    
    if (isValid(inputString)) {
        cout << "Valid";
    } else {
        cout << "Invalid";
    }
    return 0;
}
