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
#define ull unsigned long long
#define maxn 1000005
#define FOR1(i, n) for (int i = 1; i <= (n); i++)
#define FOR0(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define PER(i, a, b) for (int i = a; i >= b; --i)
#define endl '\n'

void solve(){
    int n,x;cin >> n >> x;
    vi a;
    a.pb(0);
    FOR1(i,n){
        int u;cin >> u;
        a.pb(u);
    }
    a.pb(x);
    int ans = -INF;
    //dung tich bin xang nho nhat de thoa man chinh la khoang cach lon nhat giua hai cham sang
    n = a.size();
    for(int i=1;i<n;i++){
        if(i == n - 1){
            ans = max(ans,2*(a[i] - a[i-1]));
        }
        else ans = max(ans,a[i] - a[i-1]);
    }
    cout << ans << '\n';
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;cin >> t;
    while(t--){
        solve();
    }
}