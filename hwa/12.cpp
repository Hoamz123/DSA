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

int ucln(int a,int b){
    while(b){
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

ll _pow(ll a, ll b){
    ll res = 1;
    a %= mod;
    while(b){
        if(b & 1) res = (res * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return res;
}

void solve(){
    int n;cin >> n;
    map<int,int> mp;
    for(int i=2;i<=sqrt(n);i++){
        if(n % i == 0){
            int cnt = 0;
            while(n % i == 0){
                cnt++;
                n /= i;
            }
            mp[i] = cnt;
        }
    }
    if(n != 1) mp[n] = 1;
    int res = 1;//tinh tong cac uoc cua n
    for(auto &[fi,se] : mp){
        res *= (_pow(fi,se + 1) - 1) / (fi - 1);
    }
    cout << res;
}


void hamming(){
    vll v = {1};
    int i2 = 0,i3 = 0,i5 = 0;
    while(true){
        ll next2 = v[i2] * 2;
        ll next3 = v[i3] * 3;
        ll next5 = v[i5] * 5;
        ll next = min({next2,next3,next5});
        if(next > 1e18) break;
        v.push_back(next);
        if(next == next2) i2++;
        if(next == next3) i3++;
        if(next == next5) i5++;
    }
    int q;cin >> q;
    while(q--){
        ll m;cin >> m;
        auto it = lower_bound(v.begin(),v.end(),m);
        if(it == v.end() || *it != m) cout << -1 << endl;
        else{
            cout << it - v.begin() + 1 << endl;
        }
    }
}

void hamming2(){
    vi prime = {2,3,5};
    vi idx(3,0);
    vll v = {1};
    while(true){
        ll next = LLONG_MAX;
        for(int i = 0;i<3;i++){
            next = min(next,prime[i] * v[idx[i]]);
        }
        if(next > 1e18) break;
        v.push_back(next);
        for(int i=0;i<3;i++){
            if(next == prime[i] * v[idx[i]]) idx[i]++;
        }
    }
    int q;cin >> q;
    while(q--){
        ll m;cin >> m;
        auto it = lower_bound(v.begin(),v.end(),m);
        if(it == v.end() || *it != m) cout << -1 << endl;
        else cout << it - v.begin() + 1 << endl;
    }
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;cin >> t;
    while(t--){
        hamming2();
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