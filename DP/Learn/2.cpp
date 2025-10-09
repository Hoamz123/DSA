#include<bits/stdc++.h>
using namespace std;
//so cach chon dong xu de tong  = S (cac dong xu chon nhieu lan)
int main(){
    int n,S;cin >> n >> S;
    vector<int> a(n,0);
    for(int &x : a) cin >> x;
    vector<int> f(S+1,0);
    f[0] = 1;//co 1 cach chon tong dong xu = 0 (la ko chon gi)
    for(int i=0;i<n;i++){
        for(int j=a[i];j<=S;j++){
            f[j] += f[j - a[i]];
        }
    }
    cout << f[S];
}
/*
3 5
1 2 5
*/