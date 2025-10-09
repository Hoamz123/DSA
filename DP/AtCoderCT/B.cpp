#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0);cin.tie(0);
#define INF 1000000001
int main(){
    int n,k;cin >> n >> k;
    vector<int> a(n,0);
    for(int &x : a) cin >> x;
    vector<int> f(n+1,INF);
    f[0] = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=i+k;j++){
            if(j < n){
                f[j] = min(f[j],f[i] + abs(a[i] - a[j]));
            }
        }
    }
    cout << f[n-1];
    //acc
}