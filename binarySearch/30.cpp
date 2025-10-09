#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
bool check(int radius,const vector<int> houses,const vector<int> h){
    for(int house : houses){
        //voi moi toa nha -> find vi tri gan nhat co may suoi
        auto it = lower_bound(h.begin(),h.end(),house);
        int right = (it == h.end()) ? mod : abs(*it - house);
        int left = (it == h.begin()) ? mod : abs(*prev(it) - house);
        int radiusTmp = min(right,left);
        if(radiusTmp > radius) return false;
    }
    return true;
}

int findRadius(vector<int> &houses, vector<int> &heaters)
{
    sort(houses.begin(),houses.end());
    sort(heaters.begin(),heaters.end());
    int low = 0,high = 1e9;
    while(low < high){
        int mid = low + (high - low)  / 2;
        bool tmp = check(mid,houses,heaters);
        if(tmp){
            high = mid;//mong muon giam mid -> giam ban kinh di -> tim min
        }
        else low = mid + 1;
    }
    return low;
}

int main(){
    vector<int> a = {1,5};
    vector<int> h = {2};
    cout << findRadius(a,h);
}