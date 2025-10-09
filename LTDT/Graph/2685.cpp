#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> used;
    vector<int> adj[1001];
    int k,c;
    void dfs(int u){
        used[u] = 1;
        k++;
        for(int v : adj[u]){
            c++;
            if(!used[v]){
                dfs(v);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        used = vector<int> (1001,0);
        for(auto it : edges){
            int u = it[0];int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int res = 0;
        for(int i = 0;i<n;i++){
            if(!used[i]){
                k = 0;c = 0;
                dfs(i);
                c/=2;//dem 2 lan cho 1 canh
                if(c == k*(k-1)/2) res++;
            }
        }
        return res;
    }
    /**
     * 1 do thi ma tat ca cac canhj deu co the den dc nhau k dinh -> xo k*(K-1) / 2 canh
     */
    //acc
};