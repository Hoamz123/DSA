#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e6 + 1;

ll pre[maxn] = {0};
ll M[maxn] = {0};

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin >> t;
    vector<ll> a;
    while(t--){
        int n;cin >> n;
        a = vector<ll>(n,0);
        for(int i=0;i<n;i++) cin >> a[i];
        pre[n] = 0;
        for(int i = n-1;i>=0;i--){
            pre[i] = a[i] + pre[i+1];
        }
        M[0] = a[0];
        for(int i=1;i<n;i++){
            M[i] = max(M[i-1],a[i]);
        }
        for(int i=0;i<n;i++){
            cout << M[n-i-1] + pre[n - i] << " ";
        }
        cout << endl;
    }
    // acc
    // https://codeforces.com/contest/2104/problem/B
}