#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define nax 1000005
#define mod 1000000007
#define FAST ios::sync_with_stdio(0);cin.tie(0);
int main(){
    FAST;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int n;cin >> n;
    //nho co phan biet thu tu vi du 1 2 khac voi 2 1 -> phai dem 2 lan 
    vector<int> dp(n+1,0);
    dp[0] = 1;//co 1 cach tao tong = 0
    for(int i=0;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(i >= j){
                dp[i] = (dp[i] + dp[i - j]) % mod;
            }
        }
    }
    cout << dp[n];
}