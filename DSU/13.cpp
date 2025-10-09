#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int n, q;
int root[MAXN], sz[MAXN], cur_comp;

struct edge {
    int u, v;
};

struct update {
    int node, old_size;
};

stack<update> rollback;
int total_rollback[MAXN << 2];
vector<edge> nw_edges[MAXN << 2];
vector<tuple<int, int, int>> queries;

int find(int x) {
    return (x == root[x] ? x : find(root[x]));
}

void Union(int id, int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);

    rollback.push({x, sz[x]});
    rollback.push({y, sz[y]});
    sz[x] += sz[y];
    root[y] = x;
    total_rollback[id] += 2;
}

void add_edge(int id, int l, int r, int L, int R, edge e) {
    if (l > R || r < L) return;
    if (L <= l && r <= R) {
        nw_edges[id].push_back(e);
        return;
    }
    int mid = (l + r) >> 1;
    add_edge(id << 1, l, mid, L, R, e);
    add_edge(id << 1 | 1, mid + 1, r, L, R, e);
}

map<pair<int, int>, vector<int>> active;

void get_ans(int id, int l, int r) {
    for (auto e : nw_edges[id]) {
        Union(id, e.u, e.v);
    }
    cur_comp -= (total_rollback[id] >> 1);

    if (l == r) {
        int t, u, v;
        tie(t, u, v) = queries[l];
        if (t == 3) {
            if (find(u) == find(v)) cout << 1;
            else cout << 0;
        }
    } else {
        int mid = (l + r) >> 1;
        get_ans(id << 1, l, mid);
        get_ans(id << 1 | 1, mid + 1, r);
    }

    cur_comp += (total_rollback[id] >> 1);
    while (total_rollback[id]) {
        update u = rollback.top(); rollback.pop();
        root[u.node] = u.node;
        sz[u.node] = u.old_size;
        total_rollback[id]--;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;

    queries.push_back({0, 0, 0}); // dummy để truy vấn từ 1
    for (int i = 1; i <= q; ++i) {
        int t, u, v;
        cin >> t >> u >> v;
        if (u > v) swap(u, v); // đảm bảo u < v để key trong map chuẩn
        queries.push_back({t, u, v});

        if (t == 1) {
            active[{u, v}].push_back(i);
        } else if (t == 2) {
            if (!active[{u, v}].empty()) {
                int start = active[{u, v}].back();
                active[{u, v}].pop_back();
                add_edge(1, 1, q, start, i - 1, {u, v});
            }
        }
    }

    for (auto &p : active) {
        for (int start : p.second) {
            add_edge(1, 1, q, start, q, {p.first.first, p.first.second});
        }
    }

    for (int i = 1; i <= n; ++i) {
        root[i] = i;
        sz[i] = 1;
    }
    cur_comp = n;

    get_ans(1, 1, q);
    cout << '\n';

    return 0;
}
