#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
vector<int> adj[N];
int n, m;

int tin[N], low[N], timer = 0;
bool visited[N];
bool isCut[N];    // đánh dấu đỉnh khớp

void dfs(int u, int p){
    visited[u] = true;
    tin[u] = low[u] = ++timer;

    int child = 0;

    for(int v : adj[u]){
        if(v == p) continue;

        if(visited[v]){
            // cạnh ngược
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if(low[v] >= tin[u] && p != -1)
                isCut[u] = true;

            child++;
        }
    }

    // root đặc biệt: phải có >= 2 con
    if(p == -1 && child > 1)
        isCut[u] = true;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++)
        if(!visited[i]) dfs(i, -1);

    cout << "Articulation points:\n";
    for(int i = 1; i <= n; i++)
        if(isCut[i]) cout << i << " ";
}
