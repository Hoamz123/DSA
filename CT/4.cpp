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


//trong luong W nho 
void solve(){
    int n,W;cin >> n >> W;
    vi w(n + 1,0),v(n + 1,0);
    FOR1(i,n){
        cin >> w[i] >> v[i];
    }
    int dp[W + 1];
    FOR0(i,W + 1) dp[i] = 0;
    for(int i=1;i<=n;i++){
        for(int j=W;j>=w[i];j--){
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[W];
}

void solve2(){
    int n,W;cin >> n >> W;
    vi w(n + 1,0),v(n + 1,0);
    int sum = 0;
    FOR1(i,n){
        cin >> w[i] >> v[i];
        sum += v[i];
    }
    vll dp(sum + 1,INF);
    dp[0] = 0;//dp[0] la can nang khi gia tri  = 0

    FOR1(i,n)for(int j = sum;j >= v[i];j--){
        dp[j] = max(dp[j],dp[j - v[i]] + w[i]);
    }
    //tim maxVal <= W
    int ans = 0;
    for(int i=1;i<=sum;i++){
        if(dp[i] <= W) ans = max(ans,i);
    }
    cout << ans;
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