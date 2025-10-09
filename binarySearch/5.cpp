#include<bits/stdc++.h>
using namespace std;

//tim so cap i,j co tong = s;

int main(){
    vector<int> a = {3,5,6,5,3};
    unordered_map<int,int> mp;
    int res = 0;int s = 8;
    for(int x : a){
        int pad = s - x;
        res += mp[pad];
        mp[x]++;
    }
    cout << res;
}