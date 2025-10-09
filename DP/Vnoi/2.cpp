//de quy co nho
#include<bits/stdc++.h>
using namespace std;

int f[1001];

int fib(int n){
    if(n <= 1) return n;
    if(f[n] != -1) return f[n];
    return f[n] = fib(n-1) + fib(n-2);
}

int main(){
    memset(f,-1,sizeof(f));
    cout << fib(3);
}