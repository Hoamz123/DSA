#include<bits/stdc++.h>
using namespace std;
#define faster() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define mod 1000000007
#define INF 1000000001
#define maxn 1000005
#define FOR1(i, n) for (int i = 1; i <= (n); i++)
#define FOR0(i, n) for (int i = 0; i < (n); i++)
#define endl '\n'
int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};

int spf[maxn];

void seive(){
    FOR1(i,maxn) spf[i] = i;
    for(int i=2;i * i < maxn;i++){
        if(spf[i] == i){
            for(int j = i * i;j<maxn;j+=i){
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

void solve(){
    seive();
    int n;cin >> n;
    vector<pii> mp;

    while(n > 1){
        int p = spf[n];
        if(n % p == 0){
            int cnt = 0;
            while(n % p == 0){
                cnt++;
                n /= p;
            }
            mp.pb({p,cnt});
        }
    }

    int ans = 1;
    for(auto &[p,cnt] : mp){
        ans *= ((pow(p,cnt + 1) - 1) / (p - 1));
    }
    cout << ans;
}

int main(){
    faster();
    int t = 1;
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