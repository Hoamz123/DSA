#include<bits/stdc++.h>
using namespace std;
#define faster() {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define umi unordered_map<int,int>
#define si set<int>
#define pb push_back
#define is insert
#define mod 1000000007
#define INF 1000000001
#define nax 1000005
#define FOR1(i, n) for (int i = 1; i <= (n); i++)
#define FOR0(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define PER(i, a, b) for (int i = a; i >= b; --i)
#define endl '\n'
#define fi first
#define se second

struct cow{
    int id;
    int x,y;
};

bool cmp(const cow &a,const cow &b){
    return a.x < b.x;
}

bool cmp_(const cow &a,const cow &b){
    return a.y < b.y;
}

void solve(){
    int n;cin >> n;
    vector<cow> east,north;
    vi ans(n,-1);
    FOR0(i,n){
        char c;int x,y;
        cin >> c >> x >> y;
        if(c == 'N') north.pb({i,x,y});
        else east.pb({i,x,y});
    }

    sort(north.begin(),north.end(),cmp);
    sort(east.begin(),east.end(),cmp_);


    for(auto ea : east){
        for(auto no : north){
            if(ans[no.id] != -1) continue;//da bi chan roi
            if(ea.x < no.x && ea.y > no.y){
                int dx = no.x - ea.x;//so buoc de con bo ea den o chung
                int dy = ea.y - no.y;//so buoc de con bo no den o chung
                //con bo ea den truoc
                if(dx < dy){
                    ans[no.id] = dy;
                    // break;
                }
                else if(dy < dx){
                    ans[ea.id] = dx;
                    break;
                }
            }
        }
    }

    FOR0(i,n){
        if(ans[i] == -1) cout << "Infinity\n";
        else cout << ans[i] << endl;
    }
}

void solve1(){
    int n;cin >> n;
    vector<cow> norths,easts;
    FOR0(i,n){
        char c;int x,y;
        cin >> c >> x >> y;
        if(c == 'N') norths.pb({i,x,y});
        else easts.pb({i,x,y});
    }
    //bat dau tu toa do nho den tao do lon(tranh nhay coc)
    sort(norths.begin(),norths.end(),cmp);
    sort(easts.begin(),easts.end(),cmp_);
    vi ans(n,-1);
    
    for(cow east : easts){
        for(cow north : norths){
            if(ans[north.id] != -1) continue;
            if(east.x < north.x && east.y > north.y){
                //so buoc de EAST den dc o chung
                int stepEast = north.x - east.x;
                //so buoc de NORTH den dc o chung
                int stepNorth = east.y - north.y;
                if(stepEast < stepNorth){
                    //NORTH se bi chan
                    ans[north.id] = stepNorth;
                }
                else if(stepNorth < stepEast){
                    ans[east.id] = stepEast;
                    break;
                }
            }
        }
    }
    FOR0(i,n){
        if(ans[i] == -1) cout << "Infinity\n";
        else cout << ans[i] << endl;
    }
}

int main(){
    faster();
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    int t = 1;
    while(t--){
        solve1();
    }
}