#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin >> t;
    while(t--){
        int a,b,c;cin >> a >> b >> c;
        if(a == b && b == c) cout << "YES\n";
        else{
            if((a+b+c) % 3 != 0) cout << "NO\n";
            else{
                int tbc = (a+b+c) / 3;
                if(c >= tbc){
                    if(a > tbc || b > tbc) cout << "NO\n";
                    else{
                        cout << "YES\n";
                    }
                }
                else{
                    cout << "NO\n";
                }
            }
        }
    }
    // acc
    // https://codeforces.com/contest/2104/problem/A
}