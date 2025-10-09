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
    int n;cin >> n;
    vi index(n+1);
    FOR1(i,n) cin >> index[i];
    vi id(n+1);
    FOR1(i,n) cin >> id[i];
    vi res;
    FOR1(i,n){
        res.pb(index[index[index[i]]]);
    }
    FOR0(i,(int)res.size()){
        cout << id[res[i]] << '\n';
    }
}

int main(){
    faster();
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    solve();
}