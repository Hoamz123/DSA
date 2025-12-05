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

ll _pow(ll a,int b){
    ll res = 1;
    a = a % mod;
    while(b){
        if(b & 1) res = (res * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return res;
}

int spf[maxn + 99];

void seive_(){
    FOR0(i,maxn) spf[i] = i;
    for(int i=2;i * i <+ maxn;i++){
        if(spf[i] == i){
            for(int j = i * i;j<= maxn;j+=i){
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

void solve(){
    int n;cin >> n;
    cout << _pow(n,3);
    // vi a(maxn,0);
    // FOR1(i,n) cin >> a[i];
    // unordered_map<ll,int> mp;
    // FOR1(i,n){
    //     ll x = a[i];
    //     ///phan tich thua so nt cua x
    //     for(int p = 2;p * p <= x;p++){
    //         if(x % p == 0){
    //             int cnt = 0;
    //             while(x % p == 0){
    //                 cnt++;
    //                 x /= p;
    //             }
    //             mp[p] = max(mp[p],cnt);
    //         }
    //     }
    //     if(x != 1) mp[x] = max(mp[x],1);
    // }
    // ll ans = 1;
    // for(auto &[p,c] : mp){
    //     ans = (ans * _pow(p,c)) % mod;
    // }
    // cout << ans;
}

int main(){
    faster();
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // seive_();
    solve();
}
