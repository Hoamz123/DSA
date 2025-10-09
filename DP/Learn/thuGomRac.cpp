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
#define nax 1000005
#define FOR1(i, n) for (int i = 1; i <= (n); i++)
#define FOR0(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define PER(i, a, b) for (int i = a; i >= b; --i)
#define endl '\n'
#define fi first
#define se second

void solve(){
    int n,m;cin >> n >> m;
    vector<vi> a(n+1,vi(m+2,-INF));
    FOR1(i,n) FOR1(j,m) cin >> a[i][j];
    vector<vi> dp(n+1,vi(m+2,-INF));//dp[i][j] la sum lon nhat dat duoc tai hang i cot j
    vi ans(n+1,0);
    FOR1(i,n) {
        dp[i][0] = -INF;
        dp[i][m+1] = -INF;
    }
    FOR1(i,m) dp[1][i] = a[1][i];
    REP(i,2,n){
        FOR1(j,m){
            dp[i][j] = max({dp[i-1][j],dp[i-1][j-1],dp[i-1][j+1]}) + a[i][j];
        }
    }

    int col = 0;
    int maxTemp = -INF;
    FOR1(i,m){
        if(dp[n][i] > maxTemp){
            maxTemp = dp[n][i];
            col = i;
        }
    }
    cout << maxTemp << endl;

    int i = n,j = col;

    while(i > 0){
        ans[i] = j;
        if(dp[i-1][j] >= dp[i-1][j-1] && dp[i-1][j] >= dp[i-1][j+1]) i--;
        else if(dp[i-1][j-1] >= dp[i-1][j] && dp[i-1][j-1] >= dp[i-1][j+1]){
            i--;j--;
        }
        else{
            i--;j++;
        }
    }
    //ans[1] = j;
    FOR1(i,n) cout << ans[i] << ' ';
}

int main(){
    faster();
    int t = 1;
    while(t--){
        solve();
    }
}
/*
5 4
4 5 2 4
3 4 5 2
3 4 5 2
5 6 3 5
4 5 2 5
*/

/*
out
26
2 3 3 2 2 */