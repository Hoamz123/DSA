#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define nax 1000005
#define mod 1000000007
#define FAST ios::sync_with_stdio(0);cin.tie(0);
#define FOR1(i,n) for(int i=1;i<=(n);i++)
#define FOR(i,n) for(int i=0;i<=(n);i++)
int main(){
    FAST;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;cin >> n;
    vector<vector<char>> a(n+1,vector<char>(n+1,'a'));
    FOR1(i,n){
        FOR1(j,n) cin >> a[i][j];
    }
    vector<vector<int>>dp (n + 1, vector<int>(n + 1, 0));
    dp[1][1] = 1;
    FOR1(i,n){
        FOR1(j,n){
            if(a[i][j] == '.'){
                dp[i][j] = (dp[i][j] + dp[i-1][j] + dp[i][j-1]) % mod;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    cout << dp[n][n];
}