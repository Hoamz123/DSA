#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005

int par[MAXN], sz[MAXN];
long long sumWeight[MAXN];
int weight[MAXN];

int find_set(int u) {
    if (u == par[u]) return u;
    return par[u] = find_set(par[u]);
}

void union_set(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u != v) {
        par[v] = u;
        sz[u] += sz[v];
        sumWeight[u] += sumWeight[v];
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    // Nhập trọng số các đỉnh
    for (int i = 1; i <= n; ++i) {
        cin >> weight[i];
        par[i] = i;
        sz[i] = 1;
        sumWeight[i] = weight[i];
    }

    // Nhập các cạnh
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        union_set(u, v);
    }

    // Tìm tập hợp có đúng k đỉnh và trọng số lớn nhất
    long long ans = -1;
    for (int i = 1; i <= n; ++i) {
        if (par[i] == i && sz[i] == k) {
            ans = max(ans, sumWeight[i]);
        }
    }

    if (ans == -1) cout << "No component of size " << k << endl;
    else cout << "Max weight of component with size " << k << " is: " << ans << endl;

    return 0;
}
