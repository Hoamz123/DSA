#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define nax 1000005
#define mod 1000000007
#define FAST ios::sync_with_stdio(0);cin.tie(0);
#define FOR1(i,n) for(int i=1;i<=(n);i++)
#define FOR(i,n) for(int i=0;i<=(n);i++)
int main(){
    FAST;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;cin >> n;
    vector<int> a(n+1);
    FOR1(i,n) cin >> a[i];
    vector<int> res;
    FOR1(i,n){
        auto it = lower_bound(res.begin(),res.end(),a[i]);
        if(it == res.end()){
            res.push_back(a[i]);
        }
        else *it = a[i];
    }
    cout << (int)res.size();
}