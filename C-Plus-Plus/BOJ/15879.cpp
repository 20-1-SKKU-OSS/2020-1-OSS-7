#include<bits/stdc++.h>
using namespace std;

#define MOD 100000007

int V, E, C, s;
bool chk[110];
vector<int> graph[110];
void dfs(int node){
    chk[node] = true; ++s;
    for(auto next : graph[node]){
        if(chk[next]) continue;
        dfs(next);
    }
}
int pow2(int x){
    if(x<=0) return 1;
    int ret=1;
    for(;x--;ret*=2)ret%=MOD;
    return ret%MOD;
}
int main()
{
    scanf("%d%d", &V, &E);
    for(int i=1; i<=E; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i=1; i<=V; ++i){
        if(chk[i]) continue;
        ++C; s = 0;
        dfs(i);
        if(s%2){ printf("0\n"); return 0; }
    }
    printf("%d\n", pow2(E-V+C));
}