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

void solve(){
    int m,n,k;cin >> m >> n >> k;
    vector<vector<char>> ans;
    FOR1(i,m){
        vector<char> res;
        FOR1(j,n){
            char c;cin >> c;
            FOR1(x,k){
                res.pb(c);
            }
        }
        FOR1(x,k) ans.pb(res);
    }
    FOR0(i,k*m){
        FOR0(j,k*n){
            cout << ans[i][j];
        }
        cout << endl;
    }
}

int main(){
    faster();
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}