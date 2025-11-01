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

//tim doan con dai nhat ma cac phan tu chi xuat hien nhieu nhat 1 lan
void solve(){
    int n;cin >> n;
    vi a(n + 2,0);
    FOR1(i,n) cin >> a[i];
    a[n + 1] = a[0];
    int ans = 1;
    int l = 1;
    int idx = 0;
    unordered_map<int,int> mp;
    FOR1(r,n + 1){
        if(mp.count(a[r]) == 0){
            //chua xuat hien -> luu vao
            mp[a[r]] = 1;
        }
        else{
            //neu da gap roi
            ans = max(ans,r - l);
            if(ans == r - l){
                //banwg gia tri vua gan chung to ln nhat
                idx = l;
            }
            while(l < r && mp[a[r]] != 0){
                mp[a[l++]] = 0;
            }
            mp[a[r]] = 1;
        }
    }
    for(int i=0;i<ans;i++) cout << a[idx + i] << ' ';
    cout << endl;
    cout << ans;
}

void solve2(){
    int n;cin >> n;
    vi a(n + 2,0);
    FOR1(i,n) cin >> a[i];
    map<int,int> mp;
    int ans = 0;
    int L = 1,sl = 0;
    FOR1(r,n){
        mp[a[r]]++;
        if(mp[a[r]] > 1) sl++;
        while(sl != 0){
            mp[a[L++]]--;
            if(mp[a[L]] == 1) sl--; 
        }
        if(sl == 0){
            ans = max(ans,r - L + 1);
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
        solve2();
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