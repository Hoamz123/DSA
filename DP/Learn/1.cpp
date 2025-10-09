#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin >> n;
    vector<int> a(n,0);
    vector<int> res;
    for(int &x : a) cin >> x;
    for(int i=0;i<n;i++){
        auto it = lower_bound(res.begin(),res.end(),a[i]);
        if(it == res.end()){
            res.push_back(a[i]);
        }
        else *it = a[i];
    }
    cout << (int)res.size() << endl;
    for(int i : res) cout << i << " ";
}

/*
7
3 1 5 2 6 4 9
*/