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

vector<pii> adj[maxn];
vll dist(maxn,INF);
vi par(maxn,0);
int n,m;

void dk(int u){
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,u});
    dist[u] = 0;//tu u den u thi = 0
    while(!q.empty()){
        auto [w,x] = q.top();q.pop();
        if(w > dist[x]) continue;
        for(auto [v,ww] : adj[x]){
            if(dist[v] > dist[x] + ww){
                dist[v] = dist[x] + ww;
                q.push({dist[v],v});
                par[v] = x;
            }
        }
    }
    if(dist[n] == INF) cout << -1;
    else{
        cout << dist[n] << endl;
        stack<int> st;
        int i = n;
        while(i != 1){
            st.push(i);
            i = par[i];
        }
        st.push(1);
        while(!st.empty()){
            cout << st.top() << ' ';
            st.pop();
        }
    }
}
//acc

void solve(){
    cin >> n >> m;
    FOR1(i,m){
        int u,v,w;cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dk(1);
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