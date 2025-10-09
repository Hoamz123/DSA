#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        vector<int> a(n,0);
        unordered_map<int,int> mp;
        set<int> se;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            mp[a[i]]++;
            se.insert(a[i]);
        }
        ll res = 0;
        int cnt = 0;
        for(int i : se){
            //bang nhau
            int c = mp[i];
            if(c >= 3){
                res += 1ll * c * (c - 1) * (c - 2) / 6;
            }
            // nho hon ==
            if (c >= 2){
                res += 1ll * cnt * (c) * (c - 1) / 2;
            }
            cnt += c;
        }
        cout << res << endl;
    }
}