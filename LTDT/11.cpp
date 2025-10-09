#include<bits/stdc++.h>
using namespace std;

///tim duong di giua hai dinh tren do thi

int n,m,s,t;
//di tu s den dinh t
vector<int> p[1001];
vector<int> vst(1001,0);
vector<int> pr(1001,0);

void dfs(int s){
    vst[s] = 1;
    for(int u : p[s]){
        if(!vst[u]){
            //ghi nhan cha cua u la s
            pr[u] = s;
            dfs(u);
        }
    }
}


void bfs(int s){
    queue<int> que;//FIFO
    que.push(s);
    vst[s] = 1;
    while(!que.empty()){
        int u = que.front();que.pop();
        for(int x : p[u]){
            if(!vst[x]){
                que.push(x);
                pr[x] = u;
                vst[x] = 1;
            }
        }
    }
}


int main(){
    cin >> n >> m;
    for(int i =0;i<m;i++){
        int x,y;cin >> x >> y;
        p[x].push_back(y);
        p[y].push_back(x);
    }

    cin >> s >> t;
    bfs(s);

    if(!vst[t]){
        //chua di toi (ko toi dc)
        cout << "NOT";
    }
    else{
        vector<int> path;
        ///bat dau tu dinh ket thuc
        while(t != s){
            path.push_back(t);
            t = pr[t];//cho t = cha cua no de lat ngc -> t == s -> while dung
        }
        path.push_back(s);
        reverse(path.begin(),path.end());
        for(int u : path){
            cout << u << " ";
        }
    }
}
/*
10 8
1 2
2 3
2 4
3 6
3 7
6 7
5 8
8 9
*/
