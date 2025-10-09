#include<bits/stdc++.h>
using namespace std;

bool carPooling(vector<vector<int>> &trips, int capacity)
{
    int a[1001] = {0};
    for(auto it : trips){
        int from = it[1];int to = it[2];
        a[from] += it[0];
        a[to] += -1 * it[0];
    }
    
    int check = 0;
    for(int i=0;i<1001;i++){
        check += a[i];
        if(check > capacity) return false;
    }
    return true;
    //acc
}

int main(){
    vector<vector<int>> v = {{2,1,5},{3,5,7}};
    cout << carPooling(v,3);
}