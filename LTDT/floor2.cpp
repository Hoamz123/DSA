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

int n,m;
char a[1001][1001];
int vst[1001][1001];
int cnt = 0;
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

void Try(int i,int j){
    vst[i][j] = 1;
    for(int k=0;k<4;k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && vst[i1][j1] == 0 && a[i1][j1] != '#'){
            Try(i1,j1);
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin >> a[i][j];
    }
    
    memset(vst,0,sizeof(vst));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(vst[i][j] == 0 && a[i][j] == '.') {
                cnt++;
                Try(i,j);
            }
        }
    }
    cout << cnt;
}

int main(){
    faster();
    solve();
}
/*

5 8
########
#..#...#
####.#.#
#..#...#
########

*/