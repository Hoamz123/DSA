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

char grid[1007][1007];
int startX,startY;
int d[1007][1007];
int used[1007][1007];
int m,n;
int dx[4] = {0,-1,0,1};//4 o chung cach voi i
int dy[4] = {-1,0,1,0};//tuong tu

int Try(int i,int j){
    queue<pii> q;
    q.push({i,j});
    used[i][j] = 1;
    while(!q.empty()){
        pii p = q.front();q.pop();
        FOR0(k,4){
            int i1 = p.first + dx[k];
            int j1 = p.second + dy[k];
            if(i1 > -1 && i1 < m && j1 > -1 && j1 < n && !used[i1][j1] && grid[i1][j1] == 'O'){
                d[i1][j1] = d[p.first][p.second] + 1;
                if(i1 == m - 1 || j1 == n - 1 || i1 == 0 || j1 == 0) return d[i1][j1];
                q.push({i1,j1});
                used[i1][j1] = 1;//danh dau la da duyet qua
            }
        }
    }
    return -1;//khong co duong
}

void solve(){
    cin >> m >> n;//m hang n cot
    FOR0(i,m)FOR0(j,n) {
        cin >> grid[i][j];
        if(grid[i][j] == 'E'){
            startX = i;startY = j;
        }
    }
    //E nam tren bien
    if(startX == 0 || startX == m - 1 || startY == 0 || startY == n - 1){
        cout << 0;
        return;
    }
    memset(used,0,sizeof(used));
    memset(d,0,sizeof(d));
    d[startX][startY] = 0;
    int res = Try(startX,startY);
    cout << res << endl;
}

int main(){
    faster();
    solve();
}

/*
4 5
O O X O O
X O X O O
O O E X O
O O X X O
*/
