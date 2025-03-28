#include <iostream>
using namespace std;

// Khai báo cấu trúc node
struct node {
    int data; // Giá trị của node
    node* firstchildren; // Con đầu tiên bên trái
    node* nextsibling; // Node anh em bên phải
    
    node(int value) { // Hàm khởi tạo
        data = value;
        firstchildren = nullptr;// Đặt 2 con trỏ
        nextsibling = nullptr;
    }
};

// Khai báo class tree
class tree {
public:
    node* root = nullptr; // Khởi tạo gốc cây

    // Hàm tìm kiếm node theo giá trị
    node* find(node* root, int value) {
        if (root == nullptr) return nullptr; // Nếu cây rỗng, trả về nullptr
        if (root->data == value) return root;  // Nếu tìm thấy giá trị cần tìm, trả về node đấy

        node* foundInChildren = find(root->firstchildren, value); // Tìm kiếm đệ quy trong cây con, hàm find trên cây con
        if (foundInChildren) return foundInChildren;  

        return find(root->nextsibling, value); // Nếu tìm thấy trả về node chứa giá trị
    }

    // Hàm thêm node vào cây
    void add(int parent, int value) {
        if (root == nullptr) { // Nếu cây rỗng
            root = new node(parent); // Tạo node gốc nếu cây chưa có root
            root->firstchildren = new node(value); // Gán con 
            return;
        }

        node* Parent = find(root, parent);
        if (Parent == nullptr) return; // Nếu không tìm thấy node cha, thoát

        node* newnode = new node(value); // Tạo node mới chứa giá trị (value)

        if (Parent->firstchildren == nullptr) { // Nếu chưa có con
            Parent->firstchildren = newnode;
        } else { // Nếu đã có con, tìm con cuối và thêm vào cuối danh sách anh em
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
        cout << root->data << " "; // In node hiện tại
        preorder(root->firstchildren);  // Duyệt cây con trước
        preorder(root->nextsibling);  // Duyệt anh em
    }

    // Duyệt cây theo Postorder (Children -> Siblings -> Root)
    void postorder(node* root) {
        if (root == nullptr) return;
        postorder(root->firstchildren);
        cout << root->data << " ";  // In node sau khi duyệt anh em
        postorder(root->nextsibling);
    }

    // Kiểm tra cây có phải là cây nhị phân không
    bool binarytree(node* root) {
        if (root == nullptr) return true; // Cây rỗng thì mặc định cây nhị phân

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

        if (root->firstchildren) inorder(root->firstchildren);  // Duyệt cây con trái
        cout << root->data << " ";  // In Node hiện tại

        if (root->firstchildren && root->firstchildren->nextsibling) {
            inorder(root->firstchildren->nextsibling);  // Duyệt cây con phải
        }
    }

    // Tính chiều cao của cây
    int height(node* root) {
        if (root == nullptr) return 0; // Trả về 0 nếu không có node
        
        int maxheight = 0;
        node* child = root->firstchildren;
        while (child) {
            maxheight = max(maxheight, height(child));  // Tìm chiều cao lớn nhất của con
            child = child->nextsibling;
        }
        return maxheight + 1;  // Thêm 1 vì tính luôn node hiện tại
    }
};

int main() {
    tree list;
    int n, m;
    cin >> n >> m; // Đọc số node và số cạnh

    while (m--) {
        int a, b; 
        cin >> a >> b;
        list.add(a, b);  // Nhập a(node cha) và b (node con) vào cây
    }

    cout << list.height(list.root) - 1 << endl; // In ra độ cao (trừ 1 theo đề bài)
    
    list.preorder(list.root); // duyệt preorder
    cout << endl;
    
    list.postorder(list.root); // duyệt postorder
    cout << endl;

    if (list.binarytree(list.root)) { // Nếu là cây nhị phân duyệt theo inorder không thì in "NOT BINARY TREE"
        list.inorder(list.root);
        cout << endl;
    } else {
        cout << "NOT BINARY TREE\n";
    }

    return 0;
}
