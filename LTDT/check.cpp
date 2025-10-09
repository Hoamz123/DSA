#include<bits/stdc++.h>
using namespace std;


struct edge{
    int w;
    int u,v;
};

vector<pair<int,int>> adj[101];
vector<int> used(1001,0);
int par[101],d[101];//d se luu gia ttrij trong so nho nhat cau ttaa ca cac duong den dinh i
int n,m;


void prim(int u){
    priority_queue <pair<int,int> ,vector<pair<int,int>> ,greater<pair<int,int>>> p;//luu first la w de min heap dinh nho nhat
    vector<edge> mst;
    int rs = 0;//tong torng so ket qua
    p.push({0,u});

    while(!p.empty()){
        auto top = p.top();p.pop();
        int x = top.second;
        int w = top.first;
        if(used[x]) continue;//da duyet roi thi bo qua
        rs += w;
        used[x] = 1;//danh dau da duyet qua
        if(u != x){
            mst.push_back({x,par[x],w});//p[x] - x : la 1 canh co trong so = w
        }
        
        for(auto it : adj[x]){
            int u = it.first;
            int w = it.second;
            if(!used[u] && w < d[u]){
                d[u] = w;
                p.push({d[u],u});
                par[u] = x;
            }
        }
    }
    cout << rs << endl;
    for(auto it : mst){
        cout << it.u << " " << it.v << " " << it.w << endl;
    }
}


int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v,w;cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(int i = 1;i<=n;i++) d[i] = 1e9;//trong so luc bat dau la lon nhat
    prim(1);
}