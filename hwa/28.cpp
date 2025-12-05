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

struct E {
    int u, v, w;
};

int n, m;
vi par(maxn, 0), ans(maxn, 0);
vector<E> edge;
map<tuple<int,int,int>, int> mp;

int findp(int u) {
    if (u == par[u]) return u;
    return par[u] = findp(par[u]);
}

bool Union(int u, int v) {
    u = findp(u);
    v = findp(v);
    if (u == v) return false;
    par[v] = u;
    return true;
}

bool cmp(E &a, E &b) {
    return a.w < b.w;
}

void ks() {
    FOR1(i, n) par[i] = i;
    FOR0(i, (int)edge.size()) {
        E e = edge[i];
        if (Union(e.u, e.v)) {
            mp[{e.u, e.v, e.w}] = 1;
            mp[{e.v, e.u, e.w}] = 1;
        }
    }
}

void solve() {
    cin >> n >> m;
    vector<E> x;
    FOR1(i, m) {
        int u, v, w; cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }
    x = edge;
    sort(edge.begin(), edge.end(), cmp);
    ks();

    for(auto e : x){
        if(mp[{e.u,e.v,e.w}]) cout << 1;
        else cout << 0;
    }
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;cin >> t;
    while(t--){
        solve();
    }
}
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .'  \|     |// '.
//                 /  \|||  :  |||// \.
//                / _||||| -:- |||||- \.
//               |   |  \  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//            ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//           Phật phù hộ, không bao giờ BUG
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~