#include<bits/stdc++.h>
using namespace std;
//tim phan tu lon nhat nho hon (=)k
int findX(vector<int> &a,int k){
    int l = 0,r = (int)a.size();
    int res = -1;
    while(l <= r){
        int mid = (l+r) / 2;
        if(a[mid] <= k){
            res = a[mid];
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return res;
}
//tim phan tu nho nhat > k;
int findX2(vector<int>&a,int k){
    int l = 0,r = a.size();
    int res = -1;
    while(l <= r){
        int mid = (l+r) / 2;
        if(a[mid] > k){
            res = a[mid];
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return res;
}
int main(){

    vector<int> a = {1,3,4,7,9,10,15,20,22,24,27,30,32,36};
    cout << findX(a,14) << endl;
    cout << findX2(a,16);
}