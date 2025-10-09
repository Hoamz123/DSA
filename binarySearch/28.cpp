//410 leetcode
#include<bits/stdc++.h>
using namespace std;

    //voi tong cua day con lon nhat la mid -> ta chia dc bao nhieu sub
    int check(const vector<int> &a,int mid){
        int numberSubs = 1;
        int sumOfASub = 0;
        for(int i=0;i<(int)a.size();i++){
            if(sumOfASub + a[i] <= mid){
                sumOfASub += a[i];
            }
            else{
                numberSubs ++;
                sumOfASub = a[i];
            }
        }
        return numberSubs;
    }

    int splitArray(vector<int>& nums, int k) {
        if((int)nums.size() < k) return -1;
        int low = *max_element(nums.begin(),nums.end());
        int high = 0;
        for(int i : nums) high += i;
        int res = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int tmp = check(nums,mid);
            if(tmp <= k){
                res = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return res;
    }
    //acc


int main(){
    vector<int> a = {1,2,3,4,5};
    cout << splitArray(a,2);
}