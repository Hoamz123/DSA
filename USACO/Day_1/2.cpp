#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;cin >> n >> x;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    int cnt = 0;
    //tham lam chon nguoi nho nhat va lon nhat
    int i=0,j = n-1;
    while(i <=j){
        if(a[i] + a[j] <= x){
            cnt++;
            i++;
            j--;
        }
        else{
            j--;//nguoi nang nhat luon dc di
            cnt++;
        }
       
    }
    cout << cnt;
}