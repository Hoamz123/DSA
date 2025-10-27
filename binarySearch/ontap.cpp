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

//on lai fetman nho de tinh nCk

//tinh x mu y mod 1e9 + 7

ll fact[maxn];
ll inFact[maxn];//inFact[i] la ndmd cua i!
ll _pow(ll x,ll y){
    ll res = 1;
    x %= mod;
    while(y){
        if(y & 1) res = (res * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return res;
}

void setUp(){
    //tinh giai thua
    fact[0] = 1;//0! = 1
    for(int i=1;i<maxn;i++){
        fact[i] = (fact[i-1] * i) % mod;
    }
    inFact[maxn - 1] = _pow(fact[maxn - 1],mod - 2);//nghich dao modulo cua n mod p dc tinh = n mu p - 2 mod p
    for(int i = maxn - 2;i>=0;i--){
        inFact[i] = (inFact[i + 1] * (i + 1)) % mod;
    }
}

ll nCk(int n,int k){
    if(k > n) return -1;
    return (fact[n] * inFact[k] % mod) * inFact[n-k] % mod;
}

void solve(){
    string s = "ABA";
    int n = s.size();
    int pre[n];
    pre[0] = (s[0] == 'A') ? 1 : -1;
    for(int i=1;i<n;i++){
        pre[i] = pre[i-1] + ((s[i] == 'A') ? 1 : -1);
    }
    int ans = 0;
    unordered_map<int,int> mp;
    for(int i = 0;i<n;i++){
        if(pre[i] == 0) ans ++;//xau dai tu 0
        ans += mp[pre[i]];
        mp[pre[i]]++;//gap lan thu (cu + 1)
    }
    cout << ans;
}


/*
int pre[n];
    pre[0] = (s[0] == 'A') ? 1 : -1;
    for(int i=1;i<n;i++){
        pre[i] = pre[i-1] + ((s[i] == 'A') ? 1 : -1);
    }
    unordered_map<int,int> mp;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(pre[i] == 0) ans++;
        ans += mp[pre[i]];
        mp[pre[i]]++;
    }
    cout << ans;
*/
int main(){
    faster();
    solve();
}
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .'  \|     |// '.
//                 /  \|||  :  |||// \.
//                / _||||| -:- |||||- \.
//               |   |  \  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//            ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//           Phật phù hộ, không bao giờ BUG
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~