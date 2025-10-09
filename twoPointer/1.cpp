#include<bits/stdc++.h>
using namespace std;

//tim do dai day con nho nhat co tong >=S;

// int main(){
//     int res = 1e9;
//     int l = 0;int s = 17;
//     vector<int> a = {5,1,3,5,10,7,4,9,2,8};
//     int sum = 0;
//     for(int r=0;r<(int)a.size();r++){
//         sum += a[r];
//         while(sum >= s){
//             res = min(res,r - l + 1);
//             sum -= a[l++];
//         }
//     }
//     cout << res;
// }


//cach 2 : chat nhi phan

vector<int> a;

bool check(int len,int s){
    for(int i=len;i<(int)a.size();i++){
        int tmp = a[i] - a[i - len];
        if(tmp >= s) return true;
    }
    return false;
}

int main(){
    a = {5, 1, 3, 5, 10, 7, 4, 9, 2, 8};
    for(int i=0;i<(int)a.size();i++){
        if(i == 0) continue;
        a[i] += a[i-1];
    }
    int l = 1,r = a.size();//khong phai chi so ma la do dai
    int res = 1e9;int k = 17;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid,k)){
            r = mid - 1;
            res = min(res,mid);
        }
        else l = mid + 1;
    }
    cout << res;
}