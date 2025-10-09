#include<bits/stdc++.h>
using namespace std;

// 424. Longest Repeating Character Replacement
/*
duoc phep thay the k ki tu 
-> tra ve do dai dai nhat cua dau toan ki tu giong nhau sau khi thay the k ki tu trong xau do
*/

int main(){
    string s = "ABAB";
    int k = 2;
    vector<int> mp(26,0);
    int res = 0;
    int maxPrefix = 0;
    for(int l=0,r=0;r<(int)s.size();r++){
        mp[s[r] -'A']++;
        maxPrefix = max(maxPrefix,mp[s[r] - 'A']);//tan xuat lon nhat cua 1 phan tu trnog doan lr
        while((r - l + 1) - maxPrefix > k){
            mp[s[l] - 'A'] --;
            l++;
        }
        //chac chan xuong day se == k
        res = max(r - l + 1,res);
    }
    cout << res;
}