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
char a[10001][10001];
int vst[10001][10001];

string x = "LURD";

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

int xA,yA,xB,yB;
string road = "";


bool Try(int i,int j){
    vst[i][j] = 1;
    if(i == xB && j == yB){
        return true;
    }

    for(int k=0;k<4;k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];

        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && vst[i1][j1] == 0 && a[i1][j1] != '#'){
            road.pb(x[k]);
            if(Try(i1,j1)) return true;
            road.pop_back();
        }   
    }
    return false;
}

void solve(){
    cin >> n >> m;//n hang ,m cot
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >>  a[i][j];
            if(a[i][j] == 'A'){
                xA = i;
                yA = j;
            }
            if(a[i][j] == 'B'){
                xB = i;
                yB = j;
            }
        }
    }    

    if(Try(xA,yA)){
        cout << road;
    }
    else cout << "IMPOSSIBLE";//ko den duoc B
}

int main(){
    faster();
    solve();
}
/*
5 6
A.#...
.#.#.#
..#..#
#..#.B
......
*/
//DDRDRDRRDR