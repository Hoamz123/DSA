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

vector<vi> adj;
vector<int> par,sz;
int n,m;

struct edge{
    int u,v,w;
};

vector<edge> edges;

void make_set(){
    adj.resize(n + 1);
    par.resize(n + 1);
    FOR1(i,n) par[i] = i;
    sz.assign(n + 1,1);
}

int find_root(int u){
    return (u == par[u]) ? u : (par[u] = find_root(par[u]));
}

void remo(){
    adj = vector<vi> (n + 1);
    FOR1(i,n) par[i] = i;
}

bool Union(int a,int b){
    a = find_root(a);
    b = find_root(b);
    if(a != b){
        par[b] = a;
        sz[a] += sz[b];
        return true;
    }
    return false;
}

int get_size(int u){
    u = find_root(u);
    return sz[u];
}

bool cmp(edge &a,edge &b){
    return a.w < b.w;
}

void kruskal(){
    ll sumWeightMin = 0;
    int cnt = 0;
    for(edge eg : edges){
        if(Union(eg.u,eg.v)){
            sumWeightMin += eg.w;
            cnt ++;
        }
        if(cnt == n - 1){
            break;
        }
    }
    if(cnt == n - 1){
        cout << sumWeightMin;
    }
}

void solve(){
    cin >> n >> m;
    make_set();
    FOR1(i,m){
        int u,v,w;cin >> u >> v >> w;
        Union(u,v);
        edges.pb({u,v,w});
    }

    if(get_size(1) != n){
        cout << "IMPOSSIBLE\n";
    }
    else{
        remo();
        sort(edges.begin(),edges.end(),cmp);
        kruskal();
    }
}
// https://cses.fi/problemset/task/1675/
// acc

int main(){
    faster();
    int t = 1;
    while(t--){
        solve();
    }
}