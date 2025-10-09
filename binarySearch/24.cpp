// Allocate Books or Book Allocation
#include<bits/stdc++.h>
using namespace std;

int check(const vector<int> &a,int pages){
    int student = 1;int x = 0;
    for(int i=0;i<(int)a.size();i++){
        if(x + a[i] <= pages){
            x += a[i];
        }
        else{
            x = a[i];
            student++;
        }
    }
    return student;
}

int ans(vector<int> &pages,int student){
    int low = *max_element(pages.begin(),pages.end());
    int high = 0;
    int res = -1;
    if((int)pages.size() < student) return -1;
    for(int x : pages) high += x;
    while(low <= high){
        int mid = low + (high - low) / 2;
        int tmp = check(pages,mid);
        if(tmp <= student){
            res = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return res;
}

int main(){
    vector<int> a = {25,46,28,49,24};
    cout << ans(a,4);
}