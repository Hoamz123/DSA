/*
Danh sách cạnh sang ma trận kề (vô hướng).*/
#include<bits/stdc++.h>
using namespace std;

int a[1001][1001];

int main(){
    int n,m;cin >> n >> m;
    for(int i=1;i<=m;i++){
        int x,y;cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    cout << endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cout << a[i][j] << " ";
        cout << endl;
    }
}