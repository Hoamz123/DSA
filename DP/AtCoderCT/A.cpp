#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000000001
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin >> n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<ll> ans(n+5,INF);
    ans[0] = 0;
    for(int i=0;i<n;i++){
        for(int j : {i+1,i+2}){//dang o bac i se buoc nen (i+1) or buoc nen (i+2) (j la bac sau (da buoc ne bac i ot bac i+1 roi -> da co chi phi tai hai bac do roi))
            if(j < n){
                //tm dk
                //ans[j];cost nho nhat de den bac thu j = max(ko buoc nen bac j,buoc nen bac j)
                ans[j] = min(ans[j],ans[i] + abs(a[j] - a[i]));//a[j] bayh moi duyet den -< trcdo chua co gia tri -> gan cho  la gia tri lon nhat de lay min xuong
                //bac bayh xet = min(cost bac bayh,chi phi nen bac truoc do + cost de nen bac bay h)
            }
        }
    }
    cout << ans[n-1];
    //acc
}
