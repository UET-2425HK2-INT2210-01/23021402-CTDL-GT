#include <iostream>
using namespace std;

int main() {
    int n, X;
    cin >> n >> X; // n là số vật, X là khối lượng tối đa

    int w[n + 1], v[n + 1];

    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i]; // nhập trọng lượng và giá trị từng vật
    }

    int dp[n + 1][X + 1];

    // Khởi tạo mảng dp toàn bộ bằng 0
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= X; ++j) {
            dp[i][j] = 0;
        }
    }

    // Quy hoạch động: tính giá trị lớn nhất
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= X; ++j) {
            dp[i][j] = dp[i - 1][j]; // không chọn vật i
            if (j >= w[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]); // chọn vật i nếu đủ chỗ
            }
        }
    }

    cout << dp[n][X] << endl; // In giá trị lớn nhất đạt được

    return 0;
}
