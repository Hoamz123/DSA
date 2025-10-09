#include<bits/stdc++.h>
using namespace std;

vector<int> countSmaller(vector<int> &nums)
{
    int n = nums.size();
    vector<int> sorted;
    vector<int> res;
    for(int i=n-1;i>=0;i--){
        auto it = lower_bound(sorted.begin(),sorted.end(),nums[i]);//iterator cua phan tu nho nhat > nums[i]
        res.push_back(it - sorted.begin());
        sorted.insert(it,nums[i]);
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    //acc
    vector<int> a = {5, 2, 6, 1};
    for(int i : countSmaller(a)) cout << i << " ";
}