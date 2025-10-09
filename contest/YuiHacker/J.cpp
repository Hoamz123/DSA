#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nax 1000005
#define mod 1000000007
#define M -1000000001
#define FAST ios::sync_with_stdio(0);cin.tie(0);
#define FOR1(i,n) for(int i=1;i<=(n);i++)
#define FOR(i,n) for(int i=0;i<=(n);i++)
int main(){
    FAST;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n,S;
    cin >> n >> S;
    vector<ll> w(nax,0);
    vector<ll> v(nax,0);
    FOR1(i,n){
        cin >> w[i] >> v[i];
    }
    vector<ll> dp(nax,0);//dp[i] la gia tri lon nhat co dc khi mang trong luong i
    FOR1(i,n){
        for(int j=S;j>=w[i];j--){
            dp[j] = max(dp[j],dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[S];
}