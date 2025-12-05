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
//DSU on tree

vi adj[maxn];//ds ke
vi label(maxn,0),sz(maxn,0),in(maxn),out(maxn);
//lan luot la nhan cua tung dinh,kick thuoc cay con cua tung dinh,
//vi tri bat dau,ket thuc trong tour
vi ans(maxn,0);
vi tour;//luu lai label cua moi dinh
mii cnt;

void finSz(int u,int p){
    sz[u] = 1;
    tour.push_back(label[u]);
    in[u] = (int)tour.size() - 1;
    for(int v : adj[u]){
        if(v != p){
            finSz(v,u);
            sz[u] += sz[v];
        }
    }
    out[u] = (int)tour.size() - 1;
}

void dfs(int u,int par,bool keep){
    int heavy = -1;//nhanh lon nhat
    for(int v : adj[u]){
        if(v != par && (heavy == -1 || sz[v] > sz[heavy])) heavy = v;
    }
    
    //dfs tat ca nhanh nho truoc
    for(int v : adj[u]){
        if(v != heavy && v != par) dfs(v,u,false);
    }

    if(heavy != -1) dfs(heavy,u,true);

    cnt[label[u]]++;

    for(int v : adj[u]){
        if(v != par && v != heavy){
            for(int i = in[v];i<= out[v];i++){
                cnt[tour[i]]++;
            }
        }
    }
    ans[u] = cnt.size();

    if(!keep) cnt.clear();
}

void solve(){ 
    int n;cin >> n;
    FOR1(i,n) cin >> label[i];
    FOR1(i,n-1){
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    finSz(1,0);

    dfs(1,0,true);

    FOR1(i,n) cout << ans[i] << ' ';

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