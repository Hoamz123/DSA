#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int N,H;cin >> N >> H;
    vector<int> up(H+2,0);
    vector<int> down(H+2,0);
    for(int i=0;i<N;i++){
        int h;cin >> h;
        if(i % 2 == 0) up[h]++;
        else down[h]++;
    }
    for(int i=H;i>=1;i--){
        up[i] += up[i+1];
        down[i] += down[i+1];
    }
    int res = 1e9;int cnt = 0;
    for(int h=1;h<=H;h++){
        int nums = up[h] + down[H-h+1];
        if(nums < res){
            res = nums;
            cnt = 1;
        }
        else if(nums == res) cnt++;//tang so lan
    }
    cout << res << " " << cnt;
    // https://oj.vnoi.info/submission/9025121
}