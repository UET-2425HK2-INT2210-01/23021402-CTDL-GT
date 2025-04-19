#include<iostream>
using namespace std;

// Hàm đệ quy in ngược các chữ số của số nguyên dương n
void Innguoc(int n) {
    if (n == 0) 
        return; // Khi n = 0 thì dừng lại (không làm gì nữa)
    else {
        cout << n % 10; // In ra chữ số cuối cùng của n
        Innguoc(n / 10); // Gọi lại hàm với n đã bỏ đi chữ số cuối
    }
}

int main() {
    int n;
    cout << "Nhap n: "; // Nhập số nguyên dương
    cin >> n;

    cout << "Kq: ";  
    Innguoc(n); // Gọi hàm in ngược
    return 0; 
}
