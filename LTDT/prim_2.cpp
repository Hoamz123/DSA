#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u,v;
    int w;
};

vector<pair<int,int>> adj[101];
vector<int> used(101,0);
int parent[101],d[101];
int n,m;

void prim(int u){
    priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > p;//trong so nho nhat tu dinh x den cay khung dang xayxay
    vector<edge> mst;
    int res = 0;
    p.push({0,u});

    while(!p.empty()){
        auto top = p.top();p.pop();
        int x = top.second;
        int w = top.first;
        if(used[x]) continue;
        res += w;
        used[x] = 1;
        if(u != x){
            mst.push_back({x,parent[x],w});
        }
        for(auto it : adj[x]){
            int y = it.first;
            int w = it.second;
            if(!used[y] && w < d[y]){
                d[y] = w;
                p.push({d[y],y});
                parent[y] = x;
            }
        }
    }

    cout << res << endl;
    for(auto it : mst){
        cout << it.u << " " << it.v << " " << it.w << endl;
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int u,v,w;cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(int i = 1;i<=n;i++) d[i] = 1e9;
    prim(1);
}

/*
6 9
1 2 12
1 3 4
2 3 1
2 4 5
2 5 3
3 5 2
4 5 3
4 6 10
5 6 8
 */
