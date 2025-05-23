#include <iostream>
using namespace std;

const int MAXN = 1000;
int adj[MAXN][MAXN];   // Ma trận kề lưu các cạnh có hướng
bool visited[MAXN];    // Đánh dấu đỉnh đã được thăm
int dist[MAXN];        // Khoảng cách từ đỉnh bắt đầu đến đỉnh i

int queue[MAXN];       // Mảng giả lập hàng đợi BFS
int front = 0, back = 0;  // Con trỏ đầu và cuối hàng đợi

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;

    // Nhập dữ liệu cạnh (có hướng)
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
    }

    // Khởi tạo BFS
    visited[X] = true;   // Đánh dấu đỉnh xuất phát đã thăm
    dist[X] = 0;         // Khoảng cách đến đỉnh xuất phát là 0
    queue[back++] = X;   // Thêm đỉnh X vào hàng đợi

    // Thực hiện BFS
    while (front < back) {
        int u = queue[front++];  // Lấy đỉnh đầu hàng đợi

        // Duyệt tất cả đỉnh kề u
        for (int v = 1; v <= n; ++v) {
            if (adj[u][v] && !visited[v]) { // Nếu có cạnh và chưa thăm
                visited[v] = true;          // Đánh dấu đã thăm
                dist[v] = dist[u] + 1;      // Cập nhật khoảng cách
                queue[back++] = v;          // Thêm v vào hàng đợi
            }
        }
    }

    // In kết quả
    if (visited[Y]) cout << dist[Y] << endl;
    else cout << -1 << endl;   // Nếu không có đường đi thì in -1

    return 0;
}
