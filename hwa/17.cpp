//LCA
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
vi par(maxn);

struct edge{
    int u,v,w;
    edge(int _u,int _v,int _w) : u(_u),v(_v),w(_w) {}
};

vector<edge> eg;

bool cmd(edge a,edge b){
    return a.w < b.w;//torng so tang dan
}

void make_set(){
    FOR1(i,n){
        par[i] = i;
    }
}

int find(int u){
    if(u == par[u]) return u;
    return par[u] = find(par[u]);
}

bool Union(int u,int v){
    u = find(u);
    v = find(v);
    if(u == v) return false;

    //gan v vao u
    par[v] = u;
    return true;
}

void ks(){
    vector<edge> canh;
    int res = 0;
    FOR0(i,(int)eg.size()){
        auto e = eg[i];
        if((int)canh.size() == n - 1) break;
        if(Union(e.u,e.v)){
            res += e.w;
            canh.push_back(e);
        }
    }
    cout << res << endl;//tong trong so cay khung nho nhat
    FOR0(i,(int)canh.size()) cout << canh[i].u << ' ' << canh[i].v << " " << canh[i].w << endl; 
}

void solve(){
    //n dinh m canh
    cin >> n >> m;
    FOR1(i,m){
        int u,v,w;cin >> u >> v >> w;
        edge e = edge(u,v,w);
        eg.push_back(e);
    }
    sort(eg.begin(),eg.end(),cmd);
    make_set();
    ks();
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