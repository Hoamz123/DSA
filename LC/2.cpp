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


vector<int> adj[100001];
vi d(100001,0);

int n,m;//n dinh m canh

int cnt(int s,int t){
    if(s == t) return 1;///moi khi den dich thi co 1 duong di
    if(d[s] != 0) return d[s];
    int res = 0;
    for(int v : adj[s]){
        res += cnt(v,t);
    }
    return d[s] = res;
}

void solve(){
    cin >> n >> m;
    FOR0(i,m){
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
    }
    int s,t;cin >> s >> t;
    cout << cnt(s,t);
}

int main(){
    faster();
    solve();
}