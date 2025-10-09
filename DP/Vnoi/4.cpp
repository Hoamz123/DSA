#include<bits/stdc++.h>
using namespace std;
#define INF -1e9
int grid[1005][1005];
int dp[1005][1005];
int main(){
    int m,n;cin >> m >> n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin >> grid[i][j];
        }
    }
    for(int i=0;i<=n;i++){
        dp[0][i] = -1e10;
        dp[m+1][i] = -1e10;
    }

    for(int i=1;i<=m;i++){
        dp[i][1] = grid[i][1];
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[j][i] = max({dp[j-1][i-1],dp[j][i-1],dp[j+1][i-1]}) + grid[j][i];
        }
    }
    
    int res = -1e10;
    for(int i=1;i<=m;i++){
        res = max(res,dp[i][n]);
    }
    cout << res;
    //acc
}

/*
https://oj.vnoi.info/problem/qbmax
*/