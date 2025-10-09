#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,W;cin >> n >> W;
    vector<int> w(n+1,0);
    vector<int> val(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> w[i] >> val[i];
    }
    // vector<vector<int>> f(n+1,vector<int>(W+1,0));
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=W;j++){
    //         if(w[i] <= j){
    //             f[i][j] = max(f[i-1][j],f[i-1][j - w[i]] + val[i]);
    //         }
    //         else{
    //             f[i][j] = f[i-1][j];
    //         }
    //     }
    // }
    // cout << f[n][W];
    vector<ll>f(W+1,0);
    for(int i=1;i<=n;i++){
        for(int j = W;j>=w[i];j--){
            f[j] = max(f[j],f[j-w[i]] + val[i]);
        }
    }
    cout << f[W];
}