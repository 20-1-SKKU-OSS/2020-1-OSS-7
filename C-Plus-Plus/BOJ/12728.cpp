#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int ans_6[7] = {0,0,27,143,751,935,607};

// pow(x, y, mod) = x**y % mod
ll pow(ll x, ll y, ll mod){
    ll ret=1;
    while(y){
        if(y&1) ret = (x*ret)%mod;
        x = (x*x)%mod; y>>=1;
    }
    return ret;
}

ll comb(ll n, ll r, ll mod){
    vector<ll> tmp;
    ll ret = 1;
    for(ll i=0; i<r; ++i) tmp.push_back(n-i);
    for(ll i=r; i>=2; --i){
        for(auto &x : tmp){
            if(x%i) continue;
            x /= i;
            break;
        }
    }
    for(auto x : tmp){
        ret = (ret*x)%mod;
    }
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int tt=1; tt<=T; ++tt){
        ll N;
        scanf("%lld", &N);
        if(N<=6){
            printf("Case #%d: %03d\n", tt, ans_6[N]);
            continue;
        }

        ll ans = 0, nC2 = 0, nC4 = 0;
        nC2 = comb(N, 2, 1000); nC4 = comb(N, 4, 1000);
        ans =  2*pow(3,N,1000);
        ans += 10*pow(3,N-2,1000)*nC2;
        ans += 50*pow(3,N-4,1000)*nC4;
        ans -= 250*(1+nC2+nC4)*pow(3,N,1000);
        ans -= 1;
        ans %= 1000;
        if(ans<0) ans += 1000;
        printf("Case #%d: %03lld\n", tt, ans);
    }
}