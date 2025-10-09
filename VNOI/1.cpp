#include<bits/stdc++.h>
using namespace std;
#define INF 1000000001
#define ll long long
#define mod 1000000007
#define sz 1000001
ll fact[sz];//tinh giai thua
ll inFact[sz];//tinh mod nghich dao

ll power(ll x,ll y){
    x = x % mod;
    ll res = 1;
    while(y > 0){
        if(y & 1) res = (res * x) % mod;
        y = y >> 1;//chia 2
        x = (x * x) % mod;
    }
    return res;
}

void setUp(){
    //tinh giai thuc
    fact[0] = 1;
    for(int i=1;i<sz;i++){
        fact[i] = (fact[i-1] * i) % mod;
    }
    //tinh nghich dao modun cua x!
    inFact[sz - 1] = power(fact[sz - 1],mod - 2);
    for(int i = sz - 2;i>=0;i--){
        inFact[i] = (inFact[i+1] * (i + 1) ) % mod;
    }
}

ll nCk(ll n,ll k){
    if(k > n) return 0;
    return (fact[n] * inFact[k] % mod) * inFact[n-k] % mod;
}

int main(){
    setUp();
    int n,m,k;cin >> n>> m >> k;
    vector<pair<int,int>> p;
    for(int i=0;i<k;i++){
        int x,y;cin >> x >> y;
        p.push_back({x,y});
    }
    sort(p.begin(),p.end());
    vector<ll> dp(k,0);//so luong duong di tu 1 1 tinh den cac o co boom

    for(int i=0;i<k;i++){
        int x = p[i].first;int y = p[i].second;
        dp[i] = nCk(x + y - 2,x - 1);//so cach di tu 1 1 den x y
        for(int j=0;j<i;j++){
            int x1 = p[j].first;int y1 = p[j].second;
            if(x1 <= x && y1 <= y){
                ll tmp = dp[j] * nCk(x - x1 + y - y1,x - x1) % mod;//so cach di tu 1 1 den bom x1,y1 roi so cach tu bom x1,y 1den x,y
                dp[i] = (dp[i] - tmp + mod) % mod;// + mod de trach am
            }
        }
    }
    ll totalWays = nCk(n+m-2,n-1);//tong so cach tu 1,1 dn n,m
    for(int i=0;i<k;i++){
        int x = p[i].first;int y = p[i].second;
        ll tmp = (dp[i] * nCk(n + m - x - y,n - x)) % mod;
        totalWays = (totalWays - tmp + mod) % mod;
    }
    cout << totalWays;
}