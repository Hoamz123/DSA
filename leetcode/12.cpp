#include<bits/stdc++.h>
using namespace std;

int shortestSubarray(vector<int> &nums, int k)
{
    int res = 1e9;
    int sum = 0;
    for(int l=0,r=0;r < (int)nums.size();r++){
        sum += nums[r];
        if(sum >= k){
            while(sum - nums[l] >= k){
                sum -= nums[l++];
            }
            res = min(res,r-l+1);
        }
    }
    return res;
}

int main()
{
    vector<int> a = {2,-1,2};
    cout << shortestSubarray(a,3);
}