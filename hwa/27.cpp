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

vector<pii> adj[maxn];
vi vst(maxn,0),par(maxn,0),d(maxn,1e9);
int n;

int res = 0;

void prim(int u){
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,u});
    while(!q.empty()){
        auto [w,uu] = q.top();q.pop();
        if(vst[uu]) continue;
        res += w;
        vst[uu] = 1;
        for(auto [v,w] : adj[uu]){
            if(!vst[v] && w < d[v]){
                d[v] = w;
                q.push({d[v],v});
            }
        }
    }
}

void solve(){
    cin >> n;
    vi a(maxn,0);
    FOR1(i,n) cin >> a[i];

    FOR1(i,n)FOR1(j,n){
        int x;cin >> x;
        if(i == j) continue;
        adj[i].push_back({j,x});
    }

    FOR1(i,n){
        adj[i].push_back({0,a[i]});
        adj[0].push_back({i,a[i]});
    }

    prim(0);
    cout << res;
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