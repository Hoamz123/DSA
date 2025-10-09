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
int n,m;
vector<pii> adj[maxn];
vi vst(maxn,0),d(maxn,INF),par(maxn,0);
struct ed{
    int u,v,w;
};

void prim(int s){
    priority_queue<pii,vector<pii>, greater<pii>> q;
    vector<ed> ans;
    int res = 0;
    q.push(make_pair(0,s));
    while(!q.empty()){
        auto [w,u] = q.top();q.pop();
        if(vst[u]) continue;
        res += w;
        vst[u] = 1;
        if(u != s) ans.pb({u,par[u],w});
        for(auto [v,ww] : adj[u]){
            if(!vst[v] && ww < d[v]){
                d[v] = ww;
                par[v] = u;
                q.push(make_pair(d[v],v));
            }
        }
    }
    cout << "RESULT\n";
    cout << res << endl;
    for(auto [u,v,w] : ans) cout << u << ' ' << v << ' ' << w << endl;

}

void solve(){
    cin >> n >> m;
    REP(i,1,m){
        int u,v,w;cin >> u >> v >> w;
        adj[u].pb(make_pair(v,w));
        adj[v].pb(make_pair(u,w));
    }
    prim(1);
}

int main(){
    faster();
    solve();
}