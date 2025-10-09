#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& nums, int limit) {
    int res = 0;
    deque<int> M,m;
    for(int l=0,r=0;r<(int)nums.size();r++){
        while(!M.empty() && M.back() < nums[r]){
            M.pop_back();//duy tri giam dan
        }
        M.push_back(nums[r]);
        while(!m.empty() && m.back() > nums[r]){
            m.pop_back();//duy tri tang dan
        }
        m.push_back(nums[r]);
        if(!m.empty() && !M.empty() && M.front() - m.front() > limit){
            if(M.front() == nums[l]){
                M.pop_front();
            }
            if(m.front() == nums[l]){
                m.pop_front();
            }
            l++;
        }
        res = max(res,r - l + 1);
    }
    return res;
}

int main(){
    vector<int> a = {8,2,4,7};
    cout << longestSubarray(a,4);
}