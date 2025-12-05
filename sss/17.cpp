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
vi adj[maxn];
vi vst(maxn,0);
vll t(maxn,0);
ll sum = 0;
ll Minus = 0;
int cnt = 0;

void dfs(int u){
    vst[u] = 1;
    sum += t[u];
    Minus = max(Minus,t[u]);
    cnt++;
    for(int v : adj[u]) if(!vst[v]) {
        dfs(v);
    }
}

void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> t[i];
    for(int i=0;i<m;i++){
        int u,v;cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int ans = 0;
    ll res = 0;
    for(int i=1;i<=n;i++){
        if(!vst[i]){
            dfs(i);
            if(cnt > ans){
                ans = cnt;
                res = sum - Minus;
            }
            else if(cnt == ans){
                if(sum - Minus < res) {
                    res = sum - Minus;
                }
            }
            Minus = 0;
            cnt = 0;
            sum = 0;
        }
    }
    cout << ans << ' ' << res;
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