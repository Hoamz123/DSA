#include<bits/stdc++.h>
using namespace std;

/*
cho mang ko giam
hay binh phuong tat ca cac phan tu trong mang roi in ra theo thu tu ko giam
*/

/*
y tuong thay rang mang ban dau ko giam -> cang ve sau cang lon
ta dat 1 con tro o dau 1 con o cuoi
ta thay la |a[l]| >= |a[r]| -> khi do binh phuong nen chac chan al se lon hon ar -> ta se cho a[l]^2 vao cuoi cua mang result -> va dho da lay a[l] nen ta se dich sang phai
tuong tu neu ta lay a[r] thi ta se dich sang trai
*/
int main(){
    int n;cin >> n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin >> a[i];
    int l=0,r = n-1;
    int pos = n - 1;
    vector<int> res(n,0);
    while(l <= r && pos >= 0){
        int valLeft = abs(a[l]);
        int valRight = abs(a[r]);
        if(valLeft >= valRight){
            res[pos--] = valLeft * valLeft;
            l++;
        }
        else{
            res[pos--] = valRight * valRight;
            r--;
        }
    }
    for(int i : res) cout << i << " ";
}