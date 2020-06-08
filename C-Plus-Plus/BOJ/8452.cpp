#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define MP make_pair
#define F first
#define S second
#define MAX 99999

int n, m, q;
vector<pii> edges;
vector<pii> queries;
vector<bool> chk;
vector<int> graph[1010];
vector<int> dist;

void BFS(int st){
    queue<int> q;
    q.push(st);
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(int next : graph[node]){
            if(dist[next] > dist[node] + 1){
                dist[next] = dist[node] + 1;
                q.push(next);
            }
        }
    }
}

int main()
{
    int i, j;
    scanf("%d %d %d", &n, &m, &q);
    chk.resize(m, false);
    dist.resize(n, MAX);
    dist[0] = 0;
    for(int i=0; i<m; ++i){
        int x, y;
        scanf("\n%d %d", &x, &y);
        edges.push_back(MP(x-1,y-1));
    }
    for(int i=0; i<q; ++i){
        char t; int x;
        scanf("\n%c %d", &t, &x); --x;
        queries.push_back(MP(t=='U'?1:2, x));
        if(t=='U') chk[x] = true;
    }
    for(int i=0; i<m; ++i){
        if(chk[i]) continue;
        int s = edges[i].F, e = edges[i].S;
        graph[s].push_back(e);
    }
    BFS(0);

    vector<int> ans;
    for(int i=q-1; i>=0; --i){
        int t = queries[i].F, x = queries[i].S;
        if(t==1){
            int s = edges[x].F, e = edges[x].S;
            graph[s].push_back(e);
            BFS(s);
        }
        else{
            ans.push_back( dist[x]==MAX?-1:dist[x] );
        }
    }
    for(int i=ans.size()-1; i>=0; --i) printf("%d\n", ans[i]);
    return 0;
}