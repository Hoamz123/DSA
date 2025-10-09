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
#define INF 1000000000007
#define nax 1000005
#define FOR1(i, n) for (int i = 1; i <= (n); i++)
#define FOR0(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define PER(i, a, b) for (int i = a; i >= b; --i)
#define endl '\n'
#define fi first
#define se second

void solve(){
    int n,k,p;
    cin >> n >> k >> p;
    vi a(n),b(k);
    FOR0(i,n) cin >> a[i];
    FOR0(i,k) cin >> b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<vector<ll>> dp(k+1,vector<ll>(n+1,INF));//tg toi thieu de i chia khao dau tien dc giao cho j nguoi dau tien
    dp[0][0] = 0;

    FOR0(i,k){
        FOR0(j,n+1){
            dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
            if(j < n){
                dp[i+1][j+1] = min(dp[i+1][j+1],max(dp[i][j],1ll * (abs(a[j] - b[i]) + abs(b[i] - p))));
            }
        }
    }
    cout << dp[k][n];
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}