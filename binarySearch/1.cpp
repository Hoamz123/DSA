#include<bits/stdc++.h>
using namespace std;
#define ll long long

//kiem tra 1 phan tu co nam trong day hay khong

bool bs(vector<int> &v,int x){
    int l = 0,r = (int)v.size() - 1;
    while(r - l> 1){
        int m = l + (r-l)/2;
        if(v[m] >= x) r = m;
        else l = m;
    }
    return v[r] == x;
}

int main(){
    int n;cin >> n;
    vector<int> v(n+1,0);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());
    int x;cin >> x;
    if(bs(v,x)) cout << "Yes";
    else cout << "No";
}