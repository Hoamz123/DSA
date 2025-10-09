#include<bits/stdc++.h>
using namespace std;

//van la so cach chon dong xu nhung ma chon 1 lan

int main(){
    int n,S;cin >> n >>S;
    vector<int> a(n,0);
    for(int &x : a) cin >> x;
    vector<int> f(S+1,0);
    f[0] = 1;
    for(int i=0;i<n;i++){
        for(int j=S;j>=a[i];j--){
            f[j] += f[j-a[i]];
        }
    }
    cout << f[S];
}
/*
/ok

3 5
1 2 5

*/