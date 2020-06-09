#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
#define F first
#define S second
#define MP make_pair

vector<vector<int>> road_combs;

struct P{
    ll x, y;
};

void make_roads(int cur, int N, vector<int> v){
    if(cur>N){
        road_combs.push_back(v);
        return;
    }
    if(v[cur] > 0){ make_roads(cur+1, N, v); return; }
    else{
        make_roads(cur+1, N, v);
        for(int i=cur+1; i<=N; ++i){
            if(v[i]>0) continue;
            v[i] = cur; v[cur] = i;
            make_roads(cur+1, N, v);
            v[i] = -1; v[cur] = -1;
        }
    }
}

ll gcd(ll x, ll y){ return y?gcd(y,x%y):x; }
ll dist(P a, P b){ return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y); }

int do_simul(int from, int to, int start, vector<int> &tunnel, vector<P> &points){
    ll dx = points[to].x - points[from].x;
    ll dy = points[to].y - points[from].y;
    ll d = gcd(abs(dx), abs(dy)); dx /= d; dy /= d;
    int cur = start;
    int N = points.size() - 1;
    vector<int> chk(N+1, 0);
    int ret = 0;
    bool bef_tunnel = false;
    while(true){
        //if(from==2 && to==4 && start==1 && tunnel[1]==2 && tunnel[3]==6 && tunnel[5]==7) printf("%d,", cur);fflush(stdout);
        if(chk[cur] > 4) break;
        ++chk[cur];
        if(!bef_tunnel && tunnel[cur] == -1) break;
        if(!bef_tunnel && tunnel[cur] != -1){ cur = tunnel[cur]; bef_tunnel = true; continue; }
        int next = -1;
        bool found = false;
        bef_tunnel = false;
        for(int i=1; i<=N; ++i){
            if(cur==i) continue;
            ll d_x = points[i].x - points[cur].x;
            ll d_y = points[i].y - points[cur].y;
            ll dd = gcd(abs(d_x), abs(d_y));
            if(d_x/dd != dx || d_y/dd != dy) continue;
            if(next<0 || (dist(points[next], points[cur]) > dist(points[i], points[cur]))){ next = i; found = true; }
        }
        if(!found) break;
        cur = next;
    }
    for(int i=1; i<=N; ++i) ret += chk[i]?1:0;
    return ret;
}

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int N;
        scanf("%d", &N);
        road_combs.clear();
        vector<P> points; points.push_back({0,0});
        for(int i=0; i<N; ++i){
            ll x, y;
            scanf("%lld%lld", &x, &y);
            points.push_back({x,y});
        }
        vector<int> tmp(N+1, -1);
        make_roads(1, N, tmp);
        int ans = 1;
        for(int from = 1; from <= N; ++ from){
            for(int to = 1; to <= N; ++ to){
                if(from==to) continue;
                // from->to arrow
                for(int start=1; start <= N; ++start){
                    for(auto &comb : road_combs){
                        ans = max(ans, do_simul(from, to, start, comb, points));
                    }
                }
            }
        }
        printf("Case #%d: %d\n", tt, ans);
    }
}