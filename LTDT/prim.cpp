

//giai thuat prim de tim cay khung nho nhat

/**
 * y tuong :
 * cho tat ca cac dinh vao mot nhom V
 * tao mot nhom V-MST rong
 * -> B1 : chon ra dinh bat ki trong V them vao V_MST
 * -> Chon ra canh co trong so nho nhat tao thanh tu 1 dinh cua V va 1 dinh cau V-MST (dieu kien -> ko tao thanh chu trinh)
 */

#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[1001];//xet do thi co toi da 1001 dinh
int n,m;//so dinh,so canh
vector<int> used(1001,0);// 1 : dinh thuoc V_MST ,0 : dinh thuoc V

struct edge{
    int u,v;
    int w;
};

void prim(int u){
    //1: khoi tao 1 tao tap V_MST;
    vector<edge> mst;
    int ww = 0;//tong trong so cua cay khung
    used[u] = 1;//them dinh u vao tap mst

    //2  :lap -> khi so luong phan tu trong mst = n -1 -> thoa man la mot cay khung
    while((int)mst.size() < n - 1){
        int min_w = 1e9;//trong so nho nhat
        //duyuet tat ca cac dinh
        int u,v;
        for(int i = 1;i<=n;i++){
            if(used[i]){
                //duyet danh sach ke cua dinh i
                for(auto it : adj[i]){
                    int j = it.first;
                    if(!used[j] && it.second < min_w){
                        min_w = it.second;
                        u = i;
                        v = j;
                    }
                }
            }
        }
        mst.push_back({u,v,min_w});
        ww += min_w;
        used[v] = 1;
    }
    for(auto it : mst){
        cout << it.u << " " << it.v << " " << it.w << endl;
    }
    cout << ww << endl;
}

int main(){

    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int u,v,w;cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    cout << endl;
    prim(1);
    return 0;
}