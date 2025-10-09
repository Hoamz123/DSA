#include<bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s) {
        stack<char> st;
        int cnt = 0;
        for(char c : s){
            if(c == '(') st.push(c);
            //dong va stack trong
            else if(st.empty()){
                cnt++;
            }
            else if(!st.empty()){
                st.pop();
            }
        }
        if(!st.empty()) cnt += st.size();
        return cnt;
}
// acc
// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/