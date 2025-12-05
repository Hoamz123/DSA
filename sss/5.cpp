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

ll ans = LLONG_MAX;
int n,k;
int a[55][55];
vector<int> res;

//tim duong di dai k bat dau tu dinh1 sao cho trong so la nho nhat

void dfs(int u,int deep,ll sum,vi &path,vi &vst){
    if(sum >= ans) return;
    if(deep == k){
        if(a[u][1]){
            int t = sum + a[u][1];
            if(t < ans){
                ans = t;
                res = path;
            }
        }
        return;
    }

    for(int v = 1;v <= n;v++){
        if(vst[v] == 0){
            vst[v] = 1;
            path.pb(v);
            dfs(v,deep + 1,sum + a[u][v],path,vst);
            path.pop_back();
            vst[v] = 0;
        }
    }
}

void solve(){
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    vi path;
    vi vst(n + 1,0);
    vst[1] = 1;
    path.pb(1);
    dfs(1,1,0,path,vst);
    cout << ans << endl;
    for(int x : res) cout << x << ' ';
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