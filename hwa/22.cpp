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

vi par(maxn,0);
vi sz(maxn,0);
vi ethRemove(maxn,0);
pii edge[maxn];
pii que[maxn];
int n,m,q;

int find(int u){
    if(u == par[u]) return u;
    return par[u] = find(par[u]);
}

void makeSet(){
    FOR1(i,n){
        par[i] = i;
        sz[i] = 1;
    } 
}

void Union(int u,int v){
    u = find(u);
    v = find(v);
    if(u == v) return;
    if(sz[u] < sz[v]) swap(u,v);
    par[v] = u;
    sz[u] += sz[v];
}

void solve(){
    cin >> n >> m >> q;
    FOR1(i,m){
        int u,v;cin >> u >> v;
        edge[i] = {u,v};
    }
    FOR1(i,q){
        int e,c;cin >> e >> c;
        ethRemove[e] = 1;//danh dau la dinh e trong ds bi xoa
        que[i] = {e,c};
    }
    makeSet();
    //bat dau tu do thi ko co canh -> noi lai
    FOR1(i,m){
        if(!ethRemove[i]){
            //neu ko co trong list xoa
            auto [u,v] = edge[i];
            Union(u,v);
        }
    }
    //thay vi xoa roi dem thi tao se dem roi them
    vi ans(maxn,0);
    PER(i,q,1){
        auto [e,c] = que[i];
        c = find(c);
        ans[i] = sz[c];
        auto [u,v] = edge[e];
        Union(u,v);
    }
    FOR1(i,q) cout << ans[i] << endl;
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