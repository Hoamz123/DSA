
//chuyen tu dx ke sang ds canh
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin >> n;
    cin.ignore();
    vector<pair<int,int>> p;
    string s;
    for(int i=1;i<=n;i++){
        getline(cin,s);
        stringstream ss(s);
        string tmp;
        while(ss >> tmp){
            if(stoi(tmp) > i){
                //tm xap xep tang dan -> mot canh viet 1 lan
                p.push_back({i,stoi(tmp)});
            }
        }
    }
    cout << endl;
    for(auto it : p){
        cout << it.first << " " << it.second << endl;
    }
}
/*
5
4
3 4 5
2 5
1 2
2 3
*/