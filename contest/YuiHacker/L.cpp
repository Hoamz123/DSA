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
    int n;cin >> n;
    vector<int> a(nax,0);
    int S = 0;
    FOR1(i,n) {
        cin >> a[i];
        S += a[i];
    }
    vector<bool> dp(S+1,false);
    dp[0] = true;
    FOR1(i,n){
        for(int j=S;j>=a[i];j--){
            if(dp[j - a[i]]){//neu nhu co tong j - a[i] roi -> cc se co tong j
                dp[j] = true;//neu viet
                /**
                 * dp[j] = dp[j - a[i]] -> sai vi no se ghi de mat
                 */
            }
        }
    }
    set<int> se;
    for(int i=1;i<=S;i++){
        if(dp[i]) se.insert(i);
    }
    cout << (int)se.size() << endl;
    for(int i : se) cout << i << " ";
}