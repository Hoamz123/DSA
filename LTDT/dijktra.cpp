#include<bits/stdc++.h>
using namespace std;

int n,m,s;
vector<pair<int,int>> adj[1001];
void dijkstra(int s){
    vector<int> d(1001,1e9);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > q;//min heap
    d[s] = 0;
    q.push({0,s});
    while(!q.empty()){
        //chon ra dinh co khoang cach tu s nho nhat
        auto it = q.top();q.pop();
        int u = it.second;//dinh
        int w = it.first;//khoang cach
        if(w > d[u]) continue;
        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                q.push({d[v],v});
            }
        }
    }
    for(int i = 1;i<=n;i++) cout << d[i] << " ";
}

int main(){
    cin >> n >> m >> s;
    for(int i=0;i<m;i++){
        int u,v,w;cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    dijkstra(s);
}


/*
6 8 1
1 2 7
1 3 12
2 3 2
2 4 9
3 5 10
4 6 1
5 4 4
5 6 5
*/


/*

*/