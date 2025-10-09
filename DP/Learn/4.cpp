#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0);cin.tie(0);
//tim xau con doi xung dai nhat khong nhat thiet phai lien tuc

int main(){
    FAST;
    string s = "";
    cin >> s;
    int n = s.size();
    vector<vector<int>> f(n+1,vector<int>(n+1));
    for(int i =0;i<n;i++) f[i][i] = 1;//xau con co dung 1 ki tu thi doi xung
    for(int len =2;len <= n;len ++){
        for(int i=0;i<n - len + 1;i++){
            int j = len + i - 1;
            //neu ki tu dau giong nhu ki tu cuoi
            if(s[i] == s[j]){
                f[i][j] = f[i+1][j-1] + 2;
            }
            else{
                f[i][j] = max(f[i+1][j],f[i][j-1]);
            }
        }
    }
    cout << f[0][n-1];//xau con doi xung dai nhat co duong tinh tu index = 0 den index = n-1
}


/*
LPSABPL
result = 5
LPSPL
*/