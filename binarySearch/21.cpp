#include<bits/stdc++.h>
using namespace std;
#define ll long long
//tinh tong ki tu tu 1 den mid

ll check(ll number){
    int d = to_string(number).size();
    ll total = 0;
    //tong ki tu tu 1 den 10^(d-1)
    for(int i=1;i<d;i++){
        total += 1ll * (pow(10,i) - pow(10,i-1)) * i;//cong thuc
    }
    //tong ki tu tu 10^(d-1) den number
    total += 1ll * (number - pow(10,d-1) + 1) * d;//cong thuc
    return total;
}

int findNthDigit(int n) {
    ll low = 1,high = 1000000001;
    int tmp = 0;
    while(low <= high){
        ll mid = low + (high - low) / 2;
        ll len = check(mid);
        if(len < n) low = mid + 1;
        else{
            tmp = mid;
            high = mid - 1;
        }
    }
    ll x = check(tmp - 1);
    ll index = n - x;
    string s = to_string(tmp);
    return s[index - 1] - '0';
    //acc
}


int main(){
    cout << findNthDigit(10000);
}