#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll res = 0;
    unordered_map<ll,ll> mp;
    int n;cin >> n;
    for(int i=0;i<n;i++){
        ll x;cin >> x;
        res += mp[x];
        res %= mod;
        mp[x]++;
    }
    cout << res;
    //acc
}