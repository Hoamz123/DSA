/*
Bài toán: Cho n cây có chiều cao a[i]. Muốn cắt các cây ở độ cao H sao cho tổng gỗ thu được ≥ m. 
Tìm giá trị lớn nhất của H thỏa mãn điều kiện đó.*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
vector<int> v(1001,0);

bool totalWood(int high){
    ll total = 0;
    for(int i=0;i<n;i++){
        if(v[i] > high) total += v[i] - high;
    }
    return total >= m;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> v[i];
    ll l = 0;//cat tat ca cay
    ll r = -1e9;//khong cat cay nao(H = a_max)
    for(int i=0;i<n;i++) {
        r = 1ll * max(r,(ll)v[i]);
    }
    ll ans = -1;
    while(l <= r){
        ll mid = l + (r - l)/2;
        if(totalWood(mid)){
            //tang mid <=> tang chieu cao (mid la chieu cao khong phai chi so index)
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans;
}

/*
4 7
20 15 10 17
*/