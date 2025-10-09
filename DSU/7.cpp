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

int par[nax],sz[nax];
int maxVal[nax],minVal[nax];
int n,m;

void make_set(){
    FOR1(i,n){
        par[i] = i;
        sz[i] = 1;
        maxVal[i] = i;
        minVal[i] = i;
    }
}

int find_set(int u){
    if(u == par[u]) return u;
    return par[u] = find_set(par[u]);
}

void union_set(int a,int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(sz[a] < sz[b]) swap(a,b);
        sz[a] += sz[b];
        par[b] = a;
        maxVal[a] = max(maxVal[a],maxVal[b]);
        minVal[a] = min(minVal[a],minVal[b]);
    }
}

vi get(int u){
    u = find_set(u);
    return {minVal[u],maxVal[u],sz[u]};
}

void solve(){
    cin >> n >> m;
    make_set();
    FOR1(i,m){
        string type;cin >> type;
        if (type == "union"){
            int u,v;cin >> u >> v;
            union_set(u,v);
        }
        else{
            int u;cin >> u;
            auto it = get(u);
            cout << it[0] << ' ' << it[1] << ' ' << it[2] << endl;
        }
    }
}
/*
5 11
union 1 2
get 3
get 2
union 2 3
get 2
union 1 3
get 5
union 4 5
get 5
union 4 1
get 5
*/
int main(){
    faster();
    int t = 1;
    while(t--){
        solve();
    }
}