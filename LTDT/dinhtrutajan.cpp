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
si mark;

void dfs(int u,int p){
    vst[u] = 1;
    tin[u] = low[u] = ++timer;
    int child = 0;//dem so con truc tiep
    for(int v : adj[u]){
        if(v == p) continue;//bo qua nhung canh noi ve cha truc tiep

        if(!vst[v]){
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            child++;
            if(p != -1 && low[v] > tin[u]){
                mark.is(u);
            }
        }
        else low[u] = min(low[u],tin[v]);
    }
    if(p == -1 && child >= 2) mark.is(u);
}

void solve(){
    cin >> n >> m;
    FOR1(i,m){
        int u,v;cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }    

    FOR1(i,n){
        if(!vst[i]) dfs(i,-1);
    }

    cout << (int)mark.size() << endl;
    for(int i : mark) cout << i << ' ';
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