#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDigit(string s, char digit) {
        vector<int> index;
        for(int i=0;i<(int)s.size();i++){
            if(s[i] == digit){
                index.push_back(i);
            }
        }
        int len = s.size();
        string res;
        for(int i : index){
            string x = s.substr(0,i) + s.substr(i + 1,len - i);
            res = max(res,x);
        }
        return res;
    }
};

// acc
// https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/