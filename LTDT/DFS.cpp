
//thuat toan DFS tim kiem theo chieu sau
#include<bits/stdc++.h>
using namespace std;

// int n,m,s;

// vector<int> p[1001];

// vector<int> vst(1001,0);
// void DFS(int s){
//     cout << s << " ";
//     vst[s] = 1;//danh dau da duyet qua
//     for(int u : p[s]){
//         if(!vst[u]){
//             //neu dinh u chua dc duwyt qua
//             DFS(u);
//         }
//     }
// }

// int main(){
//     cin >> n >> m >> s;
//     int u, v;
//     for(int i = 0;i<m;i++){
//         cin >> u >> v;
//         p[u].push_back(v);
//         p[v].push_back(u);
//     }

//     for(int i = 1;i<=n;i++){
//         sort(p[i].begin(),p[i].end());
//     }
//     DFS(s);
// }

/*
5 5 3
5 2
3 2
5 4
5 3
5 1
*/

int n,m,s;
vector<int> p[1001];
vector<int> vst(1001,0);

void DFS(int s){
    cout << s << " ";
    vst[s] = 1;
    for(int u : p[s]){
        if(!vst[u]){
            DFS(u);
        }
    }
}




int main(){
    cin >> n >> m >> s;
    for(int i = 0;i<m;i++){
        int x,y;cin >> x >> y;
        p[x].push_back(y);
        p[y].push_back(x);
    }

    for(int i = 1;i<=n;i++){
        sort(p[i].begin(),p[i].end());
    }

    DFS(s);

    

}