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
int n;
vi miniTree[maxn];
int lab[maxn];
si se[maxn];
vi cnt(maxn);
void dfs(int u, int parent){
    miniTree[u].push_back(u);
    se[u].insert(lab[u]);
    cnt[u] = 1;
    for(int v : adj[u]){
        if(v != parent){
            dfs(v,u);
            miniTree[u].insert(miniTree[u].end(), miniTree[v].begin(), miniTree[v].end());
            cnt[u] += cnt[v];
            se[u].insert(se[v].begin(),se[v].end());
        }
    }
}

void solve(){
    cin >> n;
    FOR1(i,n) cin >> lab[i];
    FOR1(i,n-1){
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1,0);

    FOR1(i,n){
        cout << (int)se[i].size() << ' ';
    }
}

int main(){
    faster();
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // int t;cin >> t;
    // while(t--){
        solve();
    // }
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