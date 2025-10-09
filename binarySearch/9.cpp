//find minimum in rotated array

#include<bits/stdc++.h>
using namespace std;

int find(vector<int> &a){
    int l = 0,r = a.size();
    int res = 1e9 + 7;
    while(l <= r){
        int mid = (l+r)/2;
        if(a[l] <= a[mid]){
            res = min(res,a[l]);
            l = mid + 1;
        }
        else{
            res = min(res,a[mid]);
            r = mid - 1;
        }
    }
    return res;
}
int main(){
    vector<int> a = {4,5,1,2,3};
    cout << find(a);
}