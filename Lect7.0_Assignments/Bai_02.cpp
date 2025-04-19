#include<iostream> /
using namespace std;

// Hàm tính giai thừa của n (n!)
int Tinhgiaithua(int n){
    if(n == 1)
        return 1; // Giai thừa của 1 là 1
    else 
        return n * Tinhgiaithua(n - 1); // Giai thừa = n * (n-1)!
}

int main(){
    int n;
    cout << "Nhap n: "; // Nhập số nguyên n
    cin >> n;

    int Ketqua = Tinhgiaithua(n); // Gọi hàm tính giai thừa
    cout << Ketqua; // In kết quả

    return 0; // Kết thúc chương trình
}
