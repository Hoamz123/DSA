#include<bits/stdc++.h>
using namespace std;
#define faster() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define pb push_back
#define is insert
#define mod 1000000007
#define INF 1000000001
#define nax 1000005
#define len length
#define FOR1(i,n) for(int i=1;i<=(n);i++)
#define FOR0(i,n) for(int i=0;i<(n);i++)
#define forxy(i,x,y) for(int i=(x);i<(y);i++);
#define endl '\n'

int n, W, H;
int w[111], v[111];
int dp[111][100011][2];
// dp[i][j][t] = khoi luong nho min (i phan tu dau) (gia tri loi ich j) (t : {0,1} : 0 la chua cam tay : 1 la da cam tay)


void solve(){
    cin >> n >> W >> H;
    int sumVal = 0;
    FOR1(i,n){
        cin >> w[i] >> v[i];
        sumVal += v[i];
    }

    FOR0(i, 111) FOR0(j, 100011) dp[i][j][0] = dp[i][j][1] = INF;
    dp[0][0][0] = 0;

    FOR1(i,n){
        FOR0(j, sumVal + 1){
            FOR0(t, 2){
                if(dp[i-1][j][t] < INF){
                    // //bo qua vat i
                    dp[i][j][t] = min(dp[i][j][t], dp[i-1][j][t]);

                    // nhat vat i
                    if(j + v[i] <= sumVal)
                        dp[i][j + v[i]][t] = min(dp[i][j + v[i]][t], dp[i-1][j][t] + w[i]);

                    // cam vat bang tay
                    if(t == 0 && H >= w[i] && j + v[i] <= sumVal)
                        dp[i][j + v[i]][1] = min(dp[i][j + v[i]][1], dp[i-1][j][0]);
                }
            }
        }
    }

    int ans = 0;
    FOR0(i, sumVal + 1){
        if(min(dp[n][i][0], dp[n][i][1]) <= W){
            ans = max(ans, i);
        }
    }
    cout << ans;
}

int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solve();
    }
    // https://oj.vnoi.info/problem/icpc24_mt_a
}
