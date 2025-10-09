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

int n,m;
vector<int> vst;
vector<int> adj[1001];

void bfs(int u){
    vst[u] = 1;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int u = q.front();q.pop();
        for(int v : adj[u]){
            if(vst[v] == 0){
                vst[v] = 1;
                q.push(v);
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    vst = vector<int>(n + 1,0);
    FOR1(i,m){
        int u,v;cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bfs(1);
    FOR1(i,n){
        if(vst[i] == 0){
            cout << i << '\n';
        }
    }
}
// https://www.spoj.com/PTIT/problems/BCDAISY/
int main(){
    faster();
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}