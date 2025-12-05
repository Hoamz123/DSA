//on tap kiem tra do thi hai phia
#include<bits/stdc++.h>
using namespace std;

vector<int> adj[101];
vector<int> color(101,-1);
int n,m;
bool bfs(int u){
    queue<int> q;
    q.push(u);
    color[u] = 1;
    while(!q.empty()){
        int u = q.front();q.pop();
        for(int v : adj[u]){
            if(color[v] == -1){
                color[v] = 1 - color[u];
            }
            else if(color[v] == color[u]) return false;
        }
    }
    return true;
}

bool dfs(int u,int par){
    color[u] = 1 - color[par];
    for(int v : adj[u]){
        if(color[v] == -1){
            if(!dfs(v,u)) return false;
        }
        else if(color[v] == color[u]) return false;
    }
    return true;
}

int main(){
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    color[0] = 1;
    for(int i = 1;i<=n;i++){
        if(color[i] == -1){
            if(!dfs(i,0)){
                cout <<  "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
}