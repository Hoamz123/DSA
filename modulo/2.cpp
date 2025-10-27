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

ll fact[nax];//fact[i] i!
ll inFact[nax];//inFact[i] : nghich dao modun cua i!

//nghich dao modulo
ll _power(ll x,ll y){
    x %= mod;
    ll res = 1;
    while(y){
        if(y & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;//chia doi lay pnd
    }
    return res;
}

void setUp(){
    fact[0] = 1;
    //-> tinh giai thua
    FOR1(i,nax){
        fact[i] = ((i) * fact[i-1]) % mod;
    }
    inFact[nax] = _power(fact[nax],mod - 2);
    PER(i,nax-1,1){
        inFact[i] = (inFact[i+1] * (i + 1)) % mod;
    }
}

ll nCk(ll n,ll k){
    if(k > n) return 0;
    return (fact[n] * inFact[k] % mod) * inFact[n-k] % mod;
}

void solve(){
    cout << nCk(5,3);
}

int main(){
    faster();
    setUp();
    int t = 1;
    while(t--){
        solve();
    }
}