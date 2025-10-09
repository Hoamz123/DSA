#include<bits/stdc++.h>
using namespace std;

vector<int> findRightInterval(vector<vector<int>> &a)
{
    vector<int> start;
    unordered_map<int,int> mp;
    for(int i=0;i < (int)a.size();i++){
        start.push_back(a[i][0]);
        mp[a[i][0]] = i;//luu lai index cua start trc khi sort
    }
    sort(start.begin(),start.end());
    vector<int> ans;
    for(auto it : a){
        int e = it[1];
        //low_bound xem trong start co phan tu nao nho nhat >= e hay khong
        auto i = lower_bound(start.begin(),start.end(),e);
        if(i != start.end()){
            ans.push_back(mp[*i]);
        }
        else {
            ans.push_back(-1);
        }
    }
    return ans;
    //acc
}

int main(){
    vector<vector<int>> a = {{3,4},{2,3},{1,2}};
    for(int x : findRightInterval(a)) cout << x << " ";
}