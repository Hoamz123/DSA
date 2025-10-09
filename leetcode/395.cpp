#include<bits/stdc++.h>
using namespace std;

int longestSubstring(string s, int k) {
    int res = 0;
    for(int i=1;i<=26;i++){
        unordered_map<char,int> mp;
        int l = 0,r = 0;
        int SoPhanTuKhacNhau = 0;
        int soPhanTuCoTanXuatK = 0;
        while(r < (int)s.size()){
            mp[s[r]]++;
            if(mp[s[r]] == 1) SoPhanTuKhacNhau++;
            if(mp[s[r]] == k) soPhanTuCoTanXuatK++;
            r++;
            while(SoPhanTuKhacNhau > i){
                mp[s[l]]--;
                if(mp[s[l]] == 0) SoPhanTuKhacNhau--;
                if(mp[s[l]] < k) soPhanTuCoTanXuatK--;
                l++;
            }
            if(soPhanTuCoTanXuatK == SoPhanTuKhacNhau && SoPhanTuKhacNhau == i){
                res = max(res,r - l);
            }
        }
    }
    return res;
}

int main(){
    cout << longestSubstring("ababbc", 2);
}