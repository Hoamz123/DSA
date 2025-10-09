#include<bits/stdc++.h>
using namespace std;

/*
cho hai mang a b -> f[i][j] = a[i] + b[j]
hay tim hinh chu nhat co kich co w-h có tổng lớn nhất
*/
int main(){
    int n,m,w,h;cin >> n >> m >> w >> h;
    vector<int> a(n,0),b(m,0);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int j=0;j<m;j++) cin >> b[j];
    int sum1 = 0,sum2 = 0;

    //tinh sum1
    for(int i=0;i<h;i++){
        sum1 += a[i];
    }
    int s1 = sum1;

    for(int i=h;i<n;i++){
        s1 = s1 - a[i-h] + a[i];
        sum1 = max(sum1,s1);
    }

    //tinh sum2
    for(int i=0;i<w;i++){
        sum2 += b[i];
    }
    int s2 = sum2;
    for(int i=w;i<m;i++){
        s2 = s2 - b[i-w] + b[i];
        sum2 = max(sum2,s2);
    }
    cout << w * sum1 + h * sum2;
}
/*
3 4 2 2
1 -1 2
1 1 1 1
out ; 6
*/