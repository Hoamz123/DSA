#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    //do dai 1 chon luon phan tu do
    for(int i=0;i<n;i++){
        dp[i][i] = a[i];
    }
    //do dai 2 tro nen
    for(int len = 2;len <= n;len ++){
        for(int i=0;i<n - len + 1;i++){
            int j = i + len - 1;
            dp[i][j] = max(a[i] - dp[i+1][j],a[j] - dp[i][j-1]);
        }
    }
    cout << dp[0][n-1];
}