#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> x;
int dp[310][310][2];
bool chk[310][310][2];

int f(int l, int r, int st, int k){
    if(k==0) return 0;
    if(chk[l][r][st]) return dp[l][r][st];
    chk[l][r][st] = true;
    int ret = 399999999;
    if(st==0){ // current stay in x[l]
        if(l>0) ret = min(ret, k*(x[l]-x[l-1]) + f(l-1, r, 0, k-1));
        if(r<n) ret = min(ret, k*(x[r+1]-x[l]) + f(l, r+1, 1, k-1));
    }
    else{
        if(l>0) ret = min(ret, k*(x[r]-x[l-1]) + f(l-1, r, 0, k-1));
        if(r<n) ret = min(ret, k*(x[r+1]-x[r]) + f(l, r+1, 1, k-1));
    }
    dp[l][r][st] = ret;
    return ret;
}

int main()
{
    scanf("%d%d", &n, &m);
    if(n==0){ printf("0\n"); return 0; }
    for(int i=1; i<=n; ++i){ int t; scanf("%d", &t); x.push_back(t); }
    x.push_back(0);
    sort(x.begin(), x.end());
    int ans = 0, idx = lower_bound(x.begin(), x.end(), 0) - x.begin();
    for(int k=0; k<=n; ++k){
        memset(dp, 0, sizeof(dp));
        memset(chk, 0, sizeof(chk));
        ans = max(ans, k*m - f(idx, idx, 0, k));
    }
    printf("%d\n", ans);
}