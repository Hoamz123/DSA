#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin >> n;
    while(n--){
        int ok = -1;
        int g,w,r,t;cin >> g >> w >> r >> t;
        int tmp = 0;
        vector<pair<int,int>> G;
        vector<pair<int, int>> W;
        vector<pair<int, int>> R;
        while(tmp < t + 5){
            //G
            G.push_back({tmp,tmp + g - 1});
            tmp += g;
            W.push_back({tmp,tmp + w - 1});
            tmp += w;
            R.push_back({tmp,tmp + r - 1});
            tmp += r;
        }
        for(auto it : G){
            if(t >= it.first && t <= it.second){
                cout << "Guiding Beat" << endl;
                ok = 1;
                break;
            }
        }
        if(ok != 1){
            for(auto it : W){
                if(t >= it.first && t <= it.second){
                    cout << "Warning Beat" << endl;
                    ok = 1;
                    break;
                }
            }
        }
        
        if(ok != 1){
            for(auto it : R){
                if(t >= it.first && t <= it.second){
                    cout << "Resting Phase" << endl;
                    ok = 1;
                    break;
                }
            }
        }
    }
    // ICPC 2024 vòng Quốc gia - D: Dune
}
/*
Warning Beat
Resting Phase
Guiding Beat
*/

/*
3 5 2 6
0 2 10 12
3 7 13 17
8 9 18 19
*/