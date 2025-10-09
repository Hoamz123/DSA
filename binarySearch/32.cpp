#include<bits/stdc++.h>
using namespace std;

class Skiplist {
public:
    vector<int> ve;
    Skiplist() {
        
    }

    bool search(int target) {
        int low = 0,high = ve.size() - 1;
        while(low <= high){
            int mid = (low) + (high - low) / 2;
            if(ve[mid] == target) return true;
            else if(ve[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
    
    void add(int num) {
        //tim iterator cua phan tu nho nhat >= num -> chen vao day
        auto it = lower_bound(ve.begin(),ve.end(),num);
        if(it == ve.end()) ve.push_back(num);
        else{
            ve.insert(it,num);
        }
    }
    
    bool erase(int num) {
        if(!search(num)) return false;
        //neu ton tai -> chac chan se tim dc iterator
        auto it = lower_bound(ve.begin(),ve.end(),num);
        ve.erase(it);
        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */

// acc
// https://leetcode.com/problems/design-skiplist/