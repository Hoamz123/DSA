#include<bits/stdc++.h>
using namespace std;
// https://cses.fi/problemset/result/12827755/
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n,0),b(m,0);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int j=0;j<m;j++) cin >> b[j];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int cnt = 0;
    int i=0,j=0;
    //mong muon voi moi yc cua nguoi dk se tim dc nha cho ho
    while(i < n && j < m){
        if(abs(a[i] - b[j]) <= k){
            cnt++;
            i++;
            j++;
        }
        //phong nho hon yc
        else if(b[j] < a[i] - k){ // tang j de tang b[j] -> tang kich co nha nen
            //yeu cau cao
            j++;
        }
        //phong qua to -> chuye sang nguoi co yeu cau cao hon
        //b[j] > a[i] + k
        else i++;
    }
    cout << cnt;
}