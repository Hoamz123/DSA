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

int n, k;
vi a;
int tb;

bool bt(int idx, vi &bucket, vector<vi> &b){
    if (idx == n){
        for (int i = 0; i < k; i++){
            if (bucket[i] != tb) return false;
        }

        vector<int> group(n);
        for (int i = 0; i < k; i++){
            for (int id : b[i]){
                group[id] = i + 1;
            }
        }
        for(int i=0;i<n;i++){
            cout << group[i] << ' ';
        }
        return true;
    }

    for (int i = 0; i < k; i++){
        if (bucket[i] + a[idx] > tb) continue;

        bucket[i] += a[idx];
        b[i].push_back(idx);

        if (bt(idx+1, bucket, b)) return true;

        b[i].pop_back();
        bucket[i] -= a[idx];

        if (bucket[i] == 0) break;
    }
    return false;
}

void solve(){
    cin >> n >> k;
    a = vi(n);
    int sum = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }

    if (sum % k != 0){
        cout << "ze";
        return;
    }

    tb = sum / k;

    vector<vi> b(k);
    vi bucket(k, 0);

    if (!bt(0, bucket, b)) cout << "ze";
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