#include <iostream>
using namespace std;

const int MAX_SIZE = 1000; // Kích thước tối đa của mảng

// Hàm phân tách mảng và trả về chỉ số của pivot sau khi phân chia
int partition(double array[], int left, int right);

// Hàm sắp xếp nhanh QuickSort sử dụng đệ quy
void quickSort(double array[], int left, int right) {
    if (left < right) {
        // Chọn vị trí pivot và phân chia mảng
        int pivotPos = partition(array, left, right);

        // Gọi đệ quy sắp xếp phần bên trái pivot
        quickSort(array, left, pivotPos - 1);
        // Gọi đệ quy sắp xếp phần bên phải pivot
        quickSort(array, pivotPos + 1, right);
    }
}

// Hàm partition chia mảng dựa trên pivot
int partition(double array[], int left, int right) {
    double pivotValue = array[right]; // Chọn phần tử cuối làm pivot
    int smallerIndex = left - 1;      // Chỉ số của phần tử nhỏ hơn pivot

    // Duyệt từ left đến trước right
    for (int current = left; current < right; current++) {
        if (array[current] <= pivotValue) {
            // Nếu phần tử hiện tại <= pivot thì hoán đổi về bên trái
            ++smallerIndex;
            swap(array[smallerIndex], array[current]);
        }
    }

    // Đưa pivot vào đúng vị trí giữa các phần nhỏ hơn và lớn hơn
    swap(array[smallerIndex + 1], array[right]);
    return smallerIndex + 1; // Trả về vị trí pivot mới
}

int main() {
    int n;
    cin >> n; // Nhập số lượng phần tử

    // Nếu vượt quá kích thước cho phép thì thoát
    if (n > MAX_SIZE) return 1;

    double values[MAX_SIZE]; // Khởi tạo mảng chứa số thực

    // Nhập các giá trị vào mảng
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    // Gọi hàm QuickSort để sắp xếp mảng
    quickSort(values, 0, n - 1);

    // In ra mảng đã sắp xếp, cách nhau bởi dấu cách
    for (int i = 0; i < n; i++) {
        // Nếu là số nguyên (không có phần thập phân) thì in dạng int
        if (values[i] == (int)values[i])
            cout << (int)values[i];
        else
            cout << values[i];

        if (i < n - 1) cout << " ";
    }

    return 0;
}
