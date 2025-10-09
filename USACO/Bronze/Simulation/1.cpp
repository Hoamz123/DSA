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

void memset(vector<bool> &a){
    for(int i=0;i<(int)a.size();i++){
        a[i] = false;
    }
}
// https://usaco.org/index.php?page=viewproblem2&cpid=891
void solve(){
    int n;cin >> n;
    vi point = {0,0,0,0};
    vi pos = {0,1,2,3};
    FOR1(i,n){
        int a,b,g;cin >> a >> b >> g;
        FOR1(j,3){
            if(pos[j] == a) pos[j] = b;
            else if(pos[j] == b) pos[j] = a;

            if(pos[j] == g) point[j]++;
        }
    }
    cout << max({point[1],point[2],point[3]});
}

int main(){
    faster();
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}