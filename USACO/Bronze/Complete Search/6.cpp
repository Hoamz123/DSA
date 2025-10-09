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
    int n,m;cin >> n >> m;
    vector<si> _1;
    vector<si> _2;
    vector<vector<char>> n_1(n,vector<char>(m,' '));
    vector<vector<char>> n_2(n, vector<char>(m,' '));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> n_1[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> n_2[i][j];
        }
    }
    for(int j=0;j<m;j++){
        set<int> se;
        for(int i=0;i<n;i++){
            se.is(n_1[i][j]);
        }
        _1.pb(se);
    }
    for(int j=0;j<m;j++){
        set<int> se;
        for(int i=0;i<n;i++){
            se.is(n_2[i][j]);
        }
        _2.pb(se);
    }

    int cnt = 0;
    for(int i=0;i<m;i++){
        bool ok = true;
        for(auto it : _1[i]){
            if(_2[i].find(it) != _2[i].end()){
                ok = false;
                break;
            }
        }
        if(ok) cnt++;
    }
    cout << cnt;
}

int main(){
    faster();
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}//acc
/*
anh da quay tro lai roi*/