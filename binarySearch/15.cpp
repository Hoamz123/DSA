#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int> &a,vector<int> &b){
    if(a[0] != b[0]) return a[0] < b[0];
    return a[1] < b[1];
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        vector<vector<int>> ve;
        for(int i=0;i<n;i++){
            int x,y;cin >> x >> y;
            ve.push_back({x,y,0});
        }
        sort(ve.begin(),ve.end(),cmp);
        int times = 0;
        for(int i=0;i<n-1;i++){
            if(ve[i][2]) continue;
            int tmp = ve[i][1];
            times ++;
            for(int j=i+1;j<n;j++){
                if(ve[j][2]) continue;
                if(ve[j][1] >= tmp){
                    ve[j][2] = 1;//danh dau la thuoc cung 1 tap hop
                    tmp = ve[j][1];
                }
            }
        }
        if(ve[n-1][2] != 1) times++;
        cout << times << endl;
    }
    // acc
    // https://oj.vnoi.info/problem/mstick
}

/*
3

5
4 9
5 2
2 1
3 5
1 4

3
2 2
1 1
2 2

3
1 3
2 2
3 1

*/