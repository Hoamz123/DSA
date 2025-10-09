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

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
vector<vi> vst;

int n,m;
vector<vector<char>> a;

int c = 0,f = 0;

void FF(int i,int j){
    vst[i][j] = 1;
    if(a[i][j] == 'c') c++;
    if(a[i][j] == 'f') f++;
    for(int k=0;k<4;k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && a[i1][j1] != '#' && vst[i1][j1] == 0){
            FF(i1,j1);
        }
    }
}

void solve(){
    cin >> n >> m;
    a = vector<vector<char>>(n,vector<char>(m));
    vst = vector<vi>(n,vi(m,0));
    FOR0(i,n) FOR0(j,m) cin >> a[i][j];

    int cRes = 0,fRes = 0;
    FOR0(i,n) FOR0(j,m){
        if(a[i][j] != '#' && vst[i][j] == 0){
            FF(i,j);
            if(c > f) cRes += c;
            else fRes += f;
            c = 0,f = 0;
        }
    }
    cout << fRes << ' ' << cRes << endl;
}

int main(){
    faster();
    solve();

    //acc
}
/*
8 8
.#######
#..c...#
#.####.#
#.#f.#.#
#.#.c#c#
#c.##..#
#.f..f.#
.######.*/