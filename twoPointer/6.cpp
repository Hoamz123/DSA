#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin >> n;
    vector<int> a(n+1,0);
    vector<int> dp(n+1,0);
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        dp[i] = dp[i-1] + a[i];
    }
    int res = 0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int sum = dp[j] - dp[i-1];
            if(sum % 2 == 0){
                //co kha nang dung
                int l = i,r = j-1;//xet trong doan tu i den j
                int half = sum / 2;
                while(l <= r){
                    int mid = l + (r - l) / 2;
                    int tmp = dp[mid] - dp[i-1];
                    if(tmp == half){
                        res = max(res,j - i + 1);
                        break;
                    }
                    else if(tmp < half) l = mid + 1;
                    else r = mid - 1;
                }
            }
        }
    }
    
    cout << res;
    /*
6
2 10 3 2 5 1
    */
}