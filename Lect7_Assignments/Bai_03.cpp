#include <iostream>

using namespace std;

// Hàm tính GCD của hai số n và m bằng đệ quy
int gcd(int n, int m) {
    // Điều kiện dừng: nếu m = 0, thì GCD là n
    if (m == 0) {
        return n;
    }
    // Đệ quy: gọi GCD với tham số (m, n % m)
    return gcd(m, n % m);
}

int main() {
    int n, m;
    cin >> n >> m;  // Nhập hai số n và m từ bàn phím
    cout << gcd(n, m);  // In ra GCD của n và m
    return 0;
}
