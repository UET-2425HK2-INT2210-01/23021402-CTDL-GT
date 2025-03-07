#include <iostream>

using namespace std;

long long pow2_iterative(int n) {
    long long result = 1;
    for (int i = 0; i < n; ++i) {
        result *= 2;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    cout << pow2_iterative(n);
    return 0;
}

//Mã giả:
//function pow2(n):
 //  result = 1
 // for i = 1 to n:
 //result = result * 2
 //return result


