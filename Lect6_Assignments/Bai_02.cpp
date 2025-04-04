#include <iostream> // Vẫn cần thư viện này cho cout
using namespace std;

// Định nghĩa lớp min_heap (cây heap nhị phân nhỏ - đỉnh là phần tử nhỏ nhất)
class min_heap {
public:
    int* heap;      // Mảng lưu trữ các phần tử của heap
    int size;       // Kích thước hiện tại của heap

    min_heap() {
        size = 0;                   // Khởi tạo size = 0
        heap = new int[1000];       // Cấp phát động mảng với kích thước tối đa 1000
    }

    // Hàm đẩy phần tử lên (sửa heap khi thêm phần tử mới vào)
    void push_up(int index) {
        int parent;
        while (index > 0) {
            parent = (index - 1) / 2;                // Tính chỉ số cha
            if (heap[index] < heap[parent]) {        // Nếu con nhỏ hơn cha thì hoán đổi
                std::swap(heap[index], heap[parent]);
                index = parent;                      // Tiếp tục kiểm tra ở vị trí cha
            }
            else {
                break;                               // Đã đúng vị trí, dừng lại
            }
        }
    }

    // Hàm thêm phần tử mới vào heap
    void push(int value) {
        heap[size] = value;      // Thêm phần tử vào cuối mảng
        push_up(size);           // Đẩy phần tử lên đúng vị trí trong heap
        size++;                  // Tăng kích thước heap
    }

    // Hàm sửa heap từ trên xuống sau khi xóa hoặc thay đổi phần tử
    void heapifyDown(int index) {
        int left = 2 * index + 1;       // Chỉ số con trái
        int right = 2 * index + 2;      // Chỉ số con phải
        int smallest = index;          // Giả sử node hiện tại là nhỏ nhất

        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;           // Cập nhật nếu con trái nhỏ hơn
        }
        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;          // Cập nhật nếu con phải nhỏ hơn
        }

        if (smallest != index) {               // Nếu có sự thay đổi
            std::swap(heap[index], heap[smallest]); // Hoán đổi với con nhỏ hơn
            heapifyDown(smallest);             // Đệ quy tiếp tục với vị trí mới
        }
    }

    // Hàm xóa phần tử bất kỳ khỏi heap
    void deleted(int value) {
        int index;
        for (int i = 0; i < size; i++) {
            if (heap[i] == value) {    // Tìm vị trí chứa giá trị cần xóa
                index = i;
                break;
            }
        }
        heap[index] = heap[size - 1];  // Gán phần tử cuối cùng vào vị trí bị xóa
        heapifyDown(index);           // Gọi hàm sửa heap từ vị trí đó xuống
        size--;                       // Giảm kích thước heap
    }
};

int main() {
    min_heap a;

    // Thêm các phần tử vào heap
    a.push(2);
    a.push(1);
    a.push(10);
    a.push(6);
    a.push(3);
    a.push(8);
    a.push(7);
    a.push(13);
    a.push(20);
    a.push(14);
    a.push(0);
    a.push(35);

    // Xóa các phần tử cụ thể khỏi heap
    a.deleted(6);
    a.deleted(13);
    a.deleted(35);

    // In các phần tử trong heap sau khi xóa
    for (int i = 0; i < a.size; i++) {
        cout << a.heap[i] << " ";
    }
}
