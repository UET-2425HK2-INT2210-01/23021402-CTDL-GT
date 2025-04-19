#include<iostream>
using namespace std;

// Hàm tính tổng các chữ số trong số nguyên dương n
int Tongsonguyen(int n){
    if (n <= 0) 
        return 0; // Khi n <= 0 thì không còn chữ số nào để cộng
    else 
        return n % 10 + Tongsonguyen(n / 10); 
        // Lấy chữ số cuối (n % 10) + tổng chữ số còn lại (n / 10)
}

int main(){
    int n;
    cout << "Nhap n: "; // Nhập số nguyên n
    cin >> n;

    cout << Tongsonguyen(n); // Gọi hàm và in kết quả
    return 0; 
}
