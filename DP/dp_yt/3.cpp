#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nax 1000005
#define FAST ios::sync_with_stdio(0);cin.tie(0);

int main(){
    FAST;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n,W;cin >> n >> W;
    vector<int> a(n+1);
    vector<int> val(n+1);
    for(int i=1;i<=n;i++){
        cin >> val[i] >> a[i];
    }
    /*
        // vector<int> dp(W+1,0);//dp[i] luu lai gia tri lon nhat dat duoc khi trong luong tui la i
    // vector<int> vet(W+1,-1);
    // dp[0] = 0;
    // for(int i=1;i<=n;i++){
    //     for(int j=W;j>=a[i];j--){
    //         if(dp[j] < dp[j - a[i]] + val[i]){
    //             dp[j] = dp[j - a[i]] + val[i];
    //             vet[j] = i;
    //         }

    //     }
    // }
    // cout << dp[W] << endl
    */
    vector<vector<int>> dp(n+1,vector<int>(W+1,0));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(j >= a[i]){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-a[i]] + val[i]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][W] << endl;
    vector<int> res;
    int i = n,j = W;
    while(i > 0 && j > 0){
        if(dp[i][j] == dp[i-1][j]) --i;
        else{
            res.push_back(i);
            j -= a[i];
            --i;
        }
    }
    for(int i : res) cout << i <<  " ";
}