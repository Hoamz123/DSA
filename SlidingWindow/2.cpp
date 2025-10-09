#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0);cin.tie(0);
int main(){
    FAST;
    int t;cin >> t;
    while(t--){
        int n,k;cin >> n >> k;
        vector<int> a(n,0);
        int cnt = 0; // den so pt <= k
        for(int  &x : a){
            cin >> x;
            if(x <= k) cnt++;
        }
        int res = 0;//muc dich se luu so luong so <= k lon nhat trong 1 doan dai cnt
        for(int i=0;i<cnt;i++){
            if(a[i] <= k){
                res++;
            }
        }
        int ans = res;
        for(int i=cnt;i<n;i++){
            if(a[i - cnt] <= k) res--;//bo di
            if(a[i] <= k) res++;//vua moi them vao
            ans = max(res,ans);
        }
        cout << cnt - ans << endl;
    }
}