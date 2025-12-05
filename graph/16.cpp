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

int n,m,q;

vi adj[maxn];
vi color(maxn,0);

struct query{
    int u,d,c;
};

vector<query> qe;


void bfs(int u,int d,int c){
    queue<pii> que;//{dinh ,do dai khoang c tu dinh bat dau den dinh dang xet}
    que.push({u,0});
    vi vst(maxn,0);
    vst[u] = 1;
    color[u] = c;
    while(!que.empty()){
        auto [u,dist] = que.front();que.pop();
        if(dist >= d) continue;
        for(int v : adj[u]) if(!vst[v]){
            vst[v] = 1;
            color[v] = c;
            que.push({v,dist + 1});
        }
    }
}

void solve(){
    cin >> n >> m;
    FOR1(i,m){
        int u,v;cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cin >> q;
    FOR0(i,q){
        int u,d,c;cin >> u >> d >> c;
        qe.push_back({u,d,c});
    }
    for(auto [u,d,c] : qe){
        bfs(u,d,c);
    }
    FOR1(i,n) cout << color[i] << endl;
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