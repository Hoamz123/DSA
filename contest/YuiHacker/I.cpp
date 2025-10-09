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
    int n;cin >> n;
    vector<ll> a(nax,0);
    FOR1(i,n) cin >> a[i];
    ll sum = 0;
    ll ans = M;
    FOR1(i,n){
        sum += a[i];
        ans = max(ans,sum);
        if(sum < 0) sum = 0;
    }
    cout << ans;
}