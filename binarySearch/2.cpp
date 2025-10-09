#include<bits/stdc++.h>
using namespace std;
#define maxn 1e5 + 5
#define ll long long
int n,k;
vector<int> v(maxn, 0);
ll f(int x){
    ll s = 0;
    for(int i=0;i<n;i++){
        s += v[i] / x;
    }
    return s;
}
int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> v[i];
    int l = 0,r = 1e9 + 1;
    while(r - l > 1){
        int m = (l+r)/2;
        if(f(m) >= k) l = m;
        else r = m;
    }
    cout << l;
}