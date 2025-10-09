#include<bits/stdc++.h>
using namespace std;
const int sz = 1e5 + 5;

vector<int> egdes[sz];
vector<int> in(sz,0);
vector<int> dist(sz,0);//dist[i] duong di dai nhat ket thuc tai i
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        egdes[a].push_back(b);
        in[b]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(in[i] == 0){
            q.push(i);//luu lai cac  dinh tiem nang
        }
    }
    while(!q.empty()){
        int u = q.front();q.pop();
        for(int v : egdes[u]){
            in[v]--;
            if(in[v] == 0) q.push(v);
            dist[v] = max(dist[v],dist[u] + 1);
        }
    }
    int ans = 0;
    for(int i =1;i<=n;i++){
        ans = max(ans,dist[i]);
    }
    cout << ans;
    //acc
}
