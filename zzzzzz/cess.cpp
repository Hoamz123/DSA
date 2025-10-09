#include<bits/stdc++.h>
using namespace std;
#define faster() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define umi unordered_map<int,int>
#define si set<int>
#define pb push_back
#define is insert
#define mod 1000000007
#define INF 1000000001
#define nax 1000005
#define FOR1(i, n) for (int i = 1; i <= (n); i++)
#define FOR0(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define PER(i, a, b) for (int i = a; i >= b; --i)
#define endl '\n'
#define fi first
#define se second

void solve(){
    int n;cin >> n;
    vi a(n);
    ll sum = 0;
    FOR0(i,n) {
        cin >> a[i];
        sum += a[i];
    }
    ll sumToggle = 0;//vi tri bit bat
    ll ans = 1ll * INF;
    for(int mask=1;mask < (1 << n);mask++){
        FOR0(j,n){
           if(((mask >> j) & 1)) sumToggle += a[j];
        }
        ans = min(ans,abs((sum - sumToggle) - sumToggle));
        sumToggle = 0;
    }
    cout << ans;
}

int main(){
    faster();
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}