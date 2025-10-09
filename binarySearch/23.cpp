// Aggressive Cows | Binary Search Hard
//G for G
#include<bits/stdc++.h>
using namespace std;

//co cows con bo va mot mang arr a[i] luu khoang cach tu chuong i den moc 0
// hay tim cach cho cows con vao cows chuong bat ki
//sao cho (khoang cach nho nhat giua hai con bo la lon nhat
 //trong tat ca cac case xap xep con bo vao chuong)
int check(vector<int> &a, int cows, int limit) {
    int last_pos = a[0];
    cows--;
    for (int i = 1; i < (int)a.size(); i++) {
        if (a[i] - last_pos >= limit) {
            cows--;
            last_pos = a[i];
        }
    }
    if(cows == 0) return 1;
    return -1;
}

int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls.back() - stalls.front(), ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(stalls, k, mid) == 1) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    vector<int> a = {0,3,4,7,9,10};
    cout << aggressiveCows(a,4);
    //acc
}
