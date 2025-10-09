#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,W;cin >> n >> W;
    vector<int> a(n+1,0);
    vector<int> w(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int j=1;j<=n;j++) cin >> w[j];

    int f[101][101] = {0};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            //co the lay a[i]
            if(a[i] <= j){
                //f[i][j] = max(lay,khong lay);
                f[i][j] = max(f[i-1][j - a[i]] + w[i],f[i-1][j]);
            }
            //khong lay
            else{
                f[i][j] = f[i-1][j];
            }
        }
    }
    cout << f[n][W];
}

/*
8 20
1 7 6 4 5 2 3 9
1 5 6 5 4 3 3 1

*/