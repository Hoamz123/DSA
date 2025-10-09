//chuyen tu ds ke -> sang ds canh (co huong)
#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> p;

bool cmd(pair<int,int> a,pair<int,int> b){
    if(a.first != b.first) return a.first <= b.first;
    return a.second <= b.second;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin >> n;
    cin.ignore();

    string s;
    for(int i = 1;i<=n;i++){
        getline(cin,s);
        stringstream ss(s);string x;
        while(ss >> x){
            p.push_back({i,stoi(x)});
        }
    }
    cout << endl;
    sort(p.begin(),p.end(),cmd);
    for(auto it : p){
        cout << it.first << " " << it.second << endl;
    }
}

/*
5
5 3 4
4 1 3 5
4 2
3 1 2
3 2
*/