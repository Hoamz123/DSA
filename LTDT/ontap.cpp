#include<bits/stdc++.h>
using namespace std;


//giai thuat kruskal tim cay khung nho nhat
struct edge{
    int u,v;
    int w;
};

// vector<edge> canh;
// vector<int> parent(101);
// vector<int> sz(101);
// int n,m;
// void make_set(){
//     for(int i = 1;i<=n;i++){
//         parent[i] = i;
//         sz[i] = 1;
//     }
// }

// int find(int v){
//     if(v == parent[v]) return v;
//     return parent[v] = find(parent[v]);
// }

// bool Union(int a,int b){
//     a = find(a);
//     b = find(b);
//     if(a == b) return false;
//     if(sz[a] < sz[b]) swap(a,b);
//     parent[b] = a;
//     sz[a] += sz[b];
//     return true;
// }

// bool cmp(edge a,edge b){
//     return a.w < b.w;
// }

// void kruskal(){
//     vector<edge> mst;
//     int ww = 0;
//     for(int i = 0;i<m;i++){
//         edge e = canh[i];
//         if(Union(e.u,e.v)){
//             mst.push_back(e);
//             ww += e.w;
//         }
//         if((int)mst.size() == n - 1) break;
//     }

//     if((int)mst.size() == n - 1){
//         for(auto it : mst){
//             cout << it.u << " " << it.v << " " << it.w << endl;
//         }
//         cout << ww << endl;
//     }
//     else cout << "!OK";
// }

// int main(){
//     cin >> n >> m;
//     for(int i = 0;i<m;i++){
//         edge e;cin >> e.u >> e.v >> e.w;
//         canh.push_back(e);
//     }
//     sort(canh.begin(),canh.end(),cmp);
//     make_set();
//     kruskal();
//     return 0;
// }

//giai thuat prim tim cay khung nho nhat

vector<pair<int,int>> adj[101];
int parent[101],d[101];
vector<int> used(101,0);
int n,m;

void prim(int u){
    priority_queue< pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > p;
    vector<edge> mst;
    int ww = 0;
    p.push({0,u});//day dinh u vao lam dinh bat dau -> 0 la trong so cua canh gia dinh
    while((int)mst.size() < n - 1){
        auto top = p.top();p.pop();
        int x = top.second;int w = top.first;
        if(used[x]) continue;
        if(u != x){
            mst.push_back({x,parent[x],w});
        }
        used[x] = 1;
        ww += w;

        for(auto it : adj[x]){
            int u = it.first;int w = it.second;
            if(!used[u] && w < d[u]){
                d[u] = w;
                parent[u] = x;
                p.push({d[u],u});
            }
        }
    }
    // = n - 1
    cout << endl;
    for(auto it : mst){
        cout<< it.u << " " << it.v << " " << it.w << endl;
    }
    cout << ww << endl;
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
    return 0;
}