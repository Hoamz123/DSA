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

int n,q,k;
vi par(maxn,0),sz(maxn,0),mark(maxn,0),a(maxn,0);
int res = 0;
vi ans(maxn,0);

int find(int u){
    if(u == par[u]) return u;
    return par[u] = find(par[u]);
}

void Union(int u,int v){
    u = find(u);
    v = find(v);
    if(u == v) return;
    if(sz[u] < sz[v]) swap(u,v);
    sz[u] += sz[v];
    par[v] = u;
    res = max(res,sz[u]);
}

void solve(){
    cin >> n >> q;
    vector<pii> op,que;
    FOR1(i,n){
        //setup cho DSU
        par[i] = i;sz[i] = 1;
        cin >> a[i];
        op.push_back({a[i],i});
    }
    FOR1(i,q){
        cin >> k;
        que.push_back({k,i});
    }
    sort(op.begin(),op.end());
    sort(que.begin(),que.end());

    int id = 0;
    for(auto [k,idx] : que){
        while(id < n && op[id].first <= k){
            mark[op[id].second] = 1;//danh dau lai
            if(res == 0) res = 1;//vao dc dau roi thi khoi tao co 1 phan tu trong sub
            if(op[id].second > 1 && mark[op[id].second - 1]) Union(op[id].second,op[id].second - 1);
            if(op[id].second < n && mark[op[id].second + 1]) Union(op[id].second,op[id].second + 1);
            id++;
        }
        ans[idx] = res;
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