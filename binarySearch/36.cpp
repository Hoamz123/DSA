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

ll f(ll x){
    return x / 2 + x / 3 - x / 6;
    //tong so chia het cho 2
    //tong so chia het cho 3
    //tru di so luong so chia het cho 6
}

void solve(){
    ll k;cin >> k;
    ll L = 0,R = 1e18;
    ll ans = 0;
    while(L <= R){
        ll m = L + (R - L) / 2;
        if(f(m) <= k){
            ans = m;
            L = m + 1;
        }
        else R = m - 1;
    }
    cout << ans;
}

int main(){
    faster();
    solve();
}
//2 3 4 6 8 9 10 12 14 15 16 18 20
