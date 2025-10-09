#include<bits/stdc++.h>
using namespace std;
#define faster() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define umii unordered_map<int,int>
#define si set<int>
#define pb push_back
#define is insert
#define mod 1000000007
#define INF 1000000001
#define nax 1000005
#define FOR1(i,n) for(int i=1;i<=(n);i++)
#define FOR0(i,n) for(int i=0;i<(n);i++)
#define forxy(i,x,y) for(int i=(x);i<(y);i++);
#define endl '\n'

void solve() {
    int n;cin >> n;
    vi a(n),b(n);
    FOR0(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    FOR0(i,n) cin >> b[i];
    sort(b.begin(), b.end());
    int i=0,j = n-1;
    ll ans = 0;
    while(i < n && j > -1){
        ans += 1ll * max(a[i],b[j]);
        i++;
        j--;
    }
    cout << ans << endl;
    //acc
}


int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    //bu bai de vai lon
}
