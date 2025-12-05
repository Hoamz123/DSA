#include<bits/stdc++.h>
using namespace std;


/*
tinh chat a ^ i = b ^ j thi cx co the suy ra a ^ j = b ^ i
dem so cap (i,j) sao cho a[i] * j = a[j] * i
*/
int main(){
    int n;cin >> n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i] = (a[i] ^ (i + 1));
    }
    
    unordered_map<int,int> cnt;
    int ans = 0;
    for(int i=0;i<n;i++){
        ans += cnt[a[i]];
        cnt[a[i]]++;
    }
    cout << ans;
}