#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct A{
    ll x;
    int r, l, u, d;
    bool erased;
};

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int n, m;
        ll s = 0, ans = 0;
        scanf("%d%d", &n, &m);
        vector<vector<A>> arr(n+2, vector<A>(m+2));
        for(int i=1; i<=n; ++i){
            for(int j=1; j<=m; ++j){
                scanf("%lld", &arr[i][j].x);
                s += arr[i][j].x;
                arr[i][j].r = j+1;
                arr[i][j].l = j-1;
                arr[i][j].u = i-1;
                arr[i][j].d = i+1;
                arr[i][j].erased = false;
            }
        }
        for(int i=1; i<=n; ++i) arr[i][0].x = arr[i][m+1].x = -1;
        for(int i=1; i<=m; ++i) arr[0][i].x = arr[n+1][i].x = -1;
        ans = s;
        while(true){
            bool chk = false;
            for(int i=1; i<=n; ++i){
                for(int j=1; j<=m; ++j){
                    if(!arr[i][j].x) continue;
                    ll xs = 0, xc = 0;
                    while(arr[i][arr[i][j].r].x==0) ++arr[i][j].r;
                    if(arr[i][arr[i][j].r].x != -1){ ++xc; xs += arr[i][arr[i][j].r].x; }
                    while(arr[i][arr[i][j].l].x==0) --arr[i][j].l;
                    if(arr[i][arr[i][j].l].x != -1){ ++xc; xs += arr[i][arr[i][j].l].x; }
                    while(arr[arr[i][j].u][j].x==0) --arr[i][j].u;
                    if(arr[arr[i][j].u][j].x != -1){ ++xc; xs += arr[arr[i][j].u][j].x; }
                    while(arr[arr[i][j].d][j].x==0) ++arr[i][j].d;
                    if(arr[arr[i][j].d][j].x != -1){ ++xc; xs += arr[arr[i][j].d][j].x; }
                    if(arr[i][j].x * xc < xs){ s -= arr[i][j].x; arr[i][j].erased = true; chk = true; }
                }
            }
            if(!chk) break;
            ans += s;
            for(int i=1; i<=n; ++i){
                for(int j=1; j<=m; ++j){
                    if(arr[i][j].erased) arr[i][j].x = 0;
                }
            }
        }
        printf("Case #%d: %lld\n", tt, ans);
    }
}