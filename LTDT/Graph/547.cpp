#include<bits/stdc++.h>
using namespace std;

//dem so thanh phan lien thong
vector<int> adj[101];
vector<int> vst;
void dfs(int u){
    vst[u] = 1;
    for(int v : adj[u]){
        if(!vst[v]){
            dfs(v);
        }
    }
}
//acc : medium

int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(isConnected[i][j]){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vst = vector<int>(n,0);
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(!vst[i]){
            dfs(i);
            cnt++;
        }
    }
    return cnt;
}