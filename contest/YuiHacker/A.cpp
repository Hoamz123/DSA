#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define nax 1000005
#define FAST ios::sync_with_stdio(0);cin.tie(0);
ll f[94];
int main(){
    FAST;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    f[0] = 1;f[1] = 1;
    for(int i=2;i<93;i++){
        f[i] = f[i-1] + f[i-2];
    }
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        cout << f[n] << endl;
    }
}
//chu y f[92] ko de long long dc ma phai unsigned