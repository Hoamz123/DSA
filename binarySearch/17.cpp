//69 leetcode
#include<bits/stdc++.h>
using namespace std;

int mySqrt(int x)
{
    int low = 1,high = x;
    int res = 0;
    while(low <= high){
        int tmp = low + (high - low) / 2;
        if(tmp <= x / tmp){
            res = tmp;
            low = tmp + 1;
        }
        else high = tmp - 1;
    }
    return res;
    //acc
}

int main(){
    cout << mySqrt(5);
}