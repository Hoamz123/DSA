//dem so duong di tu o [1,1] -> [n,m] ma khong di qua o co bom

#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1e9 + 7;//la snt
const int maxN = 1000001;

ll fact[maxN];//tinh giai thua
ll invFact[maxN];//tinh mod nghich dao
//cong thuc can nho
/**
 * nghich dao mod cua n voi mod p duoc tinh = cong thuc : (n ^ (p-2)) % p;cong thuc fertman nho
 * gia su ta co nghich dao modun cua i+1 -> nghich dao modun cua i = (nghich dao modun cua i+1 * (i+1)) % p;
 * nCk mod p : duoc tinh bang cong thuc : n! * nghich dao modun cua ((k!) % p) * nghich dao modum cua ((n-k)!) % p
 */

//ham tinh nghich dao modun
ll power(ll x,ll y){
    //x ^ y % p;
    x = x % mod;
    ll res = 1;
    while(y > 0){
        if(y & 1) res = (res * x) % mod;
        y = y >> 1;///chia doi lay phan nguyen duoi
        x = (x * x) % mod;
    }
    return res;
}

void setUp(){
    //tinh giai thua
    fact[0] = 1;
    for(int i = 1;i<maxN;i++){
        fact[i] = (fact[i-1] * i) % mod;
    }
    //tinh nghich dao modun tu 1 den maxN-1!
    invFact[maxN - 1] = power(fact[maxN - 1],mod - 2);
    for(int i = maxN - 2;i>=0;i--){
        invFact[i] = (invFact[i+1] * (i+1)) % mod;
    }
}

ll nCk(int n,int k){
    if(k > n) return 0;
    return (fact[n] * invFact[k] % mod) * invFact[n - k] % mod;
}

int main(){
    setUp();
    int n,m,k;cin >> n >> m >> k;
    vector<pair<int,int>> adj;
    for(int i = 0;i<k;i++){
        int x,y;cin >> x >> y;
        adj.push_back({x,y});
    }

    sort(adj.begin(),adj.end());

    vector<ll> dp(k,0);//luu so duong ti tu [1,1] -> [x,y]

    for(int i = 0;i<k;i++){
        int x = adj[i].first;int y = adj[i].second;
        dp[i] = nCk(x + y - 2,x - 1);
        for(int j = 0;j<i;j++){
            int x1 = adj[j].first;int y1 = adj[j].second;
            if(x1 <= x && y1 <= y){
                ll tmp = dp[j] * nCk(x - x1 + y - y1,x - x1) % mod;
                dp[i] = (dp[i] - tmp + mod) % mod;
            }
        }
    }

    ll res = nCk(n + m - 2,n - 1);
    for(int i = 0;i<k;i++){
        int x = adj[i].first;int y = adj[i].second;
        ll tmp = (dp[i] * nCk(n - x + m - y,n - x)) % mod;
        res = (res - tmp + mod) % mod;
    }
    cout << res;
    return 0;
}

