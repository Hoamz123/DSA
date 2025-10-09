#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u,v,w;
};

vector<edge> canh;
vector<int> used(101,0);
vector<int> parent(101,0);
vector<int> sz(101,0);
int n,m;

void make_set(){
    for(int i = 1;i<=n;i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int v){
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

bool Union(int a,int b){
    a = find(a);
    b = find(b);
    if(a == b) return false;
    if(sz[a] < sz[b]) swap(a,b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

void kruskal(){
    vector<edge> mst;
    int d = 0;
    for(int i = 0;i<m;i++){
        edge e = canh[i];
        if(Union(e.u,e.v)){
            mst.push_back(e);
            d += e.w;
        }
        if((int)mst.size() == n - 1) break;
    }
    cout << d << endl;
    for(auto it : mst){
        cout << it.u << " " << it.v << " " << it.w << endl;
    }
}

bool cmp(edge a,edge b){
    return a.w < b.w;
}

int main(){
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        edge e;
        cin >> e.u >> e.v >> e.w;
        canh.push_back(e);
    }
    sort(canh.begin(),canh.end(),cmp);
    make_set();
    kruskal();
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
5 6 8*/
