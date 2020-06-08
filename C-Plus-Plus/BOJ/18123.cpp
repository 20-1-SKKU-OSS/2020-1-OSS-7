#include<bits/stdc++.h>
using namespace std;
#define ll long long

int N;
vector<int> graph[40];
int parent[40];

int max_dist, most_far;
void DFS(int node, int dist, int par){
    parent[node] = par;
    if(max_dist < dist){ max_dist = dist; most_far = node; }
    for(auto next : graph[node]){
        if(next == par) continue;
        DFS(next, dist+1, node);
    }
}

ll get_hash(int node, int par){
    ll ret = 1;
    vector<ll> ch_hash;
    for(auto child : graph[node]){
        if(child == par) continue;
        ch_hash.push_back(get_hash(child, node));
    }
    sort(ch_hash.begin(), ch_hash.end());
    for(auto h : ch_hash){
        ll tmp = 1;
        while(tmp <= h){
            tmp<<=1; ret<<=1;
        }
        ret |= h;
    }
    ret<<=1;
    return ret;
}

int main()
{
    vector<ll> tree_hash;
    scanf("%d", &N);
    for(int tc=1; tc<=N; ++tc){
        int V;
        scanf("%d", &V);
        for(int i=0; i<V; ++i) graph[i].clear();
        for(int i=1; i<V; ++i){
            int x, y;
            scanf("%d%d", &x, &y);
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        max_dist = -1; most_far = 0;  DFS(0, 0, -1);
        int n1 = most_far;
        max_dist = -1; most_far = n1; DFS(n1, 0, -1);
        int n2 = most_far;
        int center = n2;
        for(int i=1; i<=(max_dist/2); ++i)
            center = parent[center];
        ll hash = get_hash(center, -1);
        if(max_dist % 2 == 1){ // # of center is 2
            center = parent[center];
            ll tmp_hash = get_hash(center, -1);
            hash = hash<tmp_hash?hash:tmp_hash;
        }
        tree_hash.push_back(hash);
    }
    sort(tree_hash.begin(), tree_hash.end());
    int ans=1;
    for(int i=1; i<N; ++i) ans += (tree_hash[i-1]!=tree_hash[i])?1:0;
    printf("%d\n", ans);
}