#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> tmp;

vector<vector<int>> ans;
void dfs(int u,int v){
    tmp.push_back(u);
    if(u == v){
        ans.push_back(tmp);
    }
    else{
        for(int i :adj[u]){
            dfs(i,v);
        }
    }
    tmp.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    adj = graph;
    int n = graph.size() - 1;
    dfs(0,n);
    return ans;
    //acc : medium
    //tim tat ca cac duong di tu 0 -> N-1
}