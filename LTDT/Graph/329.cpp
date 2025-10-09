#include<bits/stdc++.h>
using namespace std;


int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int n,m;
vector<vector<int>> dp;
int dfs(int i,int j,vector<vector<int>> &matrix){//khong thay đoi gia tri cua matrix -> dung & -> do ton time sao chep
    if(dp[i][j] != -1) return dp[i][j];
    dp[i][j] = 1;//it nhat la chinh no
    for(int k=0;k<4;k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && matrix[i1][j1] > matrix[i][j]){
            dp[i][j] = max(dp[i][j],1 + dfs(i1,j1,matrix));
        }
    }
    return dp[i][j];
    //acc : hard
}

//tinh do dai dai nhat tang dan tu o i,j bat ky

int longestIncreasingPath(vector<vector<int>> &matrix){
    n = matrix.size();
    m = matrix[0].size();
    int ans = -1e9;
    dp = vector<vector<int>> (n,vector<int>(m,-1));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            ans = max(ans,dfs(i,j,matrix));
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> v = {{9,9,4},{6,6,8},{2,1,1}};
    cout << longestIncreasingPath(v);
}