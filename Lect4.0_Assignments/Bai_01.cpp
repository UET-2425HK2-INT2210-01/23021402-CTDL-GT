#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void append(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void search(int x) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == x) {
                cout << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "NO" << endl;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;

        while (current) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;
        printList();
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    LinkedList linkedList;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "append") {
            int x;
            cin >> x;
            linkedList.append(x);
        } else if (command == "search") {
            int x;
            cin >> x;
            linkedList.search(x);
        } else if (command == "reverse") {
            linkedList.reverse();
        }
    }
    return 0;
}
