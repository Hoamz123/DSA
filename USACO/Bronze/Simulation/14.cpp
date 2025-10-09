#include <bits/stdc++.h>
using namespace std;

const long long LINF = 2e18;
const int mxN = 110;

int n;
long long A, B;
long long x[mxN], y[mxN], c[mxN];

bool works(long long remA, long long remB){
    for(int i = 0; i < n; i++)
        if((A - remA) * x[i] + (B - remB) * y[i] > c[i])
            return false;
    return true;
}

long long bin(long long remA){
    long long l = 0, r = B - 1;
    if(!works(remA, r) || remA < 0 || remA >= A) return LINF;
    while(l < r){
        long long mid = (l + r) / 2;
        if(works(remA, mid)) r = mid;
        else l = mid + 1;
    }
    return remA + l;
}

void solve(){
    cin >> n >> A >> B;
    long long ans = A + B - 2;
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i] >> c[i];
    for(int _ = 0; _ < 2; _++){
        long long l = 0, r = A - 1;
        while(r - l > 3){
            long long m = (r - l) / 3;
            long long X = bin(l + m), Y = bin(r - m);
            if(X == LINF || X > Y) l += m;
            else r -= m;
        }
        for(long long i = l; i <= r; i++)
            ans = min(ans, bin(i));
        swap(A, B);
        for(int i = 0; i < n; i++) swap(x[i], y[i]);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}
