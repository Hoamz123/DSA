#include<bits/stdc++.h>
using namespace std;

int maxEnvelopes(vector<vector<int>> &v)
{
    sort(v.begin(),v.end(),[](vector<int> &a,vector<int> &b){
        if(a[0] != b[0]) return a[0] < b[0];
        return a[1] > b[1];
    });

    for(auto it : v){
        cout << it[0] << " " << it[1] << endl;
    }

    vector<int> lis;
    for(auto it : v){
        int h = it[1];
        auto i = lower_bound(lis.begin(),lis.end(),h);
        if(i == lis.end()) lis.push_back(h);
        else *i = h;
    }
    //O(nlog(n))
    for(int x : lis) cout << x << " ";
    cout << endl;
    return (int)lis.size();
    //acc (hard)
}

int main(){
    vector<vector<int>> v = {{2, 100}, {3, 200}, {4, 300}, {5, 500}, {5, 400}, {5, 250}, {6, 370}, {6, 360}, {7, 380}};
    cout << maxEnvelopes(v);
}