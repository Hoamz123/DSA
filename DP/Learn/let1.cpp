#include<bits/stdc++.h>
using namespace std;

//so cach di tu top-left den bottom right
//moi buoc di xuong or sang phai

int a[101][101];
int uniquePaths(int m, int n) {
    for(int i=0;i<n;i++){
        a[0][i] = 1;
    }
    for(int j=1;j<m;j++){
        a[j][0] = 1;
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            a[i][j] += (a[i-1][j] + a[i][j-1]);
        }
    }
    return a[m-1][n-1];
}
int main(){
    cout << longestValidParentheses("(())()");
}