#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

vector<int> adj[N];
int n, m;

int timer = 0;
int tin[N], low[N];
bool visited[N];

stack<pair<int,int>> st;          // lưu cạnh trong DFS
vector<vector<int>> cycles;       // lưu chu trình đã tìm được

void extract_cycle(int u, int v){
    // lấy các cạnh trong stack cho đến khi gặp (u, v)
    vector<pair<int,int>> edges;
    while(!st.empty()){
        auto e = st.top(); st.pop();
        edges.push_back(e);
        if((e.first == u && e.second == v) ||
           (e.first == v && e.second == u))
            break;
    }

    // gom các đỉnh lại thành 1 chu trình
    set<int> nodes;
    for(auto &e : edges){
        nodes.insert(e.first);
        nodes.insert(e.second);
    }

    if(nodes.size() >= 3){ // >=3 đỉnh mới thành chu trình
        vector<int> cycle(nodes.begin(), nodes.end());
        cycles.push_back(cycle);
    }
}

void dfs(int u, int p){
    visited[u] = true;
    tin[u] = low[u] = ++timer;

    for(int v : adj[u]){
        if(v == p) continue;

        if(!visited[v]){
            st.push({u, v});
            dfs(v, u);

            low[u] = min(low[u], low[v]);

            if(low[v] >= tin[u]){
                extract_cycle(u, v);
            }
        }
        else if(tin[v] < tin[u]){
            // cạnh ngược
            st.push({u, v});
            low[u] = min(low[u], tin[v]);
        }
    }
}


bool cmd(vector<int> &a,vector<int> &b){
    return (int)a.size() > (int)b.size();
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i])
            dfs(i, -1);
    }

    
    sort(cycles.begin(),cycles.end(),cmd);

    vector<int> res = cycles[0];

    cout << (int)res.size() << endl;

    for(int x : res) cout << x << ' ';
}
