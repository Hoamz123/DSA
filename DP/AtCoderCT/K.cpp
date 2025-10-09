#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;cin >> n >> k;
    vector<int> a(n,0);
    for(int &x : a) cin >> x;
    vector<bool> dp(k+1,0);
    for(int i=0;i<=k;i++){
        for(int x : a){
            if(i >= x && !dp[i-x]){//neu so da con bayh la i va ton tai 1 cachs chon de i-x -> sai
                dp[i] = true;
            }
        }
    }
    if(dp[k]) cout << "First";
    else cout << "Second";
    //acc
}