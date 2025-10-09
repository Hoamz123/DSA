#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0);cin.tie(0);
int main(){
    FAST;
    int n;cin >> n;
    vector<int> a(n,0);
    vector<int> dp(n,0);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if(i == 0) dp[i] = a[i];
        else dp[i] = dp[i-1] + a[i];
    }
    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int haft = dp[j] - dp[i-1];
            if(haft % 2 == 0){
                int l = i,r = j;//xet trong doan tu i den j
                haft /= 2;
                while(l <= r){
                    int mid = (l+r) / 2;
                    int tmp = dp[mid] - dp[i-1];
                    if(tmp == haft){
                        res= max(res,j - i + 1);
                        break;
                    }
                    else if(tmp < haft) l = mid + 1;
                    else r = mid - 1;
                }
            }
        }
    }
    cout << res;
}