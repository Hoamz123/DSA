#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
vector<int> adj[N];
int n, m;

int timer = 0;
int tin[N], low[N];
bool visited[N];

vector<pair<int,int>> bridges;//luu lai canh cau

void dfs(int u, int p){
    visited[u] = true;
    tin[u] = low[u] = ++timer;

    for(int v : adj[u]){
        if(v == p) continue;//bo qua nhung dinh cha truc tiep

        if(visited[v]){
            // cạnh ngược
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if(low[v] > tin[u]){
                bridges.push_back({u, v}); // (u, v) là cầu
            }
        }
    }
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

    // output
    cout << "Bridges:\n";
    for(auto &e : bridges)
        cout << e.first << " " << e.second << "\n";
}
