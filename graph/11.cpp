#include<bits/stdc++.h>
using namespace std;
#define faster() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define ll long long
#define pii pair<int, int>
#define pll pair<long, long>
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

double getD(pll a,pll b){
    return 1.0 * sqrt((b.first - a.first) *(b.first - a.first)  + (b.second - a.second) * (b.second - a.second));
}

struct E{
    int u,v;
    double w;
};

bool cmd(E &a,E &b){
    return a.w < b.w;
}

vector<E> edge;
vll par(maxn,0);

ll find(ll u){
    if(u == par[u]) return u;
    return par[u] = find(par[u]);
}

bool Union(ll u,ll v){
    u = find(u);
    v = find(v);
    if(u == v) return false;
    par[v] = u;
    return true;
}

void solve(){
    int n;cin >> n;
    pll adj[n + 1];
    FOR1(i,n){
        par[i] = i;
        ll x,y;cin >> x >> y;
        adj[i] = {x,y};
    }
    FOR1(i,n){
        //d[i] = 0;
        for(int j=1;j<=n;j++){
            if(i == j) continue;
            double dis = getD(adj[i],adj[j]);
            edge.pb({i,j,dis});
        }
    }
    sort(edge.begin(),edge.end(),cmd);

    double maxD = -1e9;
    for(E e : edge){
        if(Union(e.u,e.v)){
            maxD = max(maxD,e.w);
        }
    }
    printf("%.6f",maxD / 2);
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