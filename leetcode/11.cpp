#include<bits/stdc++.h>
using namespace std;

#define INF 1000001
class Solution {
public:
    int minimumCardPickup(vector<int>& a) {
        int m = *min_element(a.begin(),a.end());
        int pre[1000001];
        for(int i=0;i<INF;i++) pre[i] = -1;
        int len = INF;
        for(int i=0;i<(int)a.size();i++){
            if(pre[a[i] - m] != -1){
                len = min(len,i - pre[a[i] - m] + 1);
            }
            pre[a[i] - m] = i;
        }
        return (len == INF) ? -1 : len;
    }
};
// acc
// https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/