#include<bits/stdc++.h>
using namespace std;

///1 : goi thuat toan dfs tren do thi ban dau va luu vao mot stack
///2 : Xay dung do thi lat nguoc cua do thi ban dau : Transpose graph
///3 : Lan luot pop cac dinh trong stack o buoc 1 va goi dfs de liet ke cac thanh phan lien thong manh
//O(2*(V+E))

vector<int> adj[101];
vector<int> r_adj[101];
vector<int> vst(101,0);

int n,m;//n canh , m dinh
stack<int> st;

void dfs(int u){
    vst[u] = 1;
    for(int x : adj[u]){
        if(!vst[x]){
            dfs(x);
        }
    }
    //sau khi da tham xong het
    st.push(u);
}

void dfs2(int u){
    vst[u] = 1;
    cout << u << " ";
    for(int x : r_adj[u]){
        if(!vst[x]){
            dfs2(x);
        }
    }
}

bool check(){
    vst = vector<int> (101,0);
    for(int i = 1;i<=n;i++){
        if(!vst[i]) dfs(i);
    }

    int cnt = 0;//dem so thanh phan lien thong manh
    vst = vector<int>(101, 0);
    while(!st.empty()){
        int u = st.top();st.pop();
        if(!vst[u]){
            dfs2(u);
            cout << endl;
            cnt++;
        }
    }
    cout << cnt << endl;
    return (cnt == 1) ? true : false;
}

int main(){
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int x,y;cin >> x >> y;
        adj[x].push_back(y);
        r_adj[y].push_back(x);
    }
    if(check()) cout << "Yes";
    else cout << "No";
    return 0;
}


/*

//co huong

8 9
1 2
2 3
3 4
4 1
3 5
5 6
6 7
7 8
8 6


*/