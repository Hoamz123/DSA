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

int spf[maxn];

//sang phan tich thua so nguyen to
void seivef(){
    FOR1(i,maxn) spf[i] = i;

    for(int i=2;i * i  < maxn;i++){
        if(spf[i] == i){
            for(int j = i * i;j< maxn;j+=i){
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

int getX(int a,int i){
    return (pow(a,i + 1) - 1) / (a - 1);
}
void solve(){
    seivef();
    int n;
    cin >> n;
    map<int,int> mp;
    while(n > 1){
        int p = spf[n];
        if(n % p == 0){
            int cnt = 0;
            while(n % p == 0){
                cnt++;
                n /= p;
            }
            mp[p] = cnt;
        }
    }

    if(n != 1) mp[n] = 1;
    int sum = 1;
    for(auto [k,v] : mp){
        sum *= getX(k,v);
    }
    cout << sum << endl;//sum la tong so uoc cua n 
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