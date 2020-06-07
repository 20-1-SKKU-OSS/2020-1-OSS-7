#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool chk[10000010];
int p[700000], c;
int x, y, z, w;
ll ans;

void dfs(int idx, int d, int cnt){
    //printf("%d %d\n", d, cnt);
    ans += ((cnt&1)?-1:1) * (ll)(y/d - (x-1)/d) * (ll)(w/d - (z-1)/d);
    for(int i=idx; i<=c && ((ll)d*(ll)p[i]<=(ll)y && (ll)d*(ll)p[i]<=(ll)w); ++i){
        dfs(i+1, d*p[i], cnt+1);
    }
}

int main()
{
    chk[1] = true;
    for(int i=3; i<=3200; i+=2){
        if(!chk[i]){
            for(int j=i*3; j<=10000000; j+=i+i) chk[j] = true;
        }
    }
    p[++c] = 2;
    for(int i=3; i<=10000000; i+=2) if(!chk[i]) p[++c] = i;
    scanf("%d%d%d%d", &x, &y, &z, &w);
    dfs(1, 1, 0);
    printf("%lld\n", ans);
}