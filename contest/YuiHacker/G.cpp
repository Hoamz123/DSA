#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nax 1000001
#define mod 1000000007
#define FAST ios::sync_with_stdio(0);cin.tie(0);
#define FOR1(i,n) for(int i=1;i<=(n);i++)
#define FOR(i,n) for(int i=0;i<=(n);i++)

ll fact[nax];
ll inFact[nax];

ll power(ll x,ll y){
    x = x % mod;
    ll res = 1;
    while(y > 0){
        if(y & 1) res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}


void setUp(){
    //tinh giai thua
    fact[0] = 1;
    for(int i=1;i<nax;i++){
        fact[i] = (fact[i-1] * i) % mod;
    }
    //tinh nghich dao moduler
    inFact[nax-1] = power(fact[nax - 1],mod - 2);//ngich dao moduler cua (nax - 1)!
    for(int i = nax - 2;i>=0;i--){
        inFact[i] = (inFact[i+1] * (i + 1)) % mod;//tinh ngac lai nghiach dao moduler ciua i
    }
}

ll nCk(int n,int k){
    if(k > n) return 0;
    return (fact[n] * inFact[k] % mod) * inFact[n-k] % mod;
}

   
int main(){
    FAST;
    setUp();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;cin >> t;
    while(t--){
        int n,k;cin >> n >> k;
        cout << nCk(n,k) << endl;
    }
}