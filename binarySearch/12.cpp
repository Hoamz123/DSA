#include<bits/stdc++.h>
using namespace std;
#define ll long long
//koko eating bananas
ll totalHours(vector<int> &a, int bananaInAHour)
{
    ll total = 0;
    for(int x : a){
        total += (int)((x + bananaInAHour - 1) / bananaInAHour);
    }
    return total;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    ll low = 1,high = *max_element(piles.begin(),piles.end());
    ll res = totalBananas;
    while(low <= high){
        ll bananaInAHour = low + (high - low) / 2;
        ll totalH = totalHours(piles,bananaInAHour);
        if(totalH <= h){
            res = min(res,bananaInAHour);
            high = bananaInAHour - 1;
        }
        else {
            low = bananaInAHour + 1;
        }
    }
    return res;
    //acc
}

int main(){
    vector<int> a = {30, 11, 23, 4, 20};
    int h = 5;
    
    cout << res;
}