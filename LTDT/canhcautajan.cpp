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
int tin[maxn],low[maxn];
int timer = 0;

set<pii> edges;

void dfs(int u,int p){
    vst[u] = 1;
    tin[u] = low[u] = ++timer;

    for(int v : adj[u]){
        if(v == p) continue;//bo qua nhung dinh quay ve cha truc tiep

        if(!vst[v]){
            dfs(v,u);//v ,cha cua v la u
            low[u] = min(low[u],low[v]);

            if(low[v] > tin[u]){
                edges.is({u,v});
                edges.is({v,u});
            }
        }
        else low[u] = min(low[u],tin[v]);
    }
}

void solve(){
    cin >> n >> m;
    vector<pii> canh(maxn);
    FOR1(i,m){
        int u,v;cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        canh[i] = {u,v};
    }    

    FOR1(i,n) if(!vst[i]){
        dfs(i,-1);
    }

    cout << (int)edges.size() / 2 << endl;

    FOR1(i,m){
        if(edges.count(canh[i]) != 0) cout << i << ' '; 
    }
}

int main(){
    faster();
    solve();
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