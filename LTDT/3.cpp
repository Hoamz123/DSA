//chuyen ds canh sang danh sach ke (co huong)
#include<bits/stdc++.h>
using namespace std;

vector<int> pr[1001];
int main(){
    int n;int m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int x,y;cin >> x >> y;
        pr[x].push_back(y);//co huong
    }
    for(int i = 1;i<=n;i++){
        cout << i << ": ";
        sort(pr[i].begin(),pr[i].end());
        for(int j : pr[i]) cout << j << " ";
        cout << endl;
    }
}
