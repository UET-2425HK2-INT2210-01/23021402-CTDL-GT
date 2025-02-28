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
    int n, a[n];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
