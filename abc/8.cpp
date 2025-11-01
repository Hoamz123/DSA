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

void solve(){
    int n;cin >> n;
    vi a(n + 5,0);
    FOR1(i,n) cin >> a[i];
    vi b = a;
    FOR1(i,n) a[i] += a[i-1];
    unordered_map<ll,int> mp;
    int idxSt = 0;
    int ans = -1;
    for(int i=1;i<=n;i++){
        mp.clear();int l = 1,r = n;
        while(l <= i){
            int sum = a[i] - a[l-1];
            mp[sum] = l;
            l++;
        }
        while(r > i){
            int sum = a[r] - a[i];
            if(mp.count(sum)){
                ans = max(ans,r - mp[sum] + 1);
                if(ans == r - mp[sum] + 1){
                    idxSt = mp[sum];
                }
            }
            r--;
        }
    }
    for(int i=0;i<ans;i++){
        cout << b[idxSt + i] << ' ';
    }
    cout << endl;
    cout << ans;
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