#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST ios::sync_with_stdio(0);cin.tie(0);
int main(){
    int n;cin >> n;
    vector<int> dp(3);//dp[i] : tong so hanh phuc lon nhat neu ngay hom truoc chon i
    for(int i=0;i<n;i++){
        vector<int> new_dp(3,0);
        vector<int> c(3,0);
        for(int i=0;i<3;i++) cin >> c[i];
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i != j){
                    //i la lan chon truoc do
                    //j la lan chon hien tai
                    new_dp[j] = max(new_dp[j],dp[i] + c[j]);
                }
            }
        }
        dp = new_dp;
    }
    cout << max({dp[0],dp[1],dp[2]});
}
/*
7
6 7 8
8 8 3
2 5 2
7 8 6
4 6 8
2 3 4
7 5 1
46
*/