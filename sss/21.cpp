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


//acc : Trong do thi 1 chieu tim ra thanh phan lien thong lon nhat

int n,m;
stack<int> st;
vi vst(maxn,0);
vi visited(maxn,0);
vi adj[maxn];
vi r_adj[maxn];

void dfs1(int u){
    vst[u] = 1;
    for(int v : adj[u]) if(!vst[v]){
        dfs1(v);
    }
    st.push(u);
}

vi ve;

void dfs2(int u){
    visited[u] = 1;
    ve.pb(u);
    for(int v : r_adj[u]) if(!visited[v]){
        dfs2(v);
    }
}

void kahn(){
    FOR1(i,n){
        if(!vst[i]) dfs1(i);
    }

    vi res;

    while(!st.empty()){
        int u = st.top();st.pop();
        if(!visited[u]){
            dfs2(u);
            if((int)res.size() < (int)ve.size()){
                res = ve;
            }
            ve.clear();
        }
    }
    sort(res.begin(),res.end());
    cout << res.size() << endl;
    for(int i : res) cout << i << " ";
}

void solve(){
    cin >> n >> m;
    FOR1(i,m){
        int u,v;cin >> u >> v;
        adj[u].pb(v);
        r_adj[v].pb(u);
    }
    kahn();
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