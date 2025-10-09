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

int n,m;
vector<vector<int>> v;
vector<vector<int>> cn,vst;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int extra;

void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) {
            cn[i][j] = 0;
            vst[i][j] = 0;
        }
    }
}

void Try(int x,int y){
    vst[x][y] = 1;
    for(int i=0;i<4;i++){
        int i1 = x + dx[i];
        int j1 = y + dy[i];
        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m){
            if(vst[i1][j1] == 0 && v[i1][j1] <= extra) Try(i1,j1);
        }
    }
}

void dfs(int x,int y){
    cn[x][y] = 1;
    for(int i=0;i<4;i++){
        int i1 = x + dx[i];
        int j1 = y + dy[i];
        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m){
            if(cn[i1][j1] == 0 && vst[i1][j1] == 0) dfs(i1,j1);
        }
    }
}

int test = 1;
void solve(){
    v.resize(n + 1, vi(m + 1, 0));
    vst.resize(n + 1, vi(m + 1, 0));
    cn.resize(n + 1, vi(m + 1, 0));
    int hMax = 0;
    FOR1(i,n) FOR1(j,m){
        cin >> v[i][j];
        hMax = max(hMax,v[i][j]);
    }
    for(int k=1;k<=hMax;k++){
        extra = k;
        init();
        FOR1(i,n){
            FOR1(j,m){
                if((i == 1 || i == n || j == 1 || j == m) && v[i][j] <= k && vst[i][j] == 0){
                    Try(i,j);
                }
            }
        }
        int cnt = 0;
        FOR1(i,n){
            FOR1(j,m){
                if(cn[i][j] == 0 && vst[i][j] == 0){
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        if(cnt > 1){
            cout << "Case " << test << ": Island splits when ocean rises " << extra << " feet." << endl;
            return;
        }
    }
    cout << "Case " << test << ": Island never splits." << endl;
}

int main(){
    faster();
    while(true){
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        v.clear();
        cn.clear();
        vst.clear();
        solve();
        test++;
    }
}