#include <iostream>
#include <fstream>  // Thư viện dùng để đọc/ghi file

using namespace std;

// Hàm gộp hai mảng con đã sắp xếp thành một mảng lớn được sắp xếp
void merge(double arr[], int left, int mid, int right) {
    // Tính kích thước của hai mảng con
    int sizeLeft = mid - left + 1;
    int sizeRight = right - mid;

    // Cấp phát mảng tạm để chứa hai nửa
    double* leftArr = new double[sizeLeft];
    double* rightArr = new double[sizeRight];

    // Sao chép dữ liệu từ mảng chính sang hai mảng con
    for (int i = 0; i < sizeLeft; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < sizeRight; ++j)
        rightArr[j] = arr[mid + 1 + j];

    // Gộp hai mảng con vào lại mảng chính theo thứ tự tăng dần
    int i = 0;        // Chỉ số duyệt mảng trái
    int j = 0;        // Chỉ số duyệt mảng phải
    int k = left;     // Chỉ số hiện tại của mảng chính

    while (i < sizeLeft && j < sizeRight) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    // Sao chép phần còn lại (nếu có) từ mảng trái
    while (i < sizeLeft)
        arr[k++] = leftArr[i++];

    // Sao chép phần còn lại (nếu có) từ mảng phải
    while (j < sizeRight)
        arr[k++] = rightArr[j++];

    // Giải phóng bộ nhớ cấp phát tạm
    delete[] leftArr;
    delete[] rightArr;
}

// Hàm đệ quy để chia nhỏ mảng và sắp xếp từng phần
void mergeSort(double arr[], int left, int right) {
    if (left >= right) return;  // Điều kiện dừng: mảng chỉ còn 1 phần tử

    int mid = (left + right) / 2;  // Tìm vị trí giữa mảng

    mergeSort(arr, left, mid);       // Gọi đệ quy sắp xếp nửa trái
    mergeSort(arr, mid + 1, right);  // Gọi đệ quy sắp xếp nửa phải
    merge(arr, left, mid, right);    // Gộp hai nửa lại với nhau
}

int main() {
    // Mở file đầu vào (numbers.txt) để đọc dữ liệu
    freopen("numbers.txt", "r", stdin);

    // Mở file đầu ra (numbers.sorted) để ghi kết quả
    freopen("numbers.sorted", "w", stdout);

    // Cấp phát mảng đủ lớn để chứa các số đọc được
    double* a = new double[10000];  // Giả sử tối đa 10.000 số
    int n = 0;                      // Biến đếm số phần tử đã đọc

    // Đọc từng số thực (double) từ file cho đến hết
    while (cin >> a[n]) {
        n++;
    }

    // Gọi hàm merge sort để sắp xếp mảng từ chỉ số 0 đến n-1
    mergeSort(a, 0, n - 1);

    // Ghi kết quả đã sắp xếp ra file, các số cách nhau bằng dấu cách
    for (int i = 0; i < n; ++i) {
        cout << a[i];
        if (i < n - 1) cout << " ";  // In dấu cách giữa các số, trừ số cuối
    }

    // Giải phóng bộ nhớ đã cấp phát
    delete[] a;

    return 0;
}
