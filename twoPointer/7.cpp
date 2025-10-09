#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin >> n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin >> a[i];
    int S;cin >> S;
    int l = 0;
    int res = 1;
    int tmpSum = 0;
    int idx = 0;
    //O(n)
    for(int r = 0;r<n;r++){
        tmpSum += a[r];
        while(tmpSum > S){
            tmpSum -= a[l++];
        }
        //tmp toi da == S
        int lenTmp = r - l + 1;
        if(lenTmp >= res){
            res = lenTmp;
            idx = l;
        }
    }
    cout << res << endl;
    for(int i=0;i<res;i++){
        cout << a[i + idx] << " ";
    }
}
/*
7
2 6 5 3 6 8 9
20
*/