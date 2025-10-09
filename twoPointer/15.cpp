#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;cin >> n >> k;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin >> a[i];
    int cnt = 0;
    sort(a.begin(),a.end());
    for(int i=0,j=0;j<n;j++){
        if(a[j] - a[i] > k){
            cnt++;
            i = j;
        }
    }
    cout << cnt;
}
/*
5 3
5 4 7 2 15
*/
