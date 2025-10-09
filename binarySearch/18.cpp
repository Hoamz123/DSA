#include<bits/stdc++.h>
using namespace std;
#define ll long long

int kthSmallest(vector<vector<int>> &matrix, int k)
{
    vector<int> a;
    for(auto it : matrix){
        for(auto x : it){
            a.push_back(x);
        }
    }
    sort(a.begin(),a.end());
    return a[k-1];
    ///acc easy
}

int main(){
    vector<vector<int>> a = {{1,5,9},{10,11,13},{12,13,15}};
    cout << kthSmallest(a,8);
}