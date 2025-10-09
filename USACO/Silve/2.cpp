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
    vector<ll> a(n + 1,0);
    FOR1(i,n) cin >> a[i];
    FOR1(i,n){
        a[i] += a[i - 1];
    }
    int res = 0;
    unordered_map<int,int> mp;
    mp[0] = 0;
    FOR1(i,n){
        if(mp.find(a[i] % 7) != mp.end()){
            res = max(res,i - mp[a[i] % 7]);
        }
        else{
            mp[a[i] % 7] = i;
        }
    }
    cout << res;
}

int main(){
    faster();
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
}