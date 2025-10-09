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
    int n,k;cin >> n >> k;
    string s;cin >> s;
    set<char> se;
    FOR0(i,k){
        char x;cin >> x;
        se.is(x);
    }
    vi dp(n,0);//dp[i] la so xau thoa man ket thuc tai s[i]
    (se.count(s[0]) > 0) ? (dp[0] = 1) : (dp[0] = 0);
    REP(i,1,n-1){
        if(se.count(s[i]) > 0) dp[i] = dp[i-1] + 1;
        else dp[i] = 0;
    }
    ll numberSub = 0;
    for(int i : dp) {
        numberSub += i;
    }
    cout << numberSub;
}

int main(){
    faster();
    int t = 1;
    while(t--){
        solve();
    }
}