#include<bits/stdc++.h>
using namespace std;
//1007
#define INF 100000001
int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
{
    int res = INF;
    int n = tops.size();
    unordered_map<int,int> t,b;
    set<int> se;
    for(int x : tops){
        t[x]++;
        se.insert(x);
    }
    for(int x : bottoms){
        b[x]++;
        se.insert(x);
    }
    vector<int> ok;
    for(int x : se){
        if(t[x] + b[x] >= n) ok.push_back(x);
    }
    if(ok.empty()) return -1;
    for(int i=0;i<(int)ok.size();i++){
        int k = 0;
        for(int j=0;j<(int)tops.size();j++){
            if(tops[j] == ok[i]){
                continue;
            }
            else if(bottoms[j] == ok[i]) {
                k++;
            }
            else return -1;
        }
        res = min(res,k);
        int h = 0;
        for(int j=0;j<(int)bottoms.size();j++){
            if(bottoms[j] == ok[i]){
                continue;
            }
            else if(tops[j] == ok[i]) {
                h++;
            }
            else return -1;
        }
        res = min(res,h);
    }
    return res;
    //acc : chua toi uu
}

//code toi uu
int ans(vector<int> &tops,vector<int> &bottoms){
    
    for(int x = 1;x <= 6;x++){
        bool ok = true;int top = 0,bot = 0;
        for(int i=0;i<(int)tops.size();i++){
            if(tops[i] != bottoms[i] && tops[i] != x){
                ok = false;//ko thoa man
                break;
            }
            else if(tops[i] != x) top ++;
            else if(bottoms[i] != x) bot ++;
        }
        if(ok) return min(top,bot);
    }
    return -1;
    //acc
}

int main(){
    vector<int> a = {2, 3, 2, 1, 1, 1, 2, 2};
    vector<int> b = {2, 1, 2, 1, 1, 3, 1, 1};
    cout << ans(a,b);
}