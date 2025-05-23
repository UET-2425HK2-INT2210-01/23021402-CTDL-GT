#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

#define INF 10000000 // Giá trị đại diện cho "vô cực"

// Cấu trúc biểu diễn một cạnh của đồ thị có hướng với trọng số
struct Edge {
    int u, v, w; // Cạnh đi từ u -> v với trọng số w
    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

/*
 * Thuật toán Bellman-Ford: Tìm đường đi ngắn nhất từ đỉnh S đến các đỉnh còn lại.
 * Tham số:
 *  - n: số đỉnh
 *  - S: đỉnh xuất phát
 *  - e: danh sách các cạnh của đồ thị
 *  - D: mảng lưu khoảng cách ngắn nhất từ S đến mỗi đỉnh
 *  - trace: mảng lưu đỉnh liền trước để truy vết đường đi
 */
void bellmanFord(int n, int S, vector<Edge> &e, vector<int> &D, vector<int> &trace) {
    D[S] = 0; // Khoảng cách từ S đến chính nó là 0

    // Thực hiện n - 1 lần để đảm bảo cập nhật hết các đường đi ngắn nhất
    for (int i = 1; i < n; i++) {
        for (Edge edge : e) {
            int u = edge.u, v = edge.v, w = edge.w;

            // Nếu tìm được đường đi ngắn hơn thì cập nhật
            if (D[u] != INF && D[v] > D[u] + w) {
                D[v] = D[u] + w;
                trace[v] = u; // Ghi nhận đỉnh đi trước v trong đường đi ngắn nhất
            }
        }
    }
}

/*
 * Hàm truy vết lại đường đi từ đỉnh S đến đỉnh u dựa vào mảng trace.
 * Trả về vector chứa các đỉnh theo thứ tự từ S đến u.
 */
vector<int> path(vector<int> &trace, int S, int u) {
    if (u != S && trace[u] == -1) return vector<int>(); // Không có đường đi

    vector<int> path;
    while (u != -1) {
        path.push_back(u);  // Thêm đỉnh hiện tại vào đường đi
        u = trace[u];       // Quay lại đỉnh trước
    }

    reverse(path.begin(), path.end()); // Đảo ngược để có thứ tự đúng
    return path;
}

int main() {
    ifstream fin("dirty.txt");     // Mở file đầu vào
    ofstream fout("dirty.out");    // Mở file đầu ra

    int n, m, s, e; // n: số đỉnh, m: số cạnh, s: đỉnh xuất phát, e: đích đến
    fin >> n >> m >> s >> e;

    vector<Edge> edge; // Danh sách các cạnh

    // Đọc danh sách cạnh từ file
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        fin >> u >> v >> w;
        edge.emplace_back(u, v, w);
    }

    // === TASK 1: Tìm đường đi ngắn nhất từ s đến e ===
    vector<int> D(n + 1, INF);        // Mảng lưu khoảng cách từ s
    vector<int> trace(n + 1, -1);     // Mảng lưu vết (đỉnh đi trước)

    bellmanFord(n, s, edge, D, trace); // Gọi Bellman-Ford

    vector<int> p = path(trace, s, e); // Truy vết đường đi từ s đến e

    fout << D[e] << '\n';             // Ghi khoảng cách ngắn nhất từ s đến e
    for (int i : p) fout << i << " "; // Ghi đường đi ngắn nhất
    fout << endl;

    // === TASK 2: Tính khoảng cách từ mỗi đỉnh đến tất cả các đỉnh khác ===
    for (int i = 1; i <= n; i++) {
        vector<int> D(n + 1, INF);        // Khoảng cách từ đỉnh i
        vector<int> trace(n + 1, -1);     // Dùng lại mảng trace

        bellmanFord(n, i, edge, D, trace); // Tính khoảng cách từ i

        // In khoảng cách từ đỉnh i đến tất cả các đỉnh khác
        for (int j = 1; j <= n; j++) {
            fout << D[j] << " ";
        }
        fout << endl;
    }

    return 0;
}
