/*
Ma trận kề sang danh sách kề, danh sách cạnh
(có hướng).*/


#include<bits/stdc++.h>
using namespace std;


vector<int> p[1001];
int a[1001][1001];
vector<pair<int,int>> pa;

int main(){
    int n;cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]){
                pa.push_back({i,j});
                p[i].push_back(j);
            }
        }
    }

    cout << endl;
    for(auto it : pa){
        cout << it.first << " " << it.second << endl;
    }
    cout << endl;

    for(int i = 1;i<=n;i++){
        cout << i << ": ";
        for(int j : p[i]){
            cout << j << " ";
        }
        cout << endl;
    }
}
