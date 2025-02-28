#include <iostream>
using namespace std;
void sort(int a[], int n) {
    int i, j;
    for (i = (n - 1); i >= 0; i--) {
        for (j = 1; j <= i; j++) {
            if (a[j - 1] > a[j]) {
                swap(a[j - 1], a[j]);
            }
        }
    }
}
int main() {
    int a[5];
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
    }
    sort(a, 5);
        cout << a[0]+a[4] ;
    return 0;
}
