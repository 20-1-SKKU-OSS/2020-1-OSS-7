#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
#define F first
#define S second
#define MP make_pair

int n, m;
ll graph[110][110];

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        scanf("%d%d", &n, &m);
        vector<pll> X;
        vector<pll> sed(n, {0,0});
        vector<pll> edges;
        sed[0].F = 1; sed[0].S = 0;
        for(int i=1; i<n; ++i){
            int x;
            scanf("%d", &x);
            if(x<0){
                for(int j=-x; j<n; ++j){
                    if(sed[j].F) continue;
                    sed[j].F = i+1; sed[j].S = x;
                    break;
                }
            }
            else X.push_back(MP(x,i+1));
        }
        sort(X.begin(), X.end());
        int t=0;
        for(auto p : X){
            while(sed[t].F) ++t;
            sed[t].F = p.S; sed[t].S = p.F;
        }
        int bef_x=0;
        for(int i=0; i<n; ++i){
            if(sed[i].S < 0){
                if(bef_x==sed[i].S) sed[i].S = sed[i-1].S;
                else{ bef_x = sed[i].S; sed[i].S = sed[i-1].S+1; }
            }
        }
        vector<ll> costs(n+1);
        for(auto p : sed){
            costs[p.F] = p.S;
        }
        memset(graph, 0, sizeof(graph));
        for(int i=0; i<m; ++i){
            int x, y;
            scanf("%d%d", &x, &y);
            edges.push_back({x,y});
            graph[x][y] = graph[y][x] = 1000000;
        }

        queue<pll> q;
        vector<bool> chk(n+1, false);
        q.push({1,0}); chk[1] = true;
        while(!q.empty()){
            pll f = q.front();
            ll node = f.F, cost = f.S;
            q.pop();
            for(int next=1; next<=n; ++next){
                if(graph[node][next]==0) continue;
                if(chk[next]) continue;
                if(costs[next] <= costs[node]) continue;
                chk[next] = true;
                graph[node][next] = graph[next][node] = costs[next] - costs[node];
                q.push({next, costs[next]});
            }
        }

        printf("Case #%d:", tt);
        for(auto e : edges){
            printf(" %lld", graph[e.F][e.S]);
        }
        printf("\n");
    }
}