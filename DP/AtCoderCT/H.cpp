#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0);cin.tie(0);
#define mod 1000000007
int main(){
    FAST;
    int n,m;cin >> n >> m;
    vector<vector<char>> a(n+1,vector<char>(m+1,'a'));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin >> a[i][j];
    }
    vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
    f[1][1] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j] == '#') continue;
            else {
                f[i][j] =  (f[i][j] +  f[i-1][j] + f[i][j-1]) % mod;
                f[i][j] %= mod;
            }
        }
    }
    cout << f[n][m];
    //acc
}