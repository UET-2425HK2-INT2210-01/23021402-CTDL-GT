#include <iostream>

using namespace std;

int main() {
    // Mở file để đọc dữ liệu đầu vào từ "matrix.txt"
    // và ghi kết quả ra "matrix.out"
    freopen("matrix.txt", "r", stdin);  
    freopen("matrix.out", "w", stdout);  

    // Nhập số dòng (m) và số cột (n) của ma trận
    int m, n;
    cin >> m >> n;  // Đọc m và n từ file

    // Cấp phát động ma trận 2 chiều a[m][n]
    int** a = new int*[m];  // Cấp phát m con trỏ
    for (int i = 0; i < m; ++i) {
        a[i] = new int[n];  // Mỗi con trỏ chứa một mảng cột
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];  // Nhập phần tử vào ma trận
        }
    }

    // Khởi tạo các biến để lưu tổng lớn nhất và tọa độ của hình chữ nhật
    int maxsumall = a[0][0];  // Tổng lớn nhất ban đầu là phần tử đầu tiên
    int finalTopRow = 0, finalLeftCol = 0;
    int finalBottomRow = 0, finalRightCol = 0;

    // Duyệt tất cả các cặp dòng startRow và endRow
    for (int startRow = 0; startRow < m; ++startRow) {
        int* temp = new int[n]();  // Mảng 1D tạm thời để lưu tổng cột

        // Duyệt qua các dòng từ startRow đến endRow
        for (int endRow = startRow; endRow < m; ++endRow) {
            // Cộng dồn các phần tử trong ma trận theo cột từ startRow đến endRow
            for (int col = 0; col < n; ++col) {
                temp[col] += a[endRow][col];  // Cộng các phần tử cột
            }

            // Áp dụng Kadane’s Algorithm để tìm tổng lớn nhất trong mảng temp
            int sum = temp[0], maxsumtmp = temp[0];
            int startCol = 0, tempLeft = 0, tempRight = 0;

            // Duyệt qua các cột trong mảng temp để tính tổng lớn nhất liên tiếp
            for (int col = 1; col < n; ++col) {
                // Nếu cộng sum với temp[col] nhỏ hơn temp[col] thì bắt đầu từ temp[col]
                if (sum + temp[col] < temp[col]) {
                    sum = temp[col];
                    startCol = col;  // Bắt đầu từ cột này
                } else {
                    sum += temp[col];  // Cộng dồn với sum
                }

                // Cập nhật tổng lớn nhất và vị trí bắt đầu, kết thúc
                if (sum > maxsumtmp) {
                    maxsumtmp = sum;
                    tempLeft = startCol;
                    tempRight = col;
                }
            }

            // Nếu tìm được tổng lớn hơn maxsumall thì cập nhật lại
            if (maxsumtmp > maxsumall) {
                maxsumall = maxsumtmp;

                // Lưu lại tọa độ của hình chữ nhật có tổng lớn nhất
                finalTopRow = startRow;
                finalBottomRow = endRow;
                finalLeftCol = tempLeft;
                finalRightCol = tempRight;
            }
        }

        // Giải phóng mảng tạm thời
        delete[] temp;
    }

    // In kết quả ra file: tọa độ (r1, c1) đến (r2, c2) và tổng s
    cout << finalTopRow + 1 << " " << finalLeftCol + 1 << " "
         << finalBottomRow + 1 << " " << finalRightCol + 1 << " "
         << maxsumall;

    // Giải phóng bộ nhớ đã cấp phát cho ma trận
    for (int i = 0; i < m; ++i) {
        delete[] a[i];  // Giải phóng các dòng
    }
    delete[] a;  // Giải phóng mảng con trỏ chính

    return 0;
}
