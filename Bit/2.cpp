#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned int a = 0;
    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            a = (a ^ x);
        } 
        else if (t == 2) {
            if (a != 0) {
                int msb = 1 << (31 - __builtin_clz(a)); //tat biet lon nhat tinh tu ben phai qua
                a = a ^ msb;
            }
        } 
        else { // t == 3
            cout << __builtin_popcount(a) << endl;
        }
    }
}
