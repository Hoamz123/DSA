//search in rotated array (co bang nhau 1 vai phan tu)

#include<bits/stdc++.h>
using namespace std;

int bs(vector<int> &a,int target){
    int l = 0,r = a.size();
    while(l <= r){
        int mid = (l+r) / 2;
        if(a[mid] == target) return mid;
        if(a[l] == a[mid] && a[mid] == a[r]){
            l++;r--;continue;
        }
        else if(a[l] < a[mid]){
            if(a[l] <= target && target <= a[mid]){
                r = mid - 1;
            }
            else l = mid + 1;
        }
        else{
            if(a[mid] <= target && target <= a[r]){
                l = mid + 1;
            }
            else r = mid - 1;
        }
    }
    return -1;
}

int main(){
    vector<int> a = {7,8,1,2,3,3,3,4,5,6};
    cout << bs(a,3);
}