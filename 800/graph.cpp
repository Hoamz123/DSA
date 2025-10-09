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

//A
/*
Problem A
void solve_A(){
    int n,k;cin >> n >> k;
    vi a(n + 2,0);
    for(int i=1;i<=n-1;i++) cin >> a[i];
    vi check(n + 5,0);
    int i = 1;
    while(true){
        check[i] = 1;
        int j = i + a[i];
        i = j;
        if(i >= n) break;
    }
    if(i == n) check[n] = 1;
    if(check[k]) cout << "YES\n";
    else cout << "NO\n";
    //acc
}*/

//B
/**
//Problem B
//neu co nhieu test thi menset lai sau moi test
vi adj[maxn];
vi vst(maxn,0),a(maxn,0);
int minCost = INF;

void dfs(int u){
    vst[u] = 1;
    minCost = min(minCost,a[u]);
    for(int v : adj[u]){
        if(!vst[v]) dfs(v);
    }
}

void solve_B(){
    int n,p;cin >> n >> p;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=0;i<p;i++){
        int u,v;cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll total = 0;
    REP(i,1,n){
        if(!vst[i]){
            minCost = INF;
            dfs(i);
            total += minCost;
        }
    }
    cout << total << endl;
}**/

//C
/*
//Problem C
vi vst;
vi par(maxn,0);
vi sz(maxn,0);
int n;

void make_set(){
    REP(i,1,n) {
        par[i] = i;
        sz[i] = 1;
    }
}

int findRoot(int u){
    return (u == par[u]) ? u : (u = findRoot(par[u]));
}

void Union(int u,int v){
    u = findRoot(u);
    v = findRoot(v);
    if(u == v) return;
    //Union 2 group
    if(sz[u] < sz[v]) swap(u,v);
    par[v] = u;
    sz[u] += sz[v];
}

void solve_C(){
    int m;cin >> n >> m;
    make_set();
    REP(i,1,m){
        int size;cin >> size;
        if(size == 0) continue;
        int p;cin >> p;
        REP(j,1,size - 1){
            int v;cin >> v;
            Union(p,v);
        }
    }
    vi res(n + 1,0);
    REP(i,1,n){
        int parI = findRoot(i);
        res[i] = sz[parI];
    }
    REP(i,1,n) cout << res[i] << ' ';
    //acc
}
*/

//D
/*
vi adj[maxn];
vi par(maxn,0),color(maxn,-2);

bool dfs(int u,int par){
    color[u] = 1 - color[par];
    for(int v : adj[u]){
        if(color[v] == -1){
            if(!dfs(v,u)) return false;
        }
        else if(color[v] == color[u]) return false;
    }
    return true;
}

void solve_D(){
    int n,m;cin >> n >> m;
    REP(i,1,m){
        int u,v;cin >> u >> v;
        color[u] = color[v] = -1;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bool check = 1;
    color[0] = 1;
    REP(i,1,n){
        if(color[i] == -1){
            if(!dfs(i,0)){
                check = 0;
            }
        }
    }
    if(check == 0) cout << -1;
    else{
        vi a,b;
        REP(i,1,n){
            if(color[i] == 1) a.pb(i);
            else if(color[i] == 0) b.pb(i);
        }
        cout << (int)a.size() << endl;
        for(int i : a) cout << i << ' ';
        cout << endl << (int)b.size() << endl;
        for(int i : b) cout << i << ' ';
    }
    //acc
}

*/

//E
/*
vi adj[maxn];
vi vst(maxn,0);

void dfs(int u,vi &x,ll &cnt){
    x.pb(u);
    vst[u] = 1;
    for(int v : adj[u]){
        cnt++;
        if(!vst[v]) {
            dfs(v,x,cnt);
        }
    }
}
void solve_E(){
    int n,m;cin >> n >> m;
    REP(i,1,m){
        int u,v;cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    REP(i,1,n){
        vi x;
        ll cnt = 0;
        if(!vst[i]){
            dfs(i,x,cnt);
        }
        ll edges = cnt / 2;
        ll s = x.size();
        if(edges != 1ll * s * (s - 1) / 2){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}*/

//F

string s;
ll n,m;
vll adj[maxn];
vll ind(maxn,0),tp(maxn,0);
queue<int> q;
vll dp(maxn,0);

void solve_F(){
    cin >> n >> m >> s;
    s = "#" + s;
    for(int i=0;i<m;i++){
        int u,v;cin >> u >> v;
        adj[u].pb(v);
        ind[v]++;
    }
    ll cnt = 0;
    REP(i,1,n){
        if(ind[i] == 0) q.push(i);
    }
    while(!q.empty()){
        cnt++;
        int u = q.front();q.pop();
        tp.pb(u);
        for(int v : adj[u]){
            ind[v]--;
            if(ind[v] == 0) q.push(v);
        }
    }
    if(cnt < n) cout << -1;
    else{
       ll ans = 0;
        for(char it = 'a';it <= 'z';it++){
            dp = vll(maxn,0);
            for(ll x : tp){
                if(s[x] == it) dp[x]++;
                for(ll y : adj[x]){
                    dp[y] = max(dp[y],dp[x]);
                }
                ans = max(ans,dp[x]);
            }
        }
        cout << ans << endl;
    }
}


int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    solve_F();
}