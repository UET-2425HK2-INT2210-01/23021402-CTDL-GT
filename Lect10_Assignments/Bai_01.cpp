#include <iostream>
using namespace std;

const int MAXN = 1005;  // Số lượng đỉnh tối đa

int adj[MAXN][MAXN];    // Ma trận kề: adj[u][v] = 1 nếu có cạnh nối u và v
bool visited[MAXN];     // Đánh dấu các đỉnh đã được duyệt
int n, m;               // n: số đỉnh, m: số cạnh

// Hàm duyệt DFS từ đỉnh u để tìm tất cả các đỉnh liên thông với u
void dfs(int u) {
    visited[u] = true;  // Đánh dấu đỉnh u đã được duyệt

    // Duyệt qua tất cả các đỉnh v từ 1 đến n
    for (int v = 1; v <= n; ++v) {
        // Nếu có cạnh nối u và v và v chưa được duyệt
        if (adj[u][v] && !visited[v]) {
            dfs(v);  // Tiếp tục duyệt DFS từ đỉnh v
        }
    }
}

int main() {
    cin >> n >> m;  // Nhập số đỉnh và số cạnh

    // Nhập m cạnh và cập nhật vào ma trận kề
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x][y] = 1;
        adj[y][x] = 1;  // Vì đồ thị vô hướng nên cập nhật cả hai chiều
    }

    int components = 0;  // Biến đếm số thành phần liên thông

    // Duyệt qua tất cả các đỉnh
    for (int i = 1; i <= n; ++i) {
        // Nếu đỉnh i chưa được duyệt, đó là một thành phần liên thông mới
        if (!visited[i]) {
            dfs(i);        // Duyệt toàn bộ các đỉnh thuộc thành phần này
            components++;  // Tăng số lượng thành phần liên thông
        }
    }

    // In ra số thành phần liên thông của đồ thị
    cout << components << endl;

    return 0;
}

