#include <iostream>

using namespace std;

// Hàm đệ quy để sinh hoán vị
void permute(int n, int k, bool used[], int res[]) { 
    if (k == n) { // Nếu đã có đủ n phần tử, in ra hoán vị
        for (int i = 0; i < n; ++i) {
            cout << res[i] << " "; // In từng phần tử trong hoán vị
        }
        cout << "\n";
        return;
    }
    // Duyệt qua tất cả các số từ 1 đến n để tạo hoán vị
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) { // Kiểm tra nếu phần tử i chưa được sử dụng
            res[k] = i; // Gán giá trị vào vị trí k của mảng hoán vị
            used[i] = true; // Đánh dấu phần tử i đã được sử dụng
            permute(n, k + 1, used, res); // Gọi đệ quy để tìm phần tiếp theo của hoán vị
            used[i] = false; // Sau khi quay lại, đánh dấu phần tử i là chưa sử dụng
        }
    }
}

int main() {
    int n; // Biến số lượng phần tử trong hoán vị
    cin >> n; // Nhập vào n
    bool* used = new bool[n + 1]; // Tạo mảng used để đánh dấu phần tử đã sử dụng
    for (int i = 0; i <= n; ++i) { // Khởi tạo mảng used với giá trị false (chưa dùng)
        used[i] = false;
    }
    int* res = new int[n]; // Tạo mảng res để lưu trữ hoán vị
    permute(n, 0, used, res); // Gọi hàm đệ quy để sinh hoán vị từ chỉ số 0
}
