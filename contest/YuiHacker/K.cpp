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
    string s,t;cin >> s >> t;
    int n = s.size();int m = t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));//dp[i][j] la xau con cung dai nhat tring i ki tu dau va j ki tu dau lan luot cua xau s t
    FOR1(i,n){
        FOR1(j,m){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout << dp[n][m];
}