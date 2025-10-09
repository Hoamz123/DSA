#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;cin >> n >> k;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin >> a[i];
    int res = -1;
    int cnt = 0;
    for(int r = 0,l=0;r<n;r++){
        cnt += (1 - a[r]);
        while(cnt > k){
            //so phan tu 0 nhieu hon quy dinh -> giam trai
            cnt -= (1 - a[l++]);
        }
        //muc dich tim day con dai nhat chua <=k so 0
        res = max(res,r - l + 1);
    }
    cout << res << endl;
    cerr << (1.0 * clock() / CLOCKS_PER_SEC);
}
/*
11 2
1 1 1 0 0 0 1 1 1 1 0
6
*/
//