#include<bits/stdc++.h>
using namespace std;

vector<int> partitionLabels(string s)
{
    unordered_map<int,int> mp;//luu index cuoi cung cua s[i]
    for(int i=0;i<(int)s.size();i++){
        mp[s[i]] = i;//cu gan the nay thi se gan dc val la index lon nhat
    }
    int start = 0;int end = 0;
    vector<int> ans;
    for(int i=0;i<(int)s.size();i++){
        end = max(end,mp[s[i]]);//mp[s[i]] se luu index cuoi cung ma s[i] xuat hine
        if(end == i){
            //ki tu hien tai la chot cuoi cung cua day con
            ans.push_back(end - start + 1);//do dai cua day con
            start = i + 1;
        }
    }
    return ans;
}

int main(){
    //chia sau s thanh cac tap con sao cho cac phan tu giong nhau chi xuat hien tren 1 tap
    for (int i : partitionLabels("ababcc"))
        cout << i << " ";
}