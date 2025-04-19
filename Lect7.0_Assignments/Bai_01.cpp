#include<iostream> 
using namespace std; 

// Hàm tính tổng từ 1 đến n (dùng đệ quy)
int Tong(int n){
    if(n == 1) 
        return 1; // Nếu n là 1 thì trả về 1
    else 
        return n + Tong(n - 1); // Tổng = n + tổng từ 1 đến (n-1)
}

int main(){
    int n;
    cout << "Nhập n: "; // Nhập số nguyên n
    cin >> n;

    int ketqua = Tong(n); // Gọi hàm tính tổng
    cout << ketqua; // In kết quả

    return 0; // Kết thúc chương trình
}
