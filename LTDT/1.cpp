//chuyen tu dnh sach canh sang ma tran ke
#include<bits/stdc++.h>
using namespace std;
//chuyen tu danh scah canh sang mtr ke
int main(){
    int n,m;cin >> n >> m;
    //n dinh - m canh
    int a[n+1][n+1];
    memset(a,0,sizeof(a));

    int x,y;
    for(int i=1;i<=m;i++){
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << a[i][j]<< " ";
        }
        cout << endl;
    }
}
/*
5 4
2 5
4 1
4 2
4 3
*/