#include<bits/stdc++.h>
using namespace std;

/*
Bài 1. Cửa sổ lớn nhất
Cho mảng số nguyên có n phần tử và số nguyên dương k. Tìm dãy con liên tiếp của mảng
có độ dài k sao cho tổng các phần tử trong dãy con là lớn nhất và liệt kê dãy con đó. Nếu
có nhiều dãy con có cùng tổng lớn nhất thì in ra dãy con đầu tiên*/

int main(){
    //k <= n
    int n,k;cin >> n >> k;
    vector<int> a(n,0);
    vector<int> b;
    for(int &x : a) cin >> x;
    b = a;
    int index = 0;
    for(int i=1;i<n;i++){
        a[i] += a[i-1];
    }
    int res = -1e9;
    for(int i=0;i< n - k;i++){
        int tmp = 0;
        if(i == 0){
            tmp = a[i + k - 1];
        }
        else{
            tmp = a[i + k - 1] - a[i-1];
        }
        if(tmp > res){
            res = tmp;
            index = i;
        }
    }
    cout << res << endl;
    for(int i=0;i<k;i++) cout << b[i + index] << " ";
}

/*
10 3
1 2 3 1 5 2 7 8 9 1*/