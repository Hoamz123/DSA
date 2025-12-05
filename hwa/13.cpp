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
//https://oj.vnoi.info/problem/icpc25_mt_l
vector<pii> adj[maxn];
vi wait(maxn,0);
vi in(maxn,0);
double timeRes = 0;
int n,m,vt;

void dsk(int s,int t){
    priority_queue<pii,vector<pii>,greater<pii>> q;
    vector<double> minDist(maxn,1e9);
    minDist[s] = 0;//tu s den s ko can di
    q.push({0,s});

    while(!q.empty()){
        auto it = q.top();q.pop();
        int u = it.second;
        int d = it.first;

        if(d > minDist[u]) continue;
        for(pii e: adj[u]){
            int v = e.first;
            int w = e.second;
            double cost = (w * 1.0) / (vt * 1.0) + wait[v];
            if(minDist[v] > cost + minDist[u]){
                minDist[v] = cost + minDist[u];
                q.push({minDist[v],v});
            }
        }
    }
    printf("%.6f\n",minDist[t]);
}

void solve(){
    cin >> n >> m >> vt;//n dinh ,m canh,v de sau cung tinh
    FOR1(i,m){
        int a,b,d;
        cin >> a >> b >> d;
        adj[a].push_back({b,d});
        adj[b].push_back({a,d});
        in[a]++;//dem so nga se tai a
        in[b]++;//tai b
    }

    FOR1(i,n){
        wait[i] = max(0,in[i] - 2);
    }
    int s,t;cin >> s >> t;
    wait[s] = 0;
    wait[t] = 0;
    dsk(s,t);
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