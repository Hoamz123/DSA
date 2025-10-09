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
    int n,m,k;cin >> n >> m >> k;
    vi row(n + 1,0),col(m + 1,0);
    FOR0(i,k){
        int x,y;cin >> x >> y;
        row[x] = 1;//hang x se co o den
        col[y] = 1;//tuong tu
    }
    ll ans = 1ll * n * m;
    int rowCurr = n;
    REP(i,1,n){
        if(row[i] == 0){
            //ko co o den
            ans -= m;
            rowCurr--;
        }
    }

    REP(i,1,m){
        if(col[i] == 0){
            //ko co o den
            ans -= rowCurr;
        }
    }
    cout << ans;
}
// https://luyencode.net/submission/1266368
int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}