//upper/lower
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a = {2,4,6,8,8,8,11,13};
    cout << *upper_bound(a.begin(),a.end(),7);//nho nhat > han 7
    cout << *lower_bound(a.begin(),a.end(),4);//nho nhat lon hon or bang 4
}