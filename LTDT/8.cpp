// Ma trận trọng số sang danh sách cạnh

#include<bits/stdc++.h>
using namespace std;

vector< pair<pair<int,int>,int>> p;

int a[1001][1001];
int main(){
    int n;cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin >> a[i][j];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j] != 0){
                if(i < j){
                    p.push_back({{i,j},a[i][j]});
                }
            }
        }
    }
    cout << endl;
    for(auto it : p){
        cout << it.first.first << " " << it.first.second <<" " << it.second << endl;
    }
}