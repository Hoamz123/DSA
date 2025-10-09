#include<bits/stdc++.h>
using namespace std;
#define INF 1e18 + 1
#define ll long long
//knapsack : nhung W len den 1e9

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,W,h;cin >> n >> W >> h;
    W += h;
    vector<int> w(n+1,0);
    vector<int> v(n+1,0);
    int totalVal = 0;
    for(int i=1;i<=n;i++){
        cin >> w[i] >> v[i];
        totalVal += v[i];
    }
    vector<ll> f(totalVal + 1,INF);
    f[0] = 0;
    //f[i] : luu lai khoi luong nho nhat thoa man = gia tri i
    for(int i=1;i<=n;i++){
        for(int j=totalVal;j >= v[i];j--){
            f[j] = min(f[j],f[j - v[i]] + w[i]);
        }
    }
    ll ans = 0;
    for(int i=0;i<=totalVal;i++){
        if(f[i] <= W){
            ans = max(ans,(ll)i);
        }
    }
    cout << ans;
}