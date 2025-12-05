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


int p[maxn];
void seive(){
    FOR0(i,maxn) p[i] = 1;
    p[1] = p[0] = 0;
    for(int i=2;i<=sqrt(maxn);i++){
        if(p[i]){
            for(int j = i * i;j<maxn;j+=i) p[j] = 0;
        }
    }
}

ll maxll(ll a,ll b){
    if(a > b) return a;
    return b;
}

vll snt;
//lay ra dung n so nguyen to trong doan L-R
void sieveLR(ll l,ll r,int n){
    int p[r - l + 1];
    FOR0(i,r - l + 1) p[i] = 1;

    for(ll i=2;i<=r;i++){
        for(ll j = maxll(i * i,(l + i - 1) / i * i);j <= r;j+=i){
            p[j - l] = 0;
        }
    }
    for(ll i = maxll(l,2);i<=r;i++){
        if(p[i-l]){
            if((int)snt.size() < n) snt.push_back(i);
        }
    }
}

ll _pow(ll a, ll b){
    ll res = 1;
    a %= mod;
    while(b){
        if(b & 1) res = (a * res) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return res;
}

void solve(){
    int l,r;cin >> l >> r;
    sieveLR(l,r,10);
    for(ll val : snt) cout << val << ' ';
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;cin >> t;
    while(t--){
        solve();
    }
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