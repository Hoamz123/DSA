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
#define maxn 10005
#define FOR1(i, n) for (int i = 1; i <= (n); i++)
#define FOR0(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define PER(i, a, b) for (int i = a; i >= b; --i)
#define endl '\n'

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

vector<vi> d,vst,a;
int n,m;

void bfs(int i,int j){
    queue<pii> q;
    q.push({i,j});
    d[i][j] = 0;
    vst[i][j] = 1;
    while(!q.empty()){
        auto it = q.front();q.pop();
        int i = it.first;
        int j = it.second;
        if(i == n && j == m) return;
        FOR0(k,4){
            int i1 = i + dx[k];
            int j1 = j + dy[k];
            if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !vst[i1][j1] && a[i1][j1] == 0){
                d[i1][j1] = d[i][j] + 1;
                vst[i1][j1] = 1;
                q.push({i1,j1});
            }
        }
    }
}

void solve(){
    cin >> n >> m;//n hang ,m cot
    a.assign(n + 1, vector<int>(m + 1, 0));
    vst.assign(n + 1, vector<int>(m + 1, 0));
    d.assign(n + 1, vector<int>(m + 1, 0));
    FOR1(i,n)FOR1(j,m){
        char x;cin >> x;
        a[i][j] = (x - '0');
    }

    if(a[1][1] || a[n][m]) {
        cout << -1;
        return;
    }
    bfs(1,1);
    if(!vst[n][m]) cout << -1;
    else cout << d[n][m];
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