#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n,l,r;cin >> n >> l >> r;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    int cnt = 0;
    for(int j = n - 1;j>=0;j--){
        int ct = l - a[j];
        int cp = r - a[j];
        for(int i = 0;i<j;i++){
            if(a[i] >= ct && a[i] <= cp) cnt++;
        }
    }
    cout << cnt;
}


void x(){
    int n,l,r;cin >> n >> l >> r;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    int cnt = 0;
    vector<int> s;
    s.reserve(n);//chi cap bo nho
    for(int j=0;j<n;j++){
        int low = l - a[j];
        int high = r - a[j];
        cnt += upper_bound(s.begin(),s.end(),high) - lower_bound(s.begin(),s.end(),low);
        auto pos = lower_bound(s.begin(),s.end(),a[j]);//chi so cua phan tu nho nha >= a[j]
        s.insert(pos,a[j]);
    }
    cout << cnt;
}

int main(){
    x();
    // vector<int> a = {1,2,3,4,5,6,7};
    // cout << upper_bound(a.begin(),a.end(),8) - lower_bound(a.begin(),a.end(),3);
    //cho biet trong a co bao nhieu phan tu thuoc [3,8]
}