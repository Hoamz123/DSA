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
#define INF 1000000000001
#define ull unsigned long long
#define maxn 1000005
#define FOR1(i, n) for (int i = 1; i <= (n); i++)
#define FOR0(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define PER(i, a, b) for (int i = a; i >= b; --i)
#define endl '\n'

void solve(){
    int n,m,k;cin >> n >> m >> k;
    vector<vector<pii>> adj(n + 1);
    FOR0(i,m){
        int u,v,w;cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    vector<vll> dist(n + 1,vll(k + 1,INF));
    //khoang cach nho nhat den dinh u khi da dung t canh = 0
    using T = tuple<ll,int,int>; // (d, u, used)
    /*
    d : khoang cach hien tai den dinh u
    u dinh hien tai
    used : so canh = 0 da dung
    */
    priority_queue<T, vector<T>, greater<T>> qp;
    //min-heap luon lay canh nho nhat

    dist[1][0] = 0;//bat dau tu dinh 1 khi chua dung canh nao = 0
    qp.push({0,1,0});

    while(!qp.empty()){
        auto [d,u,used] = qp.top();qp.pop();
        if(d > dist[u][used]) continue;
        for(auto [v,w] : adj[u]){
            if(dist[v][used] > d + w){
                dist[v][used] = d + w;
                qp.push({dist[v][used],v,used});
            }
            if(used < k && dist[v][used + 1] > d){
                dist[v][used + 1] = d;
                qp.push({dist[v][used + 1],v,used + 1});
            }
        }
    }
    ll ans = INF;
    FOR0(i,k + 1) ans = min(ans,dist[n][i]);
    if(ans == INF) cout << -1;
    else cout << ans;
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