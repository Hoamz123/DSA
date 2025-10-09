// Search in a 2D Matrix - I | Binary Search of 2D
#include<bits/stdc++.h>
using namespace std;

int bs(const int a[],int n,int target){
    int idx = -1;
    int low = 0,high = n-1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(a[mid] == target){
            idx = mid;
            high = mid - 1;
        }
        else if(a[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return idx;
}

int main(){
    int n,m,target;cin >> n >> m >> target;
    int a[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) cin >> a[i][j];

    int index = 0;
    for(int i=1;i<n;i++){
        if(a[i][m-1] >= target && a[i-1][m-1] <= target){
            index = i;
            break;
        }
    }
    cout << index << " " << bs(a[index],m,target);
}

/*
3 4 21
3 4 7 9
12 13 16 18
20 21 23 29
*/

