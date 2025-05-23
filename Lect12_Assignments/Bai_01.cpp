#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1001;              // Số lượng công việc tối đa
vector<int> adj[MAXN];              // Danh sách kề: adj[u] chứa các công việc phải làm sau khi làm xong u
bool visited[MAXN];                 // Mảng đánh dấu đỉnh đã được thăm trong DFS
vector<int> result;                 // Mảng lưu kết quả thứ tự công việc theo sắp xếp tô-pô
int n;                              // Số lượng công việc

// Hàm thực hiện DFS từ đỉnh u
void dfs(int u) {
    visited[u] = true;              // Đánh dấu u đã được thăm

    // Duyệt các đỉnh kề với u (các công việc phải làm sau u)
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);                 // Gọi đệ quy nếu chưa thăm
        }
    }

    result.push_back(u);            // Thêm u vào kết quả (sau khi xử lý xong các đỉnh kề)
}

int main() {
    int m;                          // Số lượng ràng buộc (cạnh)
    cin >> n >> m;                  // Nhập số công việc và số ràng buộc

    // Khởi tạo danh sách kề và visited
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        visited[i] = false;
    }

    // Nhập m ràng buộc: u phải làm trước v
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);        // Thêm cung u → v
    }

    // Chạy DFS từ mỗi đỉnh chưa thăm
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Đảo ngược kết quả vì DFS thêm đỉnh sau khi thăm xong
    reverse(result.begin(), result.end());

    // In ra thứ tự công việc hợp lệ
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
