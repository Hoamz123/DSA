#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0);cin.tie(0);

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> se;
    int res = 0;
    for(int l=0,r=0;r<(int)s.size();r++){
        //da tung xuat hien trong qua khu
        while(l < r && se.find(s[r]) != se.end()){
            se.erase(s[l++]);//xoa tu trai qua den khi nao s[r] la duy nhat
        }
        //thi moi chen vao set
        se.insert(s[r]);
        res = max(res,r - l + 1);
    }
    return res;
}

int main(){
    cout << lengthOfLongestSubstring("abcabcbb");
}