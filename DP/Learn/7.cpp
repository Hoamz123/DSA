//tinh so tao lon nhat co duoc
#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0);cin.tie(0);

int a[1001][1001];
int res[1001][1001];
int n,m;
int main(){
    cin >> n >> m;
    for(int i = 1;i<=n;i++)
        for(int j=1;j<=m;j++) cin >> a[i][j];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            res[i][j] = max(res[i-1][j],res[i][j-1]) + a[i][j];
        }
    }
    cout << res[n][m];
}


/*

5 5
1 2 8 9 10
11 22 78 11 3
100 7 16 22 1
11 77 88 9 4
9 10 1 45 4
 -> 346
*/
