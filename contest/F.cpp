#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> sangnt(ll m, ll c) {
    vector<bool> f(m+5,1);
    f[0]=f[1]=0;
    vector<ll> sont;
    for(ll i=2;i<=m;++i){
        if(f[i]){
            sont.push_back(i);
            if(static_cast<ll>(sont.size())==c) break;
            for(ll j=i*i;j<=m;j+=i) f[j]=0;
        }
    }
    return sont;
}

int main() {
    ll t;
    cin>>t;
    vector<vector<ll>> a;
    ll maxx=0;
    while(t--) {
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(ll i=0;i<n;++i) cin>>v[i];
        a.push_back(v);
        maxx=max(maxx,n);
    }

    vector<ll> sont=sangnt(5e6,maxx);
    vector<ll> prefix(maxx+2);
    for(ll i=1;i<=maxx;++i) prefix[i]=prefix[i-1]+sont[i-1];//tong i so nguyen to dau tien

    //O(n^2log(n))
    for(int i=0;i<a.size();i++) {
        vector<ll> cur=a[i];

        sort(cur.begin(),cur.end(),greater<ll>());
        vector<ll> s(cur.size()+2);
        for(ll j=1;j<=cur.size();j++) s[j]=s[j-1]+cur[j-1];//tong cong don den j

        ll ans=cur.size();

        for(ll j=cur.size();j>=0;j--) {

            if(s[j]>=prefix[j]){
                ans=cur.size()-j;
                break;
            }
        }
        cout<<ans<<endl;
    }
}
