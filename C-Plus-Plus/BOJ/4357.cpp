#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
ll B, N, P;

#define MP make_pair
#define F first
#define S second

ll modpow(ll a, ll b, ll p){
    ll ret = 1;
    while(b){
        if(b&1) ret = (ret*a)%p;
        a = (a*a)%p; b>>=1;
    }
    return ret;
}

int main()
{
    while(scanf("%lld%lld%lld", &P, &B, &N)>0){
        ll D = (ll)sqrt(P);
        ll bd = modpow(B, D, P);
        ll b_ = modpow(B, P-2, P);
        vector<pll> X, Y;
        X.push_back(MP(1,0));
        for(ll i=1; i<=(P/D); ++i){
            ll val = (X[i-1].F * bd) % P;
            X.push_back(MP(val, D*i));
        }
        Y.push_back(MP(N,0));
        for(ll i=1; i<D; ++i){
            ll val = (Y[i-1].F * b_) % P;
            Y.push_back(MP(val, i));
        }
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());
        int x=0, y=0;
        ll ans = P;
        while(x < X.size() && y < Y.size()){
            if(X[x].F == Y[y].F) ans = min(ans, X[x].S + Y[y].S);
            if(X[x].F > Y[y].F) ++y;
            else ++x;
        }
        if(ans == P) printf("no solution\n");
        else printf("%lld\n", ans);
    }
}