#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nax 1000005
#define FAST ios::sync_with_stdio(0);cin.tie(0);

int main(){
    FAST;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string s,t;cin >> s >> t;
    int n = s.size();int m = t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0)); //dp[i][j] la do dai xau con chung dai nhat trong i phan tu dau cua s va j phan tu dau cua t
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout << dp[n][m] << endl;//do dai xau con dainhat
    int i = n,j = m;
    string ans = "";
    while(i > 0 && j > 0){
        if(s[i-1] == t[j-1]){
            ans = s[i-1] + ans;
            cout << "i : j " << i << " " << j << endl;
            --i;--j;
        }
        else if(dp[i-1][j] > dp[i][j-1]) --i;
        else --j;
    }
    cout << ans;
}
    