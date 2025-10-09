#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll check(ll a, ll k, ll limit) {
    ll res = 1;
    while(k > 0){
        if(k % 2 == 1){
            if (res > limit / a) return limit + 1;
            res *= a;
        }
        k /= 2;
        if(k > 0){
            if (a > limit / a) return limit + 1;
            a *= a;
        }
    }
    return res;
}

//cach 2
ll dost(ll a,ll k,ll n){
    ll res = 1;
    for(int i=1;i<=k;i++){
        res *= a;
        if(res > n) return 2;
    }
    if(res == n) return 1;
    else return 0;
}

int main(){
    ll n; cin >> n;
    ll low = 1, high = min(n,1ll* 64); // giới hạn vì x^x lớn cực nhanh
    while(low <= high){
        ll mid = (low + high)/2;
        ll val = dost(mid, mid, n);
        if(val == 1){
            cout << mid;
            return 0;
        }
        else if(val == 0) low = mid + 1;//tang mid len
        else high = mid - 1;//giam mid xuong
    }
    cout << -1;
}
