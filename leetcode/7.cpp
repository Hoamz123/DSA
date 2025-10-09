#include<bits/stdc++.h>
using namespace std;

#define ll long long

int countDistinct(vector<int> &nums, int k, int p)
{
    set<vector<int>> se;
    for(int i=0;i<(int)nums.size();i++){
        int cnt = 0;vector<int> ve;
        for(int j=i;j<(int)nums.size();j++){
            if(nums[j] % p == 0){
                cnt++;
            }
            if(cnt > k) continue;
            ve.push_back(nums[j]);
            se.insert(ve);
        }
    }
    return (int)se.size();
}
//acc : easy
int main(){
    vector<int> a = {2,3,3,2,2};
    cout << countDistinct(a,2,2);
}