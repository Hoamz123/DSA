#include<bits/stdc++.h>
using namespace std;

#define maxn (1 << 20) + 10//2 ^ 20 + 10

#define ll long long
int a[maxn];
int n;

ll calc(int x){
    if(x < 0) return 0;
    ll res = 0;
    map<int,int> mp;
    int cnt = 0;
    for(int r = 1,l = 1;r <= n;r++){
        mp[a[r]]++;
        if(mp[a[r]] == 1) cnt++;
        while(l <= r && cnt > x){
            mp[a[l]]--;
            if(mp[a[l]] == 0) cnt--;
            l++;
        }
        res += r - l + 1;//so luong xau con trong doan tu l den r (ket thuc tai r)
    }
    return res;
}


int main(){
    ios::sync_with_stdio(0);cin.tie(nullptr);
    int l,r;
    cin >> n >> l >> r;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    cout << calc(r) - calc(l-1) << endl;
    cerr << (1.0 * clock() / CLOCKS_PER_SEC);//thoi gian chay
}