#include <iostream>
using namespace std;

// Cấu trúc biểu diễn 1 cạnh (u, v, w): nối từ u đến v với trọng số w
struct Edge {
    int u, v, w;
} edges[10001]; // Mảng lưu tối đa 10,000 cạnh

int parent[1001]; // Mảng cha dùng cho Union-Find

// Tìm đại diện của tập chứa đỉnh x (có nén đường đi)
int find(int x) {
    if (parent[x] != x) 
        parent[x] = find(parent[x]);
    return parent[x];
}

// Gộp hai tập chứa x và y
void unite(int x, int y) {
    parent[find(x)] = find(y);
}

// Hàm sắp xếp nhanh (QuickSort) các cạnh theo trọng số
void quickSort(int l, int r) {
    if (l >= r) return;
    int pivot = edges[(l + r) / 2].w;
    int i = l, j = r;
    while (i <= j) {
        while (edges[i].w < pivot) i++;
        while (edges[j].w > pivot) j--;
        if (i <= j) {
            swap(edges[i], edges[j]);
            i++; j--;
        }
    }
    quickSort(l, j);
    quickSort(i, r);
}

int main() {
    // Đọc dữ liệu từ file
    freopen("connection.txt", "r", stdin);
    freopen("connection.out", "w", stdout);
    
    int n, m; // n: số đỉnh, m: số cạnh
    cin >> n >> m;

    // Nhập m cạnh (u, v, w)
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // Khởi tạo Union-Find: mỗi đỉnh là cha của chính nó
    for (int i = 1; i <= n; i++) 
        parent[i] = i;

    // Sắp xếp tất cả các cạnh theo trọng số tăng dần
    quickSort(0, m - 1);

    int total = 0;                 // Tổng trọng số của cây khung
    int selected[10001], cnt = 0; // Mảng lưu chỉ số các cạnh được chọn vào MST

    // Duyệt từng cạnh theo thứ tự trọng số tăng
    for (int i = 0; i < m; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;

        // Nếu u và v thuộc hai tập khác nhau → chọn cạnh này
        if (find(u) != find(v)) {
            unite(u, v);           // Gộp hai tập lại
            total += w;            // Cộng trọng số vào tổng
            selected[cnt++] = i;   // Ghi nhận cạnh được chọn
        }
    }

    // In ra tổng trọng số của cây khung
    cout << total << endl;

    // In ra danh sách các cạnh thuộc cây khung nhỏ nhất
    for (int i = 0; i < cnt; i++) {
        int idx = selected[i];
        cout << edges[idx].u << " " << edges[idx].v << " " << edges[idx].w << endl;
    }

    return 0;
}
