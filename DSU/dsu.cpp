#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int parent[N];
int delta[N];       // giá trị chênh lệch giữa node và cha
int add_to_set[N];  // tổng cộng thêm của root tập hợp

// Khởi tạo ban đầu
void make_set(int v) {
    parent[v] = v;
    delta[v] = 0;
    add_to_set[v] = 0;
}

// Tìm gốc của tập chứa x, đồng thời cập nhật delta
int find(int x) {
    if (x == parent[x]) return x;
    int p = parent[x];
    parent[x] = find(p);
    delta[x] += delta[p];  // cập nhật delta theo cha
    return parent[x];
}

// Hợp hai tập lại (ghép ry vào rx)
void join(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx == ry) return;

    parent[ry] = rx;
    // hiệu chỉnh delta để duy trì đúng giá trị thực
    delta[ry] = add_to_set[ry] - add_to_set[rx];
}

// Cộng V vào toàn bộ tập chứa X
void add(int x, int v) {
    int r = find(x);
    add_to_set[r] += v;
}

// Trả về giá trị thực của đỉnh X
int get(int x) {
    find(x);  // đảm bảo delta[x] được cập nhật
    return delta[x] + add_to_set[parent[x]];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    // Khởi tạo
    for (int i = 1; i <= n; ++i)
        make_set(i);

    while (q--) {
        string cmd;
        int x, y;
        cin >> cmd >> x;
        if (cmd == "join") {
            cin >> y;
            join(x, y);
        } else if (cmd == "add") {
            cin >> y;
            add(x, y);
        } else if (cmd == "get") {
            cout << get(x) << '\n';
        }
    }
    return 0;
}
