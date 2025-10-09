//kiem tra chu trinh trong do thi co huong
#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[101];
vector<int> used(101,0);

bool dfs(int u,int par){
    used[u] = 1;
    for(int v : adj[u]){
        if(!used[v]){
            if(dfs(v,u)) return true;
        }
        else if(v != par) return true;
    }
    return false;
}
int parent[1001]  = {0};
bool bfs(int u){
    used[u] = 1;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int u = q.front();q.pop();
        for(int v : adj[u]){
            if(!used[v]){
                used[v] = 1;
                parent[v] = u;
                q.push(v);
            }
            else if(v != parent[u]) return true;
        }
    }
    return false;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(bfs(i)){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}