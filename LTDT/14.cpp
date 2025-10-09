// xap xep topo neu co the di tu dinh A -> dinh B thi dinh A phai xuat hien trc dinh B
//khong ap dung cho do thi co chu trinh vi diem dau va diem cuoi co the di den dc nhau
// cach 2;

// do thi co huong
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> p[1001];
vector<int> vst(1001,0);
vector<int> in(1001,0);
vector<int> topo;
int idx = 0;

void kahn(){
    queue<int> que;
    //duyet n dinh -> dinh nao ban bac vao = 0 -> day vao que
    for(int i = 1;i<=n;i++){
        if(in[i] == 0){
            que.push(i);
        }
    }

    while(!que.empty()){
        int u = que.front();que.pop();
        topo[idx++] = u;
        ///duyet tat ca cac dinh ke cua dinh u -> cho
        for(int v : p[u]){
            //p[u] la tap hop cac dinh ke cua u
            in[v]--;//bot 1 ban bac vao cua v
            if(in[v] == 0){
                que.push(v);
            }
        }
    }
    for(int i : topo) cout << i << " ";
}

int main(){
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int x,y;cin >> x >> y;
        p[x].push_back(y);
        in[y]++;
    }

    topo = vector<int> (n,0);
    kahn();
}