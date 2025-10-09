#include<bits/stdc++.h>
using namespace std;

class SummaryRanges {
public:
    set<int> se;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        se.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<int> v = vector<int>(se.begin(),se.end());
        
        if((int)v.size() == 1) return {{v[0],v[0]}};
        vector<vector<int>> ans;
        int start;
        for(int i=0;i<(int)v.size();i++){
            start = v[i];
            while(i + 1 < (int)v.size() && v[i+1] == v[i] + 1){
                i++;
            }
            ans.push_back({start,v[i]});
        }
        sort(ans.begin(),ans.end(),[](vector<int>&a,vector<int>&b){
            return a[0] < b[0];
        });
        return ans;
    }
};

//acc : beat 100%(hard)

void show(vector<vector<int>> &v){
    for(auto it : v){
        cout << it[0] << " " << it[1] << endl;
    }
    cout << endl;
}

int main(){
    vector<vector<int>> v;
    SummaryRanges s;
    s.addNum(1);
    v = s.getIntervals();
    show(v);
    s.addNum(3);
    v = s.getIntervals();
    show(v);
    s.addNum(7);
    v = s.getIntervals();
    show(v);
    s.addNum(2);
    v = s.getIntervals();
    show(v);
    s.addNum(6);
    v = s.getIntervals();
    show(v);
}