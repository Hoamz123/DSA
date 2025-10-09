#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isHappy(int n) {
            set<int> se;
            while(n != 1 && se.count(n) == 0){
                se.insert(n);
                n = next(n);
            }
            return n == 1;
        }
        int next(int n){
            int res = 0;
            while(n){
                res += (n % 10) * (n % 10);
                n /= 10;
            }
            return res;
        }
};