#include<bits/stdc++.h>
using namespace std;

// Find Peak Element
int findPeak(vector<int> &a){
    if((int)a.size() == 1) return 0;
    int n = a.size();
    if(a[0] > a[1]) return 0;
    if(a[n-1] > a[n-2]) return n-1;
    int low = 1,high = n-2;
    while(low <= high){
        int mid = (low + high) / 2;
        if(a[mid] > a[mid - 1] && a[mid] > a[mid + 1]){
            return mid;
        }
        else if(a[mid] > a[mid - 1]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
int main(){
    vector<int> a = {3, 1, 4, 2};
    cout << findPeak(a);
}