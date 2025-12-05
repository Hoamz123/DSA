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
    int n,k;cin >> n >> k;
    vi a(n,0);
    FOR0(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    int ans = 0;
    //case 1'
    if(n == 1){
        int aa = a[0];
        if(aa > k){
            ans = k * (2 * aa + k - 1) / 2;
        }
        else {
            int T = k / aa;
            int r = k % aa;
            ans += T * (aa * (aa + 1) / 2);
            if(r){
                ans += r * (2 * aa - r + 1) / 2;
            }
        }
    }
    else{
        int M1 = a[n-1];
        int M2 = a[n-2];
        //M1 >= M2
        if(M1 == M2){
            ans = k * M1;
            //nghe M1 -> Nghe M2
        }
        else{
            int cnt = M1 - M2 + 1;//nghe tu M1 den khi giam xuong = M2
            //so luong chu ki
            int T = k / cnt;
            int r = k % cnt;//r < cnt ma cnt <= M1
            ans = T * ((M1 - M2 + 1) * (M1 + M2) / 2);
            //nghe them r lan nua
            ans += r * (2 * M1 - r + 1) / 2;
        }
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