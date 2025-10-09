#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nax 1000005
#define FAST ios::sync_with_stdio(0);cin.tie(0);

//ton tai day con khong can lien tiep co tong = s

// int main(){
//     FAST;
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
//     int n,S;cin >> n >> S;
//     vector<int> a(n+1);
//     for(int i=1;i<=n;i++) cin >> a[i];
//     vector<vector<bool>> dp(n+1,vector<bool>(S+1,0));
//     // dp[i][j] : true or false : co ton tai day con trong khoang tu [1->i] de tao thanh tong j hay khong
//     dp[0][0] = true;//co cach de tu 0->0 tao tong = 0(trongg)
//     for(int i=1;i<=n;i++){
//         for(int j=0;j<=S;j++){
//             //co the nhat a[i] vao sum
//             if(j >= a[i]){
//                 dp[i][j] = dp[i-1][j - a[i]];
//             }
//             //khong the nat a[i] vao sum
//             else{
//                 dp[i][j] = dp[i-1][j];
//             }
//         }
//     }
//     cout << dp[n][S];
// }

int main(){
    FAST;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n,S;cin >> n >> S;
    vector<int> a(n+1);
    vector<int >vet(S+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<bool> dp(S+1,0);
    dp[0] = true;//dp[i] la co the tao ra tong = i hay khong
    for(int i=1;i<=n;i++){
        for(int j=S;j>=a[i];j--){
            if(dp[j-a[i]]){
                dp[j] = true;
                if(vet[j] == 0) vet[j] = i;
            }
        }
    }
    if(!dp[S]) cout << "!OK";
    else{
        cout << dp[S] << endl;
        int j = S;
        vector<int> res;
        while(j > 0){
            res.push_back(vet[j]);
            j = j - a[vet[j]];
        }
        for(int i : res){
            cout << a[i] << " ";
        }
    }
}