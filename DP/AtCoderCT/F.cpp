#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    string s,t;cin >> s >> t;
    int n = s.size();int m = t.size();
    vector<vector<int>> f(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1] == t[j-1]){
                f[i][j] = f[i-1][j-1] + 1;
            }
            else{
                f[i][j] = max(f[i-1][j],f[i][j-1]);
            }
        }
    }
    // cout << f[n][m] << endl;
    string ans = "";
    int i = n,j = m;
    //suyet nguoc tu sau ve truoc
    while(i > 0 && j > 0){
        if(s[i-1] == t[j-1]){
            ans = s[i-1] + ans;
            i--;j--;
        }
        else if(f[i-1][j] > f[i][j-1]) --i;
        else --j;
    }
    cout << ans;
}