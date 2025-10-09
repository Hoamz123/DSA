//und dung thuat toan kahn de kiem tra chu trinh cua do thi

#include<bits/stdc++.h>
using namespace std;


int n,m;
vector<int> adj[101];
vector<int> in(101,0);

int cnt = 0;
bool kahn(){
    queue<int> que;
    for(int i = 1;i<=n;i++){
        if(in[i] == 0){//neu co ban bac vao = 0
            //day vao hang doi
            que.push(i);
        }
    }

    while(!que.empty()){
        int u = que.front();que.pop();
        cnt++;
        for(int v : adj[u]){
            in[v]--;//giam ban bac vao cua v di 1
            if(in[v] == 0) que.push(v);
        }
    }
    return cnt != n;
}

int main(){
    cin >> n>> m;
    for(int i =0;i<m;i++){
        int x,y;cin >> x >> y;
        adj[x].push_back(y);
        in[y]++;
    }

    if(kahn()) cout << "yes";
    else cout << "no";
}
/*

7 7
1 2
1 5
2 3
4 2
3 6
6 7
7 3
yes
*/
