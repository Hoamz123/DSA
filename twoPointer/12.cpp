#include<bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    unordered_map<int,int> mp;
    mp[0] = 1;//1 lan xuat hien tong = 0,empty
    int cnt = 0;
    int sum = 0;
    for(int i=0;i<(int)nums.size();i++){
        sum += nums[i];
        cnt += mp[sum - goal];
        mp[sum]++;
    }
    return cnt;
}

int main(){
    vector<int> a = {1,0,1,0,1};
    cout << numSubarraysWithSum(a,2);
}
