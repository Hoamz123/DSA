
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nax 1000005
#define FAST ios::sync_with_stdio(0);cin.tie(0);

int main(){
    FAST;
    int n,k;cin >> n >> k;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    ll ans = 0;
    vector<ll> d(n);//d[i] = a[i]  - i*k
    for(int i=0;i<n;i++){
        d[i] = a[i] - i*k;
    }
    sort(d.begin(),d.end());
    int mid = d[n/2];
    if(mid < 1) mid = 1;
    for(int i=0;i<n;i++){
        ans += abs(a[i] - mid  - 1ll * i*k);
    }
    cout << ans;
}