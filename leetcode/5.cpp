#include<bits/stdc++.h>
using namespace std;
#define ll long long

int minimumAverageDifference(vector<int> &a) {
    int n = a.size();
    vector<ll> nums(n,(ll)0);
    for(int i=0;i<(int)nums.size();i++){
        if(i == 0) nums[0] = a[0];
        else nums[i] = nums[i-1] + a[i];
    }
    ll minRes = 1e6;
    int res = -1;
    for(int l=0;l < (int)nums.size();l++){
        int len1 = l + 1;
        int len2 = max(((int)nums.size() - 1) - l,1);
        ll sumLeft = nums[l];
        ll sumRight = nums[(int)nums.size() - 1] - nums[l];
        ll tmp = abs(sumLeft / len1 - sumRight / len2);
        if(tmp < minRes){
            minRes = tmp;
            res = l;
        }
    }
    return res;
}

int main(){
    vector<int> a = {1,2,3,4,4};
    cout << minimumAverageDifference(a);
    //acc
}