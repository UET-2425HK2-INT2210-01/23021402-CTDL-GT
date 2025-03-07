#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
};

class Queue {
private:
    Node *head, *tail;

public:
    Queue() {
        head = tail = nullptr;
    }

    void push(int x) {
        Node* node = new Node{x, nullptr};
        if (!tail) {
            head = tail = node;
            return;
        }
        tail->next = node;
        tail = node;
    }

    void pop() {
        if (!head) {
            cout << "Underflow\n";
            return;
        }
        Node* tmp = head;
        head = head->next;
        if (!head) tail = nullptr;
        delete tmp;
    }

    void show() {
        if (!head) {
            cout << "Empty\n";
            return;
        }
        Node* cur = head;
        while (cur) {
            cout << cur->val << " ";
            cur = cur->next;
        }
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
/*
 Node:
 val (giá trị)
 next (trỏ đến phần tử sau)

Queue:
-head, tail (phần tử đầu & cuối)

HÀM push(x):
- Tạo node mới chứa x
- Nếu rỗng: head = tail = node mới
- Ngược lại: tail.next = node mới, cập nhật tail

HÀM pop():
- Nếu rỗng: In "Hàng đợi trống!"
- Ngược lại: Di chuyển head, nếu rỗng thì tail = NULL

HÀM show():
- Nếu rỗng: In "Hàng đợi trống!"
- Ngược lại: Duyệt từ head đến tail và in giá trị

HÀM CHÍNH:
- Tạo hàng đợi q
- push(10), push(20), push(30)
- show()
- pop(), show()
*/
