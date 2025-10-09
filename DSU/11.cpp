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

vector<int> par,sz;
int n,m;

void make_set(){
    par.resize(n + 1);
    sz.assign(n+1,1);
    FOR1(i,n) par[i] = i;
}

int find_set(int u){
    return (u == par[u]) ? u : (par[u] = find_set(par[u]));
}

void Union(int a,int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        par[b] = a;
        sz[a] += sz[b];
    }
}

int get_size(int u){
    u = find_set(u);
    return sz[u];//kich co uca vung lien thong chua dinh u
}

void solve(){
    cin >> n >> m;
    make_set();
    vector<vi> adj(n + 1);
    FOR1(i,m){
        int u,v;cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> rem(n + 1);
    vector<int> vst(n + 1, 0);
    PER(i,n,1){
        cin >> rem[i];
    }
    vector<string> ans;
    ans.pb("YES");
    int cnt = 1;
    vst[rem[1]] = 1;
    REP(i,2,n){
        int u = rem[i];//them vao dinh u
        vst[u] = 1;
        cnt++;//them 1 dinh vao tap
        for(int v : adj[u]){
            if(vst[v]){
                //da them v vao tap hop
                Union(u,v);
            }
        }
        if(cnt == get_size(u)) ans.pb("YES");
        else ans.pb("NO");
    }
    for(int i=n-1;i>=0;i--) cout << ans[i] << "\n";
}

int main(){
    faster();
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}