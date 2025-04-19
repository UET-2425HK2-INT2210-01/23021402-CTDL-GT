#include<iostream>
using namespace std;

// Hàm tính lũy thừa x^n (dùng đệ quy)
int Tinhluythua(int x, int n){
    if(x == 0) 
        return 0; // Nếu x = 0 thì kết quả luôn là 0 (trừ khi n = 0, thường không định nghĩa)
    else if(n == 0) 
        return 1; // Bất kỳ số nào mũ 0 cũng bằng 1
    else 
        return x * Tinhluythua(x, n - 1); // x^n = x * x^(n-1)
}

int main(){
    int x, n;
    cout << "Nhap x: "; // Nhập cơ số x
    cin >> x;
    
    cout << "Nhap n: "; // Nhập số mũ n
    cin >> n;

    int Kq = Tinhluythua(x, n); // Gọi hàm tính lũy thừa
    cout << "Ket qua : " << Kq << endl; // In kết quả

    return 0; // Kết thúc chương trình
}
