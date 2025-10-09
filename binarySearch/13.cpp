#include<bits/stdc++.h>
using namespace std;

int numberDay(vector<int> &a,int capacity){
    int day = 1;
    int w = 0;
    for(int i=0;i<(int)a.size();i++){
        if(w + a[i] <= capacity){
            w += a[i];
        }
        else{
            day++;
            w = a[i];
        }
    }
    return day;
}
//acc

//chat nhi phan dung tich nho nhat de cho het hang trong dday ngay

int main(){
    vector<int> a = {1,2,3,4,5,6,7,8,9,10};
    int day = 5;
    int low = *max_element(a.begin(),a.end());
    int high = 0;
    int res = 0;
    for(int x : a) high += x;
    while(low <= high){
        int cap = (low + high) / 2;
        if(numberDay(a,cap) <= day){
            res = cap;
            high = cap - 1;
        }
        else low = cap + 1;
    }
    cout << res;
}

