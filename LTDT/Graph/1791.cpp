#include<bits/stdc++.h>
using namespace std;

int findCenter(vector<vector<int>> &edges)
{
    int n = edges.size();
    vector<int> a(n+2,0);
    for(auto it : edges){
        int u = it[0];int v = it[1];
        a[u]++;
        a[v]++;
    }
    int res = -1e9;
    int ans = -1e9;
    for(int i = 1;i<=n+1;i++){
        if(a[i] > ans){
            ans = a[i];
            res = i;
        }
    }
    return res;
    //acc  :easy

    //toi uu
    //return (e[0][0] == e[1][0] || e[0][0] == e[1][1]) ? e[0][0] : e[0][1];
}

int main(){
    vector<vector<int>> v = {{1,2},{2,3},{4,2}};
    cout << findCenter(v);
}