#include<bits/stdc++.h>
using namespace std;

///dem so thanh phan lien thong



vector<int> p[1001];
vector<int> vst(1001,0);
int n, m, s;
void DFS(int s){
    vst[s] = 1;
    for(int u : p[s]){
        if(!vst[u]){
            DFS(u);
        }
    }
}


int count(){
    int cnt = 0;
    for(int i = 1;i<=n;i++){
        if(!vst[i]){
            cnt++;
            DFS(i);
        }
    }
    return cnt;
}

int main(){
    cin >> n >> m >> s;

    for(int i = 0;i<m;i++){
        int x,y;cin >> x >> y;
        p[x].push_back(y);
        p[y].push_back(x);
    }

    cout << count();

}

/*
5 5 3
5 2
3 2
5 4
5 3
5 1*/