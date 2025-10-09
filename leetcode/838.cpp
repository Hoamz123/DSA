//leetcode
#include<bits/stdc++.h>
using namespace std;

string pushDominoes(string s) {
    int n = s.size();
    vector<int> forces(n, 0);
    
    // Quét từ trái sang phải
    int force = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R') force = n;
        else if (s[i] == 'L') force = 0;
        else force = max(force - 1, 0);
        forces[i] += force;
    }

    for(int i : forces) cout << i << " ";
    cout << endl;

    // Quét từ phải sang trái
    force = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'L') force = n;
        else if (s[i] == 'R') force = 0;
        else force = max(force - 1, 0);
        forces[i] -= force;
    }

    for(int i : forces) cout << i << " ";
    cout << endl;

    // Tạo kết quả cuối
    string result = "";
    for (int f : forces) {
        if (f == 0) result += '.';
        else if (f > 0) result += 'R';
        else result += 'L';
    }

    return result;
}

int main(){
    cout << pushDominoes(".L.R...LR..L..");
}

/*
0 0 0 14 13 12 11 0 14 13 12 0 0 0
-13 -14 0 14 2 0 -2 -14 14 1 -1 -14 0 0
*/

/*
.L.R...LR..L..*/
