#include<iostream> 
using namespace std;

// Hàm đếm số chữ số trong một số nguyên dương n
int Demsonguyen(int n){
    if (n <= 0) 
        return 0; // Nếu n <= 0 thì không còn chữ số nào
    else 
        return 1 + Demsonguyen(n / 10); // Mỗi lần chia 10 là bỏ đi 1 chữ số => đếm thêm 1
}

int main(){
    int n;
    cout << "Nhap n: "; // Nhập số nguyên n
    cin >> n;

    cout << Demsonguyen(n); // Gọi hàm đếm và in kết quả
    return 0; 
}
