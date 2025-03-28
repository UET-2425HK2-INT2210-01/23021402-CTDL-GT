#include <iostream>
using namespace std;

// Khai báo cấu trúc node
struct node {
    int data; // Giá trị của node
    node* firstchildren; // Con đầu tiên bên trái
    node* nextsibling; // Node anh em bên phải
    
    node(int value) { // Hàm khởi tạo
        data = value;
        firstchildren = nullptr;
        nextsibling = nullptr;
    }
};

// Khai báo class tree
class tree {
public:
    node* root = nullptr; // Khởi tạo gốc cây

    // Hàm tìm kiếm node theo giá trị
    node* find(node* root, int value) {
        if (root == nullptr) return nullptr;
        if (root->data == value) return root;

        node* foundInChildren = find(root->firstchildren, value);
        if (foundInChildren) return foundInChildren;

        return find(root->nextsibling, value);
    }

    // Hàm thêm node vào cây
    void add(int parent, int value) {
        if (root == nullptr) { // Nếu cây rỗng
            root = new node(parent);
            root->firstchildren = new node(value);
            return;
        }

        node* Parent = find(root, parent);
        if (Parent == nullptr) return; // Nếu không tìm thấy node cha

        node* newnode = new node(value);

        if (Parent->firstchildren == nullptr) { // Nếu chưa có con
            Parent->firstchildren = newnode;
        } else { // Nếu đã có con, thêm vào cuối danh sách anh em
            node* temp = Parent->firstchildren;
            while (temp->nextsibling != nullptr) {
                temp = temp->nextsibling;
            }
            temp->nextsibling = newnode;
        }
    }

    // Duyệt cây theo Preorder (Root -> Children -> Siblings)
    void preorder(node* root) {
        if (root == nullptr) return;
        cout << root->data << " ";
        preorder(root->firstchildren);
        preorder(root->nextsibling);
    }

    // Duyệt cây theo Postorder (Children -> Siblings -> Root)
    void postorder(node* root) {
        if (root == nullptr) return;
        postorder(root->firstchildren);
        cout << root->data << " ";
        postorder(root->nextsibling);
    }

    // Kiểm tra cây có phải là cây nhị phân không
    bool binarytree(node* root) {
        if (root == nullptr) return true;

        node* child = root->firstchildren;
        int count = 0;

        while (child) {
            count++;
            if (count > 2) return false; // Nếu có hơn 2 con thì không phải cây nhị phân
            if (!binarytree(child)) return false; // Kiểm tra đệ quy
            child = child->nextsibling;
        }
        return true;
    }

    // Duyệt cây theo Inorder (Chỉ áp dụng với cây nhị phân)
    void inorder(node* root) {
        if (root == nullptr) return;

        if (root->firstchildren) inorder(root->firstchildren);
        cout << root->data << " ";

        if (root->firstchildren && root->firstchildren->nextsibling) {
            inorder(root->firstchildren->nextsibling);
        }
    }

    // Tính chiều cao của cây
    int height(node* root) {
        if (root == nullptr) return 0; // Trả về 0 thay vì -1 để đúng với định nghĩa độ cao cây
        
        int maxheight = 0;
        node* child = root->firstchildren;
        while (child) {
            maxheight = max(maxheight, height(child));
            child = child->nextsibling;
        }
        return maxheight + 1;
    }
};

int main() {
    tree list;
    int n, m;
    cin >> n >> m; // Đọc số node và số cạnh

    while (m--) {
        int a, b;
        cin >> a >> b;
        list.add(a, b);
    }

    cout << list.height(list.root) - 1 << endl; // In ra độ cao (trừ 1 để đúng yêu cầu đề bài)
    
    list.preorder(list.root);
    cout << endl;
    
    list.postorder(list.root);
    cout << endl;

    if (list.binarytree(list.root)) {
        list.inorder(list.root);
        cout << endl;
    } else {
        cout << "NOT BINARY TREE\n";
    }

    return 0;
}
