#include<iostream>
using namespace std;

// Hàm tính số Fibonacci thứ n
int Fibonacci(int n){
    if(n == 0) 
        return 0; // F(0) = 0
    else if(n == 1) 
        return 1; // F(1) = 1
    else 
        return Fibonacci(n - 1) + Fibonacci(n - 2); // F(n) = F(n-1) + F(n-2)
}

int main(){
    int n;
    cout << "Nhap n: "; // Nhập số n
    cin >> n;

    int Ketqua = Fibonacci(n); // Gọi hàm Fibonacci và gán kết quả
    cout << Ketqua; // In kết quả

    return 0; // Kết thúc chương trình
}
