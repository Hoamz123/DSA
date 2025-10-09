#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;cin >> s;
    int res = -1;
    int idxStart = 0;
    int ch[256];
    memset(ch,-1,sizeof(ch));
    for(int l = 0,r = 0;r < (int)s.size();r++){
        if(ch[(int)s[r]] != -1){
            //da gap roi
            if(l < r && ch[(int)s[r]] >= l){
                l = ch[(int)s[r]] + 1;
            }
        }
        int tmp = r - l + 1;
        if(tmp > res){
            res = tmp;
            idxStart = l;
        }
        ch[(int)s[r]] = r;
    }
    cout << res << endl;
    for(int i=0;i<res;i++){
        cout << s[i + idxStart];
    }
}

// cadbzabcd