#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin >> n;
    vector<int> h(n,0);
    for(int &i : h) cin >> i;
    int res = 0;//tong luong mua co the chua
    vector<int> left(n,0),right(n,0);
    //left[i] : cot cao nhat tinh den i tu ben trai
    //right[i] cot cao nhat tinh den i tu ben phai
    for(int i=0;i<n;i++){
        if(i == 0) left[0] = h[0];
        else left[i] = max(left[i-1],h[i]);
    }
    for(int i=n-1;i>=0;i--){
        if(i==n-1) right[i] = h[i];
        else right[i] = max(right[i+1],h[i]);
    }
    //xet luong nuoc co the chua cua tung cot mot
    for(int i=0;i<n;i++){
        res += min(left[i],right[i]) - h[i];
    }
    cout << res;
}
//Trapping Rain Water
/*
6
4 2 0 3 2 5

*/
