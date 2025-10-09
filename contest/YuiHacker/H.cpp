#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nax 1000005
#define mod 1000000007
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
    vector<ll> fre(nax,0);
    FOR1(i,n) fre[i] = fre[i-1] + a[i];
    int t;cin >> t;
    while(t--){
        int l,r;cin >> l >> r;
        cout << fre[r] - fre[l-1] << endl;
    }
}