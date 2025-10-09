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
vector<vi> a;
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
vector<vi> vst;
bool check;
void ff(int i,int j){
    vst[i][j] = 1;
    for(int k=0;k<8;k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m){
            if(check && a[i1][j1] > a[i][j]){
                check = false;
            }
            else if(a[i1][j1] == a[i][j] && vst[i1][j1] == 0){
                ff(i1,j1);
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    a = vector<vi>(n + 1,vi(m + 1));
    vst = vector<vi>(n + 1, vi(m + 1,0));
    REP(i,1,n) REP(j,1,m) cin >> a[i][j];
    int ans = 0;
    REP(i,1,n) REP(j,1,m){
        check = true;
        if(vst[i][j] == 0){
            ff(i,j);
            if(check) ans++;
        }
    }
    cout << ans;
}

int main(){
    faster();
    solve();
} // https://oj.vnoi.info/problem/nkguard