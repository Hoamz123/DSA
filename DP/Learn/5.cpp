#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0);cin.tie(0);

//xau con lien tiep doi xung dai nhat

int main(){
    string s;cin >> s;
    int n = s.size();
    bool f[n+1][n+1] = {false};
    for(int i=0;i<n;i++) f[i][i] = true;//xau con do dai 1 thoa man doi xung
    int ans = 1;
    string res = "";
    for(int len = 2;len <= n;len ++){
        for(int i=0;i<n-len+1;i++){
            int j = len + i - 1;
            //neu xau con co 2 phan tu
            if(len == 2){
                f[i][j] = (s[i] == s[j]);
            }
            else{
                f[i][j] = (s[i] == s[j] && f[i+1][j-1]);//xau con thoa man dai nhat trong doan i;j hay khong phu thuoc vao dieu kien
            }
            if(f[i][j]){
                if(len > ans){
                    ans = len;
                    res = s.substr(i,len);
                }
            }
        }
    }
    cout << ans << endl;
    cout << res;
}

/*
LPSP11234
result ; PSP
ok
*/