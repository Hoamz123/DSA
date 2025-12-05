#include<bits/stdc++.h>
using namespace std;

int main(){
    int q;cin >> q;
    int x = 0;
    while(q--){
        int type,k;cin >> type >> k;
        if(type == 1){
            x |= (1 << k);
        }
        else if(type == 2){
            x &= ~(1 << k);
        }
        else{
            x ^= (1 << k);
        }
        cout << x << endl;
    }
}