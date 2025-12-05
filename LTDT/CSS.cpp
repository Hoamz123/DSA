#include<bits/stdc++.h>
using namespace std;

vector<int> adj[101];//danh sach ke
vector<int> r_adj[101];//cung la ds ke nhung nguoc - >Transpose Graph
vector<int> vst(101,0);
stack<int> st;
int n,m;

//thuat toan k kiem tra tinh lien thong manh cua do thi co huong ///lien thong manh la co duong di tu moi dinh -> moi dinh khac
void dfs(int u){
    vst[u] = 1;
    for(int x : adj[u]){
        if(!vst[x]){
            dfs(x);
        }
    }
    //chay den day -> khong the di tiep tu dinh u nua -> push
    st.push(u);
}

void dfs2(int u){
    cout << u << " ";
    vst[u] = 1;
    for(int x : r_adj[u]){
        if(!vst[x]){
            dfs2(x);
        }
    }
}

void css(){
    vst = vector<int>(101, 0);
    for(int i = 1;i<=n;i++){
        if(!vst[i]){
            dfs(i);
        }
    }
    vst = vector<int>(101, 0);
    int cnt = 0;
    while(!st.empty()){
        int u = st.top();st.pop();
        if(!vst[u]){
            dfs2(u);
            //chay dc xuong day -> da xet xong 1 thanh phan lien thong
            cout << endl;
            cnt++;
        }
    }
    (cnt == 1) ? cout << "YES" : cout << "NO";
}

int main(){
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int x,y;cin >> x >> y;
        adj[x].push_back(y);
        r_adj[y].push_back(x);
    }
    css();
}