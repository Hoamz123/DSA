//441 leetcode
#include<bits/stdc++.h>
using namespace std;
#define ll long long

//voi so bac thang la mid  -> can bao nhieu dong coin
    ll check(int mid){
       return 1ll * mid * (mid + 1) / 2;//cap so cong cong sai = 1
    }

    int arrangeCoins(int n) {
        int l = 1,h = n;
        int res = 0;
        while(l <= h){
            int mid = l + (h - l) / 2;//so bac thang
            ll numberOfCoins = check(mid);
            if(numberOfCoins <= n){
                res = mid;
                l = mid + 1;
            }
            else h = mid - 1;
        }
        return res;
    }
    //acc

    int main(){
        cout << arrangeCoins(8);
    }