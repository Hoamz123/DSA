#include<bits/stdc++.h>
using namespace std;

//tim cac dinh tao thanh chu trinh
vector<int> vst(1001,0);
vector<int> pr(1001,-1);
vector<int> adj[1001];
set<int> road;

bool dfs(int u,int par){
    vst[u] = 1;
    for(int v : adj[u]){
        if(v == par) continue;
        if(vst[v]){
            while(u != v){
                road.insert(u);
                u = pr[u];
            }
            road.insert(v);
            return true;
        }
        pr[v] = u;
        if(dfs(v,u)) return true;
    }
    return false;
}
//acc  :chua toi uu

vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    int m = edges.size();
    int n = 0;
    for(int i = 0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
        n = max({u,v,n});
    }
    set<int> se;
    for(int i = 1;i<=n;i++){
        if(!vst[i]){
            if(dfs(i,-1)){
                se = road;
                break;
            }
        }
    }
    for(int i = m-1;i>=0;i--){
        int u = edges[i][0];
        int v = edges[i][1];
        if(se.count(u) > 0 && se.count(v) > 0){
            return {u,v};
        }
    }
    return {};
}
