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
#define nax 1000005
#define FOR1(i, n) for (int i = 1; i <= (n); i++)
#define FOR0(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define PER(i, a, b) for (int i = a; i >= b; --i)
#define endl '\n'
#define fi first
#define se second
//bai toan long dau tren mang 2d
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
vector<vector<int>> v,vst;
unordered_map<int,int> pre;
int n,m;
int cnt = 0;
void dfs(int x,int y){
    v[x][y] = 0;
    cnt++;
    for(int i=0;i<4;i++){
        int i1 = x + dx[i];
        int j1 = y + dy[i];
        if(i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && v[i1][j1] == 1){
            dfs(i1,j1);
        }
    }
}

void solve(){
    v = vector<vector<int>>(n, vector<int>(m,0));
    set<int> res;
    FOR0(i,n)FOR0(j,m) cin >> v[i][j];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j] == 1){
                dfs(i,j);
                res.is(cnt);
                pre[cnt]++;
                cnt = 0;
            }
        }
    }
    int sum  = 0;
    for(auto &[fi,se] : pre) sum += se;
    cout << sum << endl;
    for(int i : res) cout << i << ' ' << pre[i] << endl;
}
//acc
int main(){
    faster();
    while(true){
        cnt = 0;
        pre.clear();
        cin >> n >> m;
        if(n == m && m  == 0) break;
        solve();
    }
}