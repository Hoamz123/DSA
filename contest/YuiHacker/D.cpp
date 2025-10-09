#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define nax 1000005
#define mod 1000000007
#define FAST ios::sync_with_stdio(0);cin.tie(0);
#define FOR1(i,n) for(int i=1;i<=(n);i++)
#define FOR(i,n) for(int i=0;i<=(n);i++)
int main(){
    FAST;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n,S;cin >> n >> S;
    vector<int> a(n+1);
    FOR1(i,n) cin >> a[i];
    vector<int> dp(S+1,0);
    dp[0] = 1;//co 1 cach de tao ra tong = 0 -> ko chon gi het
    for(int j=0;j<=S;j++){
        for(int i=1;i<=n;i++){
            if(j >= a[i]){
                dp[j] = (dp[j] + dp[j - a[i]]) % mod;
            }
        }
    }
    cout << dp[S];
    ///chu y bai nay 2 + 2+ 5 !- 5 + 2 + 2 -> se tinh nhieu lan
}