#include<bits/stdc++.h>
using namespace std;

//bai toan day con tang dai nhat

int main(){
    int n;cin >> n;
    vector<int> a(n,0);
    vector<int> f(n,0);//do dai dai nhat cua day con thoa man tinh den i
    vector<int> r(n,-1);
    for(int &x : a) cin >> x;
    int last = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        f[i] = 1;
        for(int j=0;j<=i;j++){
            if(a[j] < a[i] && f[i] < f[j] + 1){
                f[i] = f[j] + 1;
                r[i] = j;
            }
        }
        if(f[i] > ans){
            ans = f[i];
            last = i;
        }
    }
    vector<int> lis;
    while(last != -1){
        lis.push_back(a[last]);
        last = r[last];
    }
    cout << ans << endl;
    reverse(lis.begin(),lis.end());
    for(int i=0;i<(int)lis.size();i++) cout << lis[i] << " ";
}

/*
12
4 1 3 7 8 5 6 2 7 4 10 6
*/