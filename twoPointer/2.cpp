#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;cin >> n;
    vector<int> a(n,0);
    ll x = 0,y = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        x += a[i];
    }
    cin >> m;
    vector<int> b(m, 0);
    for(int j=0;j<m;j++){
        cin >> b[j];
        y += b[j];
    }
    if(x != y){
        cout << -1;
        return 0;
    }
    int res = 0;
    ll SumA = 0,SumB = 0;
    int i = 0,j = 0;
    while(i < (int)a.size() || j < (int)b.size()){
        if(SumA == SumB && SumA != 0){
            res++;//tang nen 1
            SumA = SumB = 0;
        }
        else if(SumA <= SumB && i < (int)a.size()){
            SumA += a[i++];
        }
        else if(j < (int)b.size()){
            SumB += b[j++];
        }
    }
    if(SumA == SumB && SumA != 0){
        res++;
    }
    if(res == 0) cout << -1;
    else cout << res;
    // acc
    // https://codeforces.com/contest/1036/problem/D
}