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

vi adj[maxn];
vi vst(maxn,0);
pii road[maxn];

int n,m,k;
vi p(maxn,0);
int d[1005][1005];//d[s][i] la khoang cach tu s den i

void bfs(int s){
    queue<int> q;
    q.push(s);
    vst[s] = 1;
    d[s][s] = 0;
    while(!q.empty()){
        int u = q.front();q.pop();
        for(int v : adj[u]) if(!vst[v]){
            vst[v] = 1;
            d[s][v] = d[s][u] + 1;
            q.push(v);
        }
    }
}

void solve(){
    cin >> n >> m >> k;
    FOR1(i,k) cin >> p[i];
    memset(d,-1,sizeof(d));
    
    FOR1(i,m){
        int u,v;cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        road[i] = {u,v};
    }

    FOR1(i,k){
        bfs(p[i]);
        vst = vi(maxn,0);
    }

    int res = 1e9;
    FOR1(i,m){
        auto [u,v] = road[i];
        int tmp = 0;
        for(int j=1;j<=k;j++){
            int pj = p[j];
            if(d[pj][u] < 0 && d[pj][v] >= 0) tmp += d[pj][v];
            else if(d[pj][v] < 0 && d[pj][u] >= 0) tmp += d[pj][u];
            else if(d[pj][v] >= 0 && d[pj][u] >= 0) tmp += min(d[pj][v],d[pj][u]);
        }
        res = min(res,tmp);
    }
    cout << res;
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
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