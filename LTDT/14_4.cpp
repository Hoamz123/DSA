#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u,v,w;
};

vector<pair<int,int>> adj[1001];
vector<int> used(1001,0);
int parent[1001],d[1001];
int n,m;


void prim(int u){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    vector<edge> mst;
    int res = 0;
    q.push({0,u});
    while(!q.empty()){
        auto top = q.top();q.pop();
        int x = top.second;
        int w = top.first;
        if(used[x]) continue;///da thuoc mst
        res += w;
        used[x] = 1;
        if(x != u){
            mst.push_back({x,parent[x],w});
        }
        for(auto it : adj[x]){
            int y = it.first;
            int w = it.second;
            if(!used[y] && w < d[y]){
                d[y] = w;
                q.push({d[y],y});
                parent[y] = x;
            }
        }
    }
    cout << res << endl;
    for(auto it : mst) cout << it.u << " " << it.v << " " << it.w << endl;
}


int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v,w;cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++) d[i] = 1e9;
    prim(1);
}