#include<bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(0);cin.tie(0);

/*
Tuyến đường ven biển của thành phố Highland có N chiếc đèn. Không may cơn bão vừa
rồi đã làm hỏng B chiếc đèn.
Để khắc phục sự cố và nhanh chóng khôi phục lại hoạt động du lịch, chính quyền thành
phố đã quyết định sửa tạm thời một số đèn đường bị hỏng sao cho có ít nhất một khu vực
có K chiếc đèn liên tiếp hoạt động.
Các bạn hãy xác định xem số đèn đường cần phải sữa chữa ít nhất là bao nhiêu?
*/
int main(){
    FAST;
    int n,k,b;
    cin >> n >> k >> b;
    vector<int> a(n,0);
    for(int i=0;i<b;i++){
        int x;cin >> x;
        a[--x] = 1;
    }

    int cnt = 0;
    int res = 0;
    for(int i=0;i<k;i++){
        cnt += a[i];
    }
    res = cnt;
    for(int i=k;i<n;i++){
        if(a[i - k] == 1) cnt--;//cua so truoc
        if(a[i] == 1) cnt++;//moi them vao
        res = min(res,cnt);
    }
    cout << res;
}