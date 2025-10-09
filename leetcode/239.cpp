#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = (int)nums.size();
    deque<int> idx;
    vector<int >ans;
    for(int i=0;i<n;i++){
        //i da la phan tu o ngoai cua so
        if(!idx.empty() && idx.front() == i - k){
            idx.pop_front();
        }
        //duy tri phan tu tai front() la lon nhat trong doan cua so dang xet
        while(!idx.empty() && nums[idx.back()] <= nums[i]){
            idx.pop_back();
        }
        idx.push_back(i);
        if(i >= k - 1){
            ans.push_back(nums[idx.front()]);
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    for(int x : maxSlidingWindow(nums,3)){
        cout << x << " ";
    }
}