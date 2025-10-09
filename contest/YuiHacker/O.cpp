#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nax 1000005
#define mod 1000000007
#define M -1000000001
#define FAST ios::sync_with_stdio(0);cin.tie(0);
#define FOR1(i,n) for(int i=1;i<=(n);i++)
#define FOR(i,n) for(int i=0;i<=(n);i++)
int main(){
    FAST;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n,m;cin >> n >> m;
    vector<vector<int>> a(n+1,vector<int>(m+1,0));
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    FOR1(i,n)FOR1(j,m) cin >> a[i][j];
    int ans = 0;
    int cnt = 0;
    FOR1(i,n){
        FOR1(j,m){
            if(a[i][j] == 0) continue;
            else{
                dp[i][j] = min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]}) + 1;
            }
            if(dp[i][j] > ans){
                ans = dp[i][j];
                cnt=0;
                cnt++;
            }
            else if(dp[i][j] == ans){
                cnt++;
            }
        }
    }
    cout << ans << " " << cnt;
}