#include<bits/stdc++.h>
using namespace std;
#define faster() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define umii unordered_map<int,int>
#define si set<int>
#define pb push_back
#define is insert
#define mod 1000000007
#define INF 1000000001
#define nax 1000005
#define FOR1(i,n) for(int i=1;i<=(n);i++)
#define FOR0(i,n) for(int i=0;i<(n);i++)
#define forxy(i,x,y) for(int i=(x);i<(y);i++);
#define endl '\n'


//cho 1 xau S moi buoc ban co the chen 1 ki tu vao bat ki vi tri nao de tao thanh xau doi xung


void solve() {
    string s;
    int n;
    cin >> n >> s;
    vector<vi> dp(n,vi(n,0));
    for(int len = 2;len <= n;len ++){
        for(int i=0;i<n - len  +1;i++){
            int j = i + len - 1;
            if(s[i] == s[j]){
                dp[i][j] = dp[i+1][j-1];
            }
            else{
                dp[i][j] = min(dp[i][j-1],dp[i+1][j]) + 1;
            }
        }
    }
    cout << dp[0][n-1];
    //acc
}


int main(){
    faster();
    int t = 1;
    while (t--) {
        solve();
    }
}
