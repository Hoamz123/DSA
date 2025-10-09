#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        vector<int> a(n,0);
        for(int &x : a) cin >> x;
        int cnt = 0;
        for(int i=0;i<n;i++){
            cnt += (abs(a[i]) < abs(a[0]));
        }
        if(cnt <= n/2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

/*

4
4 2 0 -5

//-> co the sua thanh : -5 -4 0 2 -> khi do -4 la mid
4
-5 0 4 3
ko the thao tac de -5 (5) thanh mid
*/