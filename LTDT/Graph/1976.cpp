#include<bits/stdc++.h>
using namespace std;

#define ll long long
int n,m;
vector<pair<int,int>> adj[1001];

int countPaths(int n, vector<vector<int>> &roads)
{
    for(auto it : roads){
        int u = it[0];int v = it[1];int w = it[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int mod=  1e9 + 7;
    vector<ll> d(1001,LLONG_MAX);//tong trong so cua duong di ngan nhat -> u;
    vector<ll> ways(1001,0);//so duong di
    priority_queue<pair<ll,int> ,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
    q.push({0,0});//bat dau di tu dinh 0
    d[0] = 0;//tong trong so tuu 0->0 = 0
    ways[0] = 1;//bat dau co 1 cach -> 0
    while(!q.empty()){
        auto it = q.top();q.pop();
        ll w = it.first;
        int u = it.second;
        if(w > d[u]) continue;

        for(auto it : adj[u]){
            int v = it.first;ll w = it.second;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                ways[v] = ways[u];
                q.push({d[v],v});
            }
            else if(d[v] == d[u] + w){
                ways[v] = (ways[v] + ways[u]) % mod;
            }
        }
    }
    return ways[n-1];//acc
}