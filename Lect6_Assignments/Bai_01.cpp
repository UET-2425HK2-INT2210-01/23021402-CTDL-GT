#include <iostream>
using namespace std;

// Định nghĩa node của cây nhị phân
struct node {
    int data;           // Giá trị của node
    node* left;         // Con trỏ đến node con bên trái
    node* right;        // Con trỏ đến node con bên phải

    node(int value) {   // Constructor khởi tạo node với giá trị value
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Định nghĩa lớp binarytree (cây nhị phân tìm kiếm)
class binarytree {
public:
    node* root = nullptr;   // Gốc của cây, khởi đầu là nullptr

    // Hàm thêm phần tử vào cây
    void insert(node*& root, int value) {
        if (root == nullptr) {             // Nếu node hiện tại rỗng
            root = new node(value);        // Tạo node mới với giá trị value
            return;
        }
        if (value < root->data) {          // Nếu giá trị nhỏ hơn node hiện tại
            insert(root->left, value);     // Đệ quy thêm vào cây con bên trái
        }
        else if (value > root->data) {     // Nếu giá trị lớn hơn node hiện tại
            insert(root->right, value);    // Đệ quy thêm vào cây con bên phải
        }
        // Nếu bằng thì không thêm (cây nhị phân không chứa phần tử trùng)
    }

    // Hàm tìm node nhỏ nhất trong cây con bên phải
    node* minright(node* temp) {
        while (temp && temp->left != nullptr) { // Lặp đến node trái ngoài cùng
            temp = temp->left;
        }
        return temp; // Trả về node có giá trị nhỏ nhất
    }

    // Hàm xóa phần tử trong cây
    void deleted(node*& root, int value) {
        if (root == nullptr) return;  // Nếu cây rỗng thì không làm gì cả

        if (value < root->data) {         // Nếu giá trị nhỏ hơn, tìm ở cây trái
            deleted(root->left, value);   // Đệ quy
        }
        else if (value > root->data) {    // Nếu giá trị lớn hơn, tìm ở cây phải
            deleted(root->right, value);  // Đệ quy
        }
        else {  // Tìm thấy node cần xóa
            if (root->left == nullptr) {      // Nếu không có con trái
                node* temp = root->right;     // Giữ lại con phải
                delete root;                  // Xóa node hiện tại
                root = temp;                  // Gán con phải lên
            }
            else if (root->right == nullptr) { // Nếu không có con phải
                node* temp = root->left;       // Giữ lại con trái
                delete root;                   // Xóa node hiện tại
                root = temp;                   // Gán con trái lên
            }
            else {  // Có cả hai con
                node* temp = minright(root->right); // Tìm node nhỏ nhất bên phải
                root->data = temp->data;            // Thay giá trị node cần xóa
                deleted(root->right, temp->data);   // Xóa node thay thế ở cây con phải
            }
        }
    }

    // Duyệt cây theo thứ tự LNR (trái - gốc - phải)
    void inorder(node* root) {
        if (root != nullptr) {
            inorder(root->left);              // Duyệt cây con trái
            cout << root->data << " ";        // In giá trị node hiện tại
            inorder(root->right);             // Duyệt cây con phải
        }
    }
};

int main() {
    binarytree tree;

    // Thêm các giá trị vào cây
    tree.insert(tree.root, 2);
    tree.insert(tree.root, 1);
    tree.insert(tree.root, 10);
    tree.insert(tree.root, 6);
    tree.insert(tree.root, 3);
    tree.insert(tree.root, 8);
    tree.insert(tree.root, 7);
    tree.insert(tree.root, 13);
    tree.insert(tree.root, 20);

    // Thêm thêm vài giá trị nữa
    tree.insert(tree.root, 14);
    tree.insert(tree.root, 0);
    tree.insert(tree.root, 35);

    // Xóa một vài node có giá trị cụ thể
    tree.deleted(tree.root, 6);
    tree.deleted(tree.root, 13);
    tree.deleted(tree.root, 35);

    return 0;
}
