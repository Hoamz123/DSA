#include<bits/stdc++.h>
using namespace std;
#define faster() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define umii unordered_map<int,int>
#define si set<int>
#define pb push_back
#define is insert
#define mod 1000000007
#define INF 1000000001
#define nax 1000005
#define FOR1(i,n) for(int i=1;i<=(n);i++)
#define FOR0(i,n) for(int i=0;i<(n);i++)
#define forxy(i,x,y) for(int i=(x);i<(y);i++);
#define endl '\n'


bool check(string &s,string &t,int k){
    string x = "";
    for(int i=0;i<k;i++){
        x += t;
    }
    int n = s.size();
    int m = x.size();
    int i=0,j=0;
    while(i<n && j < m){
        if(s[i] == x[j]){
            i++;
            j++;
        }
        else i++;
    }
    if(j == m) return true;
    return false;
}


string longestSubsequenceRepeatedK(string s, int k){
    unordered_map<char,int> mp;
    FOR0(i,(int)s.size()){
        mp[s[i]]++;
    }
    string se = "";
    FOR0(i,(int)s.size()){
        if(mp[s[i]] >= k) se.push_back(s[i]);
    }
    queue<string> que;
    string tmp = "";
    que.push(tmp);
    while(!que.empty()){
        string x = que.front();
        que.pop();
        for(char c = 'z';c >= 'a';c--){
            string y = x + c;
            if(check(se,y,k)){
                //dung thi luu vao queue
                que.push(y);
                if((int)y.size() > (int)tmp.size()) tmp = y;
                else if((int)y.size() == (int)tmp.size()){
                    if(y > tmp) tmp = y;
                }
            }
        }
    }
    return tmp;
}


int main(){
    faster();
    cout << longestSubsequenceRepeatedK("letsleetcode",2);
}
