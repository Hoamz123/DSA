#include<bits/stdc++.h>
using namespace std;

int longestSubstring(string s, int k) {
    int res = 0;
    for(int i=1;i<=26;i++){
        unordered_map<char,int> mp;
        int l=0,r=0;
        int cnt = 0;
        int count = 0;
        while(r < (int)s.size()){
            mp[s[r]]++;
            if(mp[s[r]] == 1) cnt++;//dem so ki tu phan biet
            if(mp[s[r]] == k) count++;//dem so ki tu thoa man yeu cau
            while(l <= r && cnt > i){
                mp[s[l]]--;
                if(mp[s[l]] == 0) cnt--;
                if(mp[s[l]] == k - 1) count--;//boi di 1 ki tu ko thoa man
                l++;
            }
            //do giam tung don vi 1 -> cnt == i;
            if(cnt == i && cnt == count){
                res = max(res,r - l + 1);
            }
            r++;
        }
    }
    return res;
}

int main(){
    cout << longestSubstring("aaabb",3);
}