#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,target;cin >> n >> m >> target;
    int a[n+1][m+1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) cin >> a[i][j];

    int i = 1,j = m;
    while(i <= n && j > 0){
        if(a[i][j] == target){
            cout << i << " " << j;
            return 0;
        }
        else if(a[i][j] < target) i++;
        else j--;
    }
    cout << -1;
    return 0;
}

/*
5 5 14
1 4 7 11 15
2 5 8 12 19
3 6 9 16 22
10 13 14 17 24
18 21 23 26 30
*/