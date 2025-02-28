#include <iostream>
using namespace std;

struct Node {
   int value;
   int count;
   Node* next;
   Node(int val) : value(val), count(1), next(nullptr) {}
};

void insert(Node*& head, int val) {
   Node* current = head;

   while (current != nullptr) {
      if (current->value == val) {
         current->count++;
         return;
      }
      current = current->next;
   }

   Node* newNode = new Node(val);
   newNode->next = head;
   head = newNode;
}

int count_pairs(Node* head) {
   int count = 0;
   Node* current = head;

   while (current != nullptr) {
      int f = current->count;
      if (f > 1) {
         count += (f * (f - 1)) / 2;
      }
      current = current->next;
   }
   return count;
}

int main() {
   int n;
   cin >> n;
   int A[n];
   for (int i = 0; i < n; i++) {
      cin >> A[i];
   }

   Node* head = nullptr;
   for (int i = 0; i < n; i++) {
      insert(head, A[i]);
   }
   cout << count_pairs(head) << endl;
   return 0;
}
