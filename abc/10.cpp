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


int a[maxn];
int b[maxn];
int n,k;
int mini[maxn];

bool check(int m){
    int sum = 0;
    int sum2 = 0;
    FOR1(i,n){
        b[i] = a[i] - m;
    }
    FOR1(i,n){
        sum += b[i];
        mini[i] = min(mini[i-1],sum);
    }
    sum = 0;
    int p = 1;
    FOR1(i,n){
        sum += a[i];
        sum2 += b[i];
        while(p < i && sum >= k && sum - a[p] >= k){
            sum -= a[p];
            p++;
        }
        if(sum >= k && sum2 - mini[p-1] >= 0){
            return true;
        }
    }
    return false;
}

void solve(){
    cin >> n >> k;
    FOR1(i,n) cin >> a[i];
    int l=0,r = 1e9;
    int res = 0;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(check(m)){
            res = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    cout << res;
}

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