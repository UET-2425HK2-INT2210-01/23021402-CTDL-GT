#include <iostream>

using namespace std;

void binnum(string s, int n) { // Hàm in ra tất cả các số nhị phân
    if (s.size() == n) { // Điều kiện dừng khi chuỗi đạt độ dài n
        cout << s << "\n"; // In chuỗi ra màn hình
        return;
    }
    binnum(s + '0', n); // Thử chuỗi có thêm ký tự '0'
    binnum(s + '1', n); // Thử chuỗi có thêm ký tự '1'
}

int main() {
    int n;
    cin >> n; // Nhập vào độ dài của chuỗi nhị phân
    string s = ""; // Bắt đầu với một chuỗi rỗng
    binnum(s, n); // Gọi hàm để in tất cả các chuỗi nhị phân có độ dài n
}
