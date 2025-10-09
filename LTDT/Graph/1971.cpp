#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> used;

void dfs(int u){
    used[u] = 1;
    for(int v : adj[u]){
        if(!used[v]){
            dfs(v);
        }
    }
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    used[u] = 1;
    while(!q.empty()){
        int v = q.front();q.pop();
        for(int x  :adj[v]){
            if(!used[x]){
                q.push(x);
                used[x] = 1;
            }
        }
    }
}

bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    used = vector<int>(n,0);
    adj = vector<vector<int>> (n,vector<int>() );//nho cap phat vector
    for(auto it : edges){
        int u = it[0];int v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(source);
    if(used[destination]) return true;
    return false;
    //acc  :easy
}


int main(){
    vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    cout << validPath(3,edges,0,2);
}