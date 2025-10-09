#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin >> t;
    while(t--){
        int n,x;cin >> n >> x;
        vector<int> a(n,0);
        vector<int> b(n,0);
        for(int i=0;i<n;i++) {
            cin >> a[i];
            b[i] = a[i];
            a[i] = (a[i] == -1) ? x : a[i];
        }
        sort(a.begin(),a.end());
        int mid = (n - 1) / 2;
        if(a[mid] == x){
            cout << "YES" << endl;
            for(int i=0;i<n;i++){
                if(b[i] == -1) cout << x <<  " ";
                else cout << b[i] << " ";
            }
            cout << endl;
        }
        else cout << "NO" << endl;
    }
    //acc
}