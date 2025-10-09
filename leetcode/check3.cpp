 #include<bits/stdc++.h>
using namespace std;

//so sub con co co phan tu khac nhau <= k
int calc(vector<int> &a,int k){
    int res = 0;
    unordered_map<char,int> mp;
    int cnt = 0;//dem so phantu khac hau
    for(int l=0,r=0;r<(int)a.size();r++){
        mp[a[r]]++;
        if(mp[a[r]] == 1) cnt++;
        while(l <= r && cnt > k){
            mp[a[l]]--;
            if(mp[a[l]] == 0) cnt--;
            l++;
        }
        res += r - l + 1;//so sub con ket thuc tai r
    }
}

int subarraysWithKDistinct(vector<int>& a, int k) {
    return calc(a,k) - calc(a,k-1);
}