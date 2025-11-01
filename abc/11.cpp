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

int a[maxn];//mang ban dau
int b[maxn];//b[i] = a[i] - m;suay ra tu cong thuc tbc voi m la tbc
int n,k;
int mi[maxn];//gia tr b[i] = a[i] - m,nho nhat tinh den i

bool f(int m){
    FOR1(i,n) b[i] = a[i] - m;
    int sum = 0;
    int sum2 = 0;
    int p = 1;
    FOR1(i,n){
        sum += b[i];
        mi[i] = min(mi[i-1],sum);
    }
    sum = 0;
    FOR1(i,n){
        sum += a[i];//tong day con tinh den i
        sum2 += b[i];//tong cong don (a[i] - m) tinh den i
        while(p < i && sum >= k && sum - a[p] >= k){
            sum -= a[p++];
        }
        //tim dc p la gia tri ben phai lon nhat ma tong [p->i] >= k (cac doan [l->i] voi l thuoc [1->p] deu thoa man >= k)
        if(sum >= k && sum2 - mi[p-1] >= 0) return true;
    }
    return false;
}

void solve(){
    cin >> n >> k;
    FOR1(i,n) cin >> a[i];
    int l = 1,r = 1e9;
    int ans = 0; 
    while(l <= r){
        int m = l + (r - l) / 2;//m nay la tbc
        if(f(m)){
            ans = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    cout << ans << endl;
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