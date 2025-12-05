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

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

vector<vector<char>> a;
vector<vi> vst;
int cnt = 0;
int n,m;

void bfs(int i,int j){
    vst[i][j] = 1;
    queue<pii> q;
    q.push({i,j});
    while(!q.empty()){
        auto it = q.front();q.pop();
        int i = it.first;
        int j = it.second;
        if(a[i][j] == 'x') cnt++;
        FOR0(k,4){
            int i1 = i + dx[k];
            int j1 = j + dy[k];
            if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !vst[i1][j1] && a[i1][j1] != '#'){
                vst[i1][j1] = 1;
                q.push({i1,j1});
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    a.assign(n + 1,vector<char>(m + 1));
    vst.assign(n + 1,vi(m + 1,0));
    FOR1(i,n)FOR1(j,m){
        cin >> a[i][j];
    }
    multiset<int> se;
    FOR1(i,n)FOR1(j,m){
        if(a[i][j] != '#' && !vst[i][j]){
            cnt = 0;
            bfs(i,j);
            if(cnt) se.is(cnt);
        }
    }
    for(int i : se) cout << i << ' ';
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