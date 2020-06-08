#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int V, E, ans, ANS = 2147483647;
struct A
{
    int x, y, cost;
    bool operator()(A a, A b)
    {
        return a.cost < b.cost;
    }
};
A edges[200010];
int parents[50010][20], depth[50010], maxl[50010][20];
bool chk[200010];
vector<pair<int,int> > MST[50010];
int uf[50010];
int getmax(int x, int y){ return x<y?y:x; }
pair<int,int> mk_pair(int x, int y)
{
    pair<int,int> pa;
    pa.first = x;
    pa.second = y;
    return pa;
}
int Find(int p){ return uf[p] = (uf[p]==p?p:Find(uf[p])); }
void Union(int p, int q){ uf[p] = q; }
void dfs(int node, int par, int dep, int dist)
{
    int tmp = 2, i=1;
    depth[node] = dep;
    if(dep>0){ parents[node][0] = par; maxl[node][0] = dist; }
    while(tmp<=dep)
    {
        parents[node][i] = parents[parents[node][i-1]][i-1];
        maxl[node][i] = getmax(maxl[node][i-1], maxl[parents[node][i-1]][i-1]);
        tmp*=2; ++i;
    }
    for(i=0; i<MST[node].size(); ++i)
    {
        int next = MST[node][i].first;
        if(next == par) continue;
        dfs(next, node, dep+1, MST[node][i].second);
    }
}
pair<int,int> nthparent(int node, int num)
{
    pair<int,int> pa;
    pa.second = 0;
    int i=0;
    while(num)
    {
        if(num&(1<<i))
        {
            num -= (1<<i);
            pa.second = getmax(pa.second, maxl[node][i]);
            node = parents[node][i];
        }
        ++i;
    }
    pa.first = node;
    return pa;
}
pair<int,int> get_max_edge(int x, int y)
{
    if(depth[x]<depth[y]) x^=y^=x^=y;
    pair<int,int> pa = nthparent(x, depth[x]-depth[y]);
    int ret = pa.second;
    x = pa.first;
    if(x==y)
    {
        pa.first = x;
        pa.second = ret;
        return pa;
    }
    int tmp = 19;
    while(1)
    {
        while(tmp>=0 && (depth[x]<(1<<tmp) || parents[x][tmp]==parents[y][tmp])) --tmp;
        if(tmp<0)
        {
            ret = getmax(ret, maxl[x][0]);
            ret = getmax(ret, maxl[y][0]);
            x = parents[x][0];
            break;
        }
        ret = getmax(ret, maxl[x][tmp]);
        ret = getmax(ret, maxl[y][tmp]);
        x = parents[x][tmp];
        y = parents[y][tmp];
    }
    pa.second = ret;
    pa.first = x;
    return pa;
}
int main()
{
    int i, j;
    scanf("%d%d", &V, &E);
    for(i=1; i<=V; ++i) uf[i]=i;
    for(i=1; i<=E; ++i)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        edges[i].x = x;
        edges[i].y = y;
        edges[i].cost = z;
    }
    sort(&edges[1], &edges[E+1], A());
    int cnt=0;
    for(i=1; i<=E && cnt<V-1; ++i)
    {
        int x=edges[i].x, y=edges[i].y;
        x = Find(x); y = Find(y);
        if(x == y) continue;
        Union(x, y);
        ++cnt;
        ans += edges[i].cost;
        chk[i] = true;
        x = edges[i].x; y = edges[i].y;
        MST[x].push_back(mk_pair(y, edges[i].cost));
        MST[y].push_back(mk_pair(x, edges[i].cost));
    }
    if(cnt<V-1 || E<=V-1){ printf("-1\n"); return 0; }
    dfs(1, -1, 0, -1);
    for(i=1; i<=E; ++i)
    {
        if(chk[i]) continue;
        pair<int,int> tmp = get_max_edge(edges[i].x, edges[i].y);
        if(tmp.second == edges[i].cost)
        {
            int lca = tmp.first, M = -1;
            int x = edges[i].x, y = edges[i].y;
            while(x != lca)
            {
                if(maxl[x][0] != edges[i].cost) M = getmax(M, maxl[x][0]);
                x = parents[x][0];
            }
            while(y != lca)
            {
                if(maxl[y][0] != edges[i].cost) M = getmax(M, maxl[y][0]);
                y = parents[y][0];
            }
            if(M>=0 && edges[i].cost > M && ANS > ans-M+edges[i].cost) ANS = ans-M+edges[i].cost;
        }
        else if(ANS > ans-tmp.second+edges[i].cost) ANS = ans-tmp.second+edges[i].cost;
    }
    printf("%d\n", ANS==2147483647?-1:ANS);
}