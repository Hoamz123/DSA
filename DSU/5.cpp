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

vector<vector<char>> v;
int n,m;

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};


void bfs(int x,int y){
    v[x][y] = '.';
    for(int i=0;i<8;i++){
        int i1 = x + dx[i];
        int j1 = y + dy[i];
        if(i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && v[i1][j1] != '.'){
            bfs(i1,j1);
        }
    }
}

void solve(){
    cin >> n >> m;
    int cnt = 0;
    v.resize(n,vector<char>(m));
    FOR0(i,n) FOR0(j,m) cin >> v[i][j];

    FOR0(i,n)FOR0(j,m){
        if(v[i][j] != '.'){
            bfs(i,j);
            cnt++;
        }
    }
    cout << cnt;
}

int main(){
    faster();
    int t = 1;
    while(t--){
        solve();
    }
} // https://www.spoj.com/PTIT/problems/BCLKCOUN/