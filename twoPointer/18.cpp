#include<bits/stdc++.h>
using namespace std;

//day con dai nhat co dung k phan tu
int longestKSubstr(string s, int k) {
    // your code here
    unordered_map<char,int> mp;
    int cnt = 0;
    int res = -1;

    for(int l=0,r=0;r<(int)s.size();r++){
        mp[s[r]]++;
        if(mp[s[r]] == 1) cnt++;
        while(l <= r && cnt > k){
            mp[s[l]]--;
            if(mp[s[l]] == 0) cnt--;
            l++;
        }
        if(cnt == k){
            res = max(res,r - l + 1);
        }
    }
    return res;
}

int main(){
    cout << longestKSubstr("aaaa",2);
}