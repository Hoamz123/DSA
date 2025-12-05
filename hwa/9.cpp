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

bool check(int i,int j,int k){
    if((i ^ j) && (i ^ k) && (k ^ j)) return 1;
    return 0;
}

vi a;
vi used;
void Try(int idx,const int n){
    if(idx == n){
        for(int i : a) cout << i << ' ';
        cout << endl;
        return;
    }
    for(int i=1;i<=n;i++){
        if(used[i] == 0){
            a.push_back(i);
            used[i] = 1;
            Try(idx + 1,n);
            a.pop_back();
            used[i] = 0;
        }
    }
}

void solve(){
    int n;cin >> n;
    a.clear();
    used = vector<int> (n + 1,0);
    Try(0,n);

    // for(int mask = 0;mask < (1 << n) ;mask ++){
    //     for(int i=n-1;i>=0;i--){
    //         cout << ((mask >> i) & 1) << ' ';
    //     }
    //     cout << endl;
    // }
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