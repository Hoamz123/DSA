#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXQ = 100005;

struct edge {
    int u, v;
};

struct update {
    int node, old_size;
};

int n, q;
int sz[MAXN], root[MAXN], answer[MAXQ];
int total_rollback[MAXQ << 2];
stack<update> rollback;
vector<edge> nw_edges[MAXQ << 2];

int cur_comp;

int rt(int x) {
    return (x == root[x] ? x : rt(root[x]));
}

void Union(int id, int x, int y) {
    x = rt(x);
    y = rt(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);

    rollback.push({x,sz[x]});

    rollback.push({y,sz[y]});

    total_rollback[id] += 2;
    sz[x] += sz[y];
    root[y] = x;
}

void upd(int id, int l, int r, int L, int R, edge cur_edge) {
    if (l > R || r < L) return;
    if (l >= L && r <= R) {
        nw_edges[id].push_back(cur_edge);
        return;
    }
    int mid = (l + r) >> 1;
    upd(id * 2 , l, mid, L, R, cur_edge);
    upd(id * 2 + 1, mid + 1, r, L, R, cur_edge);
}

void get_ans(int id, int l, int r) {
    for (int i = 0; i < (int)nw_edges[id].size(); ++i) {
        Union(id, nw_edges[id][i].u, nw_edges[id][i].v);
    }

    cur_comp -= (total_rollback[id] / 2);
    if (l == r) {
        answer[l] = cur_comp;
    } else {
        int mid = (l + r) >> 1;
        get_ans(id * 2, l, mid);
        get_ans(id * 2 + 1, mid + 1, r);
    }

    cur_comp += (total_rollback[id] >> 1);
    while (total_rollback[id]) {
        update u;
        u = rollback.top();
        rollback.pop();
        root[u.node] = u.node;
        sz[u.node] = u.old_size;
        total_rollback[id]--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        root[i] = i;
        sz[i] = 1;
    }
    cur_comp = n;

    for (int i = 1; i <= q; ++i) {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        edge e;
        e.u = u;
        e.v = v;
        upd(1, 1, q, l, r, e);
    }

    get_ans(1, 1, q);

    for (int i = 1; i <= q; ++i) {
        cout << answer[i] << '\n';
    }
    return 0;
}
