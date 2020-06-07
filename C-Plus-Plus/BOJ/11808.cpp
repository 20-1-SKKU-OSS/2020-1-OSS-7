#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF ((ll)1e18)

int n, k;
ll dp[1010][110];
vector<pair<int,ll>> graph[1010];

void DFS(int u){
    for(int i=1; i<=k; ++i) dp[u][i] = -INF;
    if(u!=1) dp[u][1] = 0;
    for(auto x : graph[u]){
        int v = x.first;
        ll w = x.second;
        DFS(v);
        for(int i=k; i>=1; --i){
            for(int j=1; j<=i; ++j){
                if(dp[v][j] < 0 || dp[u][i-j] < 0) continue;
                dp[u][i] = max(dp[u][i], dp[u][i-j] + dp[v][j] + 2LL * min(j, k+1-j) * w);
            }
        }
    }
}

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        scanf("%d%d", &n, &k);
        for(int i=1; i<=n; ++i) graph[i].clear();
        for(int i=2; i<=n; ++i){
            int x; ll y;
            scanf("%d%lld", &x, &y);
            graph[x].push_back(make_pair(i,y));
        }
        memset(dp, 0, sizeof(dp));
        
        DFS(1);
        printf("Case %d: %lld\n", tt, dp[1][k]);
    }
}