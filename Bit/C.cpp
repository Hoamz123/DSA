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

// void solve(){
//     //liet ke tat ca cac tap hop con cua n
//     int n = 10;
//     for(int sub = n;sub >= 0;sub--){
//         sub &= n;
//         cout << sub << endl;
//     }
// }


void solve(){
    map<string,int> dp;
    dp["A"] = nax;dp["B"] = nax;
    dp["C"] = nax;
    dp["AB"] = nax;
    dp["AC"] = nax;
    dp["BC"] = nax;
    dp["ABC"] = nax;
    int n;cin >> n;
    FOR0(i,n){
        int c;string str;cin >> c >> str;
        sort(str.begin(),str.end());
        if (c < dp[str]){
            dp[str] = c;
        }
    }
    dp["AB"] = min(dp["AB"],dp["A"] + dp["B"]);
    dp["AC"] = min(dp["AC"], dp["A"] + dp["C"]);
    dp["BC"] = min(dp["BC"], dp["B"] + dp["C"]);
    dp["ABC"] = min({dp["AB"] + dp["AC"],dp["AB"] + dp["BC"],
                dp["AC"] + dp["BC"],
                dp["A"] + dp["B"] + dp["C"],
                dp["AB"] + dp["C"],
                dp["AC"] + dp["B"],
                dp["BC"] + dp["A"],
                dp["ABC"]});
    if(dp["ABC"] == nax) cout << -1 << endl;
    else cout << dp["ABC"] << endl;
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
    // https://codeforces.com/group/FcraNkfhvg/contest/554120/problem/C
    //dit mej toi uu cho bo cai code ban the nay ma de duoc a
}