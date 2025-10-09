#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> &a,pair<int,int> &b){
    if(a.second != b.second) return a.second < b.second;
    else return a.first < b.first;
}


int main(){
    int n;cin >> n;
    vector<pair<int,int>> p;
    for(int i=0;i<n;i++){
        int s,e;cin >> s >> e;
        p.push_back({s,e});
    }
    sort(p.begin(),p.end(),cmp);
    int cnt = 1;
    int endPrevious = p[0].second;
    for(auto &[start,end] : p){
        if(start >= endPrevious){
            cnt++;
            endPrevious = end;
        }
    }
    cout << cnt;
}