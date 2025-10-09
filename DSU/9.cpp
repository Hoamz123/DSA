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

vector<ll> a,par,sz;
ll cnt = 0;
ll ans = -INF;
int n,m;
void make_U(){
    a.resize(n + 1, 0);
    par.resize(n + 1, 0);
    sz.resize(n + 1, 0);
    FOR1(i,n){
        par[i] = i;
        sz[i] = 1;
    }
    cnt = n;
}

int find_root(int u){
    return (u == par[u]) ? u : (par[u] = find_root(par[u]));
}

void Union(int a,int b){
    a = find_root(a);
    b = find_root(b);
    if(a != b){
        par[b] = a;
        sz[a] += sz[b];
        ans = max(ans,sz[a]);
        cnt--;
    }
}

void solve(){
    cin >> n >> m;
    make_U();
    while(m--){
        int a,b;cin >> a >> b;
        Union(a,b);
        cout << cnt << ' ' << ans << endl;
    }
}

int main(){
    faster();
    int t = 1;
    while(t--){
        solve();
    }
}

/*acc*/
// https://cses.fi/problemset/task/1676