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


//so buoc it nhat de bien doi xau s thanh xau t

void solve() {
    string s,t;cin >> s >> t;
    int n = s.size();int m = t.size();
    s = "1" + s;
    t = "1" + t;
    vector<vi> dp(n+1,vi(m+1,INF));//dp[i][j] so cach it nhat bien xau si thanh xau tj
    dp[0][0] = 0;//can 0 buoc de tu xau 0 thanh xau 0
    FOR1(i,n) dp[i][0] = i;//can i buoc de tu xau rong thanh xau i
    FOR1(i,m) dp[0][i] = i;//can i buoc de tu xau rong thanh xau i
    FOR1(i,n) FOR1(j,m){
        //case 1
        if(s[i] == t[j]){
            dp[i][j] = min(dp[i][j],dp[i-1][j-1]);//hai mut ngoai bang nhau -> so buoc thanh so buoc cua [i-1][j-1]
        }
        //case 2
        else{
            dp[i][j] = min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]}) + 1;//them 1 buoc nua
        }
    }
    cout << dp[n][m];
}


int main(){
    faster();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solve();
        //acc
    }
    
}
