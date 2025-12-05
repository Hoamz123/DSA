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

int n,m,k,s;

vi adj[maxn];
vi par(maxn,0);
vi vst(maxn,0);
vi d(maxn,0);

void bfs(int s){
    queue<int> q;
    q.push(s);
    vst[s] = 1;
    d[s] = 1;
    while(!q.empty()){
        int u = q.front();q.pop();
        for(int v : adj[u]) if(!vst[v]){
            if(d[u] + 1 > k) continue;
            vst[v] = 1;
            d[v] = d[u] + 1;
            par[v] = u;
            q.push(v);
            //nho ko quen dong nay
        }
    }
}

void solve(){
    cin >> n >> m >> s >> k;
    for(int i=0;i<m;i++){
        int u,v;cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }    

    bfs(s);
    bool ok = false;
    FOR1(i,n){
        if(d[i] == k){
            ok = true;
            int x = i;
            while(x != s){
                cout << x << ' ';
                x = par[x];
            }
            cout << s << endl;
        }
    }
    if(!ok) cout << -1;
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