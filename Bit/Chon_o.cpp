//https://oj.vnoi.info/problem/qbselect
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

void solve(){
    //chaun bi (4 hang vi du 0101 : chon o o hang 1 va hang 3)
    vi ve(16);
    FOR0(i,16){
        int ok = 1;
        FOR0(j,3){//j : {0,1,2}
            if(((i >> j) & 1) && ((i >> (j+1)) & 1)){
                ok = 0;
            }
        }
        ve[i] = ok;
    }
    int n;cin >> n;
    vector<vi> a(4,vi(n+1));
    int cntN = 0;//dem so luong so 0
    int M = -INF;/*phong case so am lon nhat(mang toan so 0)*/
    FOR0(i,4){
        FOR0(j,n) {
            cin >> a[i][j];
            M = max(M,a[i][j]);
            if(a[i][j] < 0) cntN++;
        }
    }
    if(cntN == 4 * n){
        cout << M << endl;
        return;
    }
    vector<vi> dp(16,vi(n+1,-INF));//dp[i][j] : tong lon nhat tai cot j khi chon mask i
    FOR0(i,n){
        FOR0(j,16){
            if(ve[j]){
                //tinh tong cua cot nay
                int sum = 0;
                FOR0(k,4){
                    //neu nhu bit thu k la bit 1 thi cong gia tri tai a[k][i]
                    if((j >> k) & 1){
                        sum += a[k][i];
                    }
                }
                if(i == 0){
                    dp[j][i] = sum;
                }
                else{
                    FOR0(k,16){
                        //neu nhu k la mot mask hop le(0 co hai bit 1 gan nhau va k,j la hai mask tai hai cot i va i - 1 ko co hai bit 1 tai vi tri giong nhau(tranh case hai cot nhung chon chung hang))
                        if(ve[k] && ((k & j) == 0)){
                            dp[j][i] = max(dp[j][i],dp[k][i-1] + sum);
                        }
                    }
                }
            }
        }
    }
    int ans = -INF;
    FOR0(i,16){
        ans = max(ans,dp[i][n-1]);
    }
    cout << ans;
}


int main(){
    faster();
    int t = 1;
    while(t--){
        solve();
        //acc
    }
    
}