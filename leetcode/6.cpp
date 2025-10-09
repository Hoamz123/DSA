#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};


void Try(int i,int j,vector<vector<int>> &grid,int m,int n){
    for(int k=0;k<4;k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        while(i1 >= 0 && i1 < m && j1 >= 0 && j1 < n && grid[i1][j1] >= 1){//co nhung o da duoc danh dau la 2 roi -> neu == 1 thi se dung -> mat case
            //Try
            grid[i1][j1] = 2;
            cout << i1 << " " << j1 << endl;
            i1 += dx[k];
            j1 += dy[k];
        }
    }
    //acc
}

int countUnguarded(int m, int n, vector<vector<int>> &g, vector<vector<int>> &w)
{
    vector<vector<int>> a = vector(m,vector<int>(n,1));

    for(auto it : g){
        int i = it[0];int j = it[1];
        a[i][j] = -1;//linh
    }

    for(auto it : w){
        int i = it[0];
        int j = it[1];
        a[i][j] = 0; // tuong
    }

    for(auto it : g){
        int i = it[0];
        int j = it[1];
        Try(i,j,a,m,n);
    }
    
    int cnt = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << a[i][j] << " ";
            if(a[i][j] == 1) cnt++;
        }
        cout << endl;
    }
    return cnt;
}

int main(){
    int m = 4,n = 6;
    vector<vector<int>> g = {{0, 0},{1, 1},{2, 3}};
    vector<vector<int>> w = {{0,1}, {2,2}, {1,4}};
    cout << countUnguarded(m,n,g,w);
}
