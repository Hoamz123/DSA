#include<bits/stdc++.h>
using namespace std;

int countPrefixes(vector<string> &words, string s)
{
    int cnt = 0;
    for(auto it : words){
        int check = 1;
        for(int i=0;i<(int)it.size();i++){
            if(it[i] != s[i]) {
                check = 0;
                break;
            }
        }
        if(check == 1) cnt++;
    }
    return cnt;
    //acc
    //https://leetcode.com/problems/count-prefixes-of-a-given-string/submissions/1628221283/
}

int main(){
    vector<string> w = {"a", "b", "c", "ab", "bc", "abc"};
    cout << countPrefixes(w,"abc");
}