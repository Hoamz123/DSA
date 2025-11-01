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

// int n,m,s;
// vector<pii> adj[maxn];
// vi d(maxn,INF);
// void dik(int s){
//     priority_queue<pii,vector<pii>,greater<pii>> q;
//     d[s] = 0;
//     q.push(make_pair(0,s));
//     while(!q.empty()){
//         auto &[w,u] = q.top();q.pop();
//         if(d[u] < w) continue;
//         for(auto &[w,v] : adj[u]){
//             if(d[v] > d[u] + w){
//                 d[v] = d[u] + w;
//                 q.push(make_pair(d[v],v));
//             }
//         }
//     }
//     REP(i,1,n) cout << d[i] << ' ';
// }
// void solve(){
//     cin >> n >> m >> s;
//     REP(i,1,m){
//         int u,v,w;cin >> u >> v >> w;
//         adj[u].pb(make_pair(w,v));
//     }
//     dik(s);
// }

// struct edge{
//     int u,v,w;
// };
// vector<edge> adj;
// int n,m;
// vi par(maxn);
// int findRoot(int u){
//     return (u == par[u]) ? u : (par[u] = findRoot(par[u]));
// }
// bool Union(int a,int b){
//     a = findRoot(a);
//     b = findRoot(b);
//     if(a == b) return false;
//     par[b] = a;
//     return true;
// }
// void kr(){
//     vector<edge> e;
//     int w = 0;
//     for(auto it : adj){
//         if(Union(it.u,it.v)){
//             w += it.w;
//             e.pb(it);
//         }
//         if((int)e.size() == n - 1) break;
//     }
//     if((int)e.size() == n -1){
//         cout << w << endl;
//         for(auto &[u,v,w] : e){
//             printf("%d %d %d\n",u,v,w);
//         }
//     }
// }
// bool cmd(edge &a,edge &b){
//     return a.w < b.w;
// }
// void solve(){
//     cin >> n >> m;
//     REP(i,1,n) par[i] = i;
//     REP(i,1,m){
//         int u,v,w;cin >> u >> v >> w;
//         adj.pb({u,v,w});
//     }
//     sort(adj.begin(),adj.end(),cmd);
//     kr();
// }





int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    solve();
}