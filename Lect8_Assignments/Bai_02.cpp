#include <iostream>
using namespace std;

// Hàm quay lui để kiểm tra xem có tập con nào có tổng bằng X hay không
bool findSubsetSum(int A[], int n, int X, int index, int currentSum) {
    // Nếu tổng hiện tại bằng X, trả về true
    if (currentSum == X) {
        return true;
    }

    // Nếu đã duyệt hết mảng hoặc tổng hiện tại vượt quá X, trả về false
    if (index >= n || currentSum > X) {
        return false;
    }

    // Hai lựa chọn: bao gồm hoặc không bao gồm A[index]

    // Lựa chọn 1: Bao gồm A[index] vào tổng
    if (findSubsetSum(A, n, X, index + 1, currentSum + A[index])) {
        return true;
    }

    // Lựa chọn 2: Bỏ qua A[index]
    if (findSubsetSum(A, n, X, index + 1, currentSum)) {
        return true;
    }

    // Nếu không có tập con nào thỏa điều kiện
    return false;
}

int main() {
    int n, X;
    cin >> n >> X; // Nhập số lượng học sinh và tổng cần tìm

    int A[n]; // Mảng lưu độ tuổi của học sinh

    for (int i = 0; i < n; i++) {
        cin >> A[i]; // Nhập từng độ tuổi
    }

    // Gọi hàm kiểm tra và in kết quả
    if (findSubsetSum(A, n, X, 0, 0)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
