#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a,vector<int> &b){
    if(a[0] != b[0]) return a[0] < b[0];
    return a[1] < b[1];
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin >> n;
    vector<vector<int>> a;
    for(int i=0;i<n;i++){
        int w,il,p;
        cin >> w >> il >> p;
        a.push_back({w,il,p});
    }
    sort(a.begin(),a.end(),cmp);
    int res = -1e9;
    vector<int> dp(n,0);//dp[i] la day con co tong lon nhat ket thuc tai i
    for(int i=0;i<n;i++){
        dp[i] = a[i][2];
        for(int j=0;j<i;j++){
            if(a[j][1] <= a[i][1]){
                dp[i] = max(dp[i],dp[j] + a[i][2]);
            }
        }
        res = max(res,dp[i]);
    }
    cout << res;
    //acc
}

/*
7
2000 13 40
2000 17 50
2100 11 50
2300 7 10
2500 6 20
2600 9 15
2800 13 40
*/