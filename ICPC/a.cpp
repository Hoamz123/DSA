#include<bits/stdc++.h>
using namespace std;
#define INF  1e9
int main(){

    int n,D,H;cin >> n >> D >> H;
    vector<int> d(n+1,INF);
    vector<int> h(n+1,0);
    for(int i=1;i<=n;i++) cin >> h[i];
    vector<int> parent(n+1,-1);

    priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>> q;
    d[1] = h[1];//tong chieu cao nho nhat tinh tu 1 den 1
    q.push({d[1],1});
    while(!q.empty()){
        auto [minHeight,u] = q.top();q.pop();
        if(minHeight > d[u]) continue;//tong chieu cao nho nhat tinh den dinh u
        for(int v = u + 1;v <= min(n,u + D);v++){
            if(abs(h[u] - h[v]) <= H){
                if(d[v] >= d[u] + h[v]){
                    d[v] = d[u] + h[v];
                    parent[v] = u;
                    q.push({d[v],v});
                }
            }
        }
    }

    if(d[n] == INF){
        cout << -1;
    }
    else{
        cout << d[n] << endl;
        vector<int> res;
        while(n != -1){
            res.push_back(n);
            n = parent[n];
        }
        reverse(res.begin(),res.end());
        for(int i : res) cout << i << " ";
    }
    return 0;
}

//acc

/*
13 4 2
4 1 7 2 6 3 5 1 7 5 3 4 3
*/