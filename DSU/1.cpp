#include<bits/stdc++.h>
using namespace std;

vector<long long> sum(1e5 + 1, 0);
vector<int> parent(1e5 + 1, 0);
vector<int> ac(1e5 + 1, 0);
vector<int> sz(1e5 + 1, 0);


int find(int u){
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);//nen duong
}

void Union(int u,int v){
    u = find(u);
    v = find(v);
    if(u == v) return;
    if(sz[u] < sz[v]) swap(u,v);
    //them v vao tap u
    sz[u] += sz[v];
    parent[v] = u;
    sum[u] += sum[v];
}

vector<long long> maximumSegmentSum(vector<int> &nums, vector<int> &removeQueries){
    int n = nums.size();
    
    for(int i=0;i<n;i++){
        parent[i] = i;
        sz[i] = 1;
    }
    vector<long long> res(n, 0);

    long long ans = 0;
    for(int i=n-1;i>=0;i--){
        res[i] = ans;
        int index = removeQueries[i];
        ac[index] = 1;//danh dau la da xet roi
        sum[index] = nums[index];
        if(index > 0 && ac[index - 1]) Union(index,index-1);
        if(index + 1 < n && ac[index + 1]) Union(index,index + 1);
        ans = max(ans,sum[find(index)]);
    }
    return res;
}

int main(){
    vector<int> a = {1,2,5,6,1};
    vector<int> q = {0,3,2,4,1};
    vector<long long> res =  maximumSegmentSum(a,q);
    for(int i=0;i<5;i++){
        cout << res[i] << " ";
    }
}