#include<bits/stdc++.h>
using namespace std;
#define ll long long

//tra ve so sub con co <= k phan tu rieng biet
ll calc(vector<int> &a,int k){
    unordered_map<int,int> mp;
    int cnt = 0;
    int res = 0;
    for(int l=0,r=0;r<(int)a.size();r++){
        mp[a[r]]++;
        if(mp[a[r]] == 1) cnt++;
        while(l <= r && cnt > k){
            mp[a[l]]--;
            if(mp[a[l]] == 0) cnt--;
        }
        res += r - l + 1;//so day con trong doan l-r ket thuc tai r
    }
    return res;//tra ve so luong sub con co so phan tu rieng biet <= k
}

int main(){
    int n;cin >> n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin >> a[i];
    cout << calc(a,k) - calc(a,k-1);//so day con co dung k phan tu rieng biet
}

/*
11
3 3 3 1 2 1 1 2 3 3 4
*/