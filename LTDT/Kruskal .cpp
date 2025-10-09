#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u,v;//dinh dau,dinh cuoi
    int w;//trong so
};

int n,m;
vector<edge> canh;//luu cac canh nhap vao
vector<int> sz(1001);//luu so luong dinh trong 1 tap hop
vector<int> pr(1001);//luu dinh cha (leader) cua dinh u

void make_set(){
    for(int i = 1;i<=n;i++){
        pr[i] = i;
        sz[i] = 1;
    }
}

int find(int v){
    //tra ve cha cua dinh v
    if(v == pr[v]) return v;
    return pr[v] = find(pr[v]);//toi uu nen duong
}

bool Union(int a,int b){
    //kiem cha xem dinh u va dinh v co gop -> ve chung 1 tap hop hay khong
    a = find(a);
    b = find(b);

    if(a == b) {
        //khong
        return false;
    }
    if(sz[a] < sz[b]) swap(a,b);//so luong phan tu cua a mac dinh lon hon sl phan tu cua b
    pr[b] = a;//gan b sang tap hop cua a thi cha cua b phai la a
    sz[a] += sz[b];//sl phan tu cua tap hop a sau khi them b
    return true;
}

bool cmp(edge a,edge b){
    return a.w < b.w;//sort trong so tang dan
}

void kruskal(){
    int ww = 0;//trong so cua cay khung ket qua
    vector<edge> mst;
    for(int i = 0;i<m;i++){
        if((int)mst.size() == n - 1) break;//thoa man n - 1 canh
        edge e = canh[i];//canh co trong so nho nhat
        if(Union(e.u,e.v)){
            mst.push_back(e);
            ww+=e.w;
        }
    }

    if((int)mst.size() == n - 1){
        for(auto it : mst){
            cout << it.u << " " << it.v << " " << it.w << endl;
        }
        cout << "Tong trong so : " << ww << endl;
    }
    else{
        //khong co cay khung tm
        cout<< "!OK" << endl;
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        edge e;
        e.u = u;e.v = v;e.w = w;
        canh.push_back(e);
    }
    make_set();
    cout << endl;
    sort(canh.begin(),canh.end(),cmp);
    kruskal();

}


/*
6 9
1 2 12
1 3 4
2 3 1
2 4 5
2 5 3
3 5 2
4 5 3
4 6 10
5 6 8


*/