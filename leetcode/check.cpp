#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0);cin.tie(0);
int main(){
    FAST;
    string s,t;cin >> s >> t;
    unordered_map<char,int> preT;
    for(char x : t) preT[x]++;
    unordered_map<char,int> preS;
    int res = 10000000;
    int cnt = 0;
    int start = 0;
    for(int l=0,r=0;r<(int)s.size();r++){
        preS[s[r]]++;
        if(preT.count(s[r]) > 0 && preS[s[r]] == preT[s[r]]) cnt++;
        while(cnt == (int)preT.size()){
            int len = r - l + 1;
            if(len < res){
                res = len;
                start = l;
            }
            preS[s[l]]--;
            if(preT.count(s[l]) > 0 && preS[s[l]] < preT[s[l]]) cnt--;
            l++;
        }
    }
    if (res == 10000000) cout << "NONE";
    else cout << s.substr(start,res);
}
/*
https://leetcode.com/problems/minimum-window-substring/description/
*/