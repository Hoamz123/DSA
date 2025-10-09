// Painter's Partition and Split Array - Largest Sum

#include<bits/stdc++.h>
using namespace std;

/*
cho mot mang arr nhiem vu cua ban hay tach mang -> k day con sao cho dayx con cos gia tri lon nhat la nho nhat trong tat ca cac cach split -> tim tong nho nhat do
//cach lam giong nhu 24.cpp
*/
int check(const vector<int> &a,int sum){
    int k = 1;//ban dau la 1 mang
    int s = 0;//tong day con lon nhat
    for(int i=0;i<(int)a.size();i++){
        if(s + a[i] <= sum){
            s += a[i];
        }
        else{
            //chia sang day tiep theo
            k ++;
            s = a[i];
        }
    }
    return k;
}

int ans(const vector<int> &a,int k){
    int low = *max_element(a.begin(),a.end());
    int high = 0;
    for(int i : a) high += i;
    int res = 0;
    while(low <= high){
        int mid = low + (high - low) / 2;
        int tmp = check(a,mid);
        if(tmp <= k){
            res = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return res;
}

int main(){
    vector<int> a = {1,2,3,4,5};
    cout << ans(a,3);
}