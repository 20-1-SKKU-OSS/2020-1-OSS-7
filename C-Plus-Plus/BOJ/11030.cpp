#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll pow(ll x, ll y, ll MOD){
    ll ret=1;
    while(y){
        if(y&1){ ret *= x; ret %= MOD; }
        y>>=1; x = (x*x)%MOD;
    }
    return ret;
}

ll phi(ll N){
    if(N%2==0) N/=2;
    if(N%5==0) N=N*4/5;
    return N;
}

ll a_up_b(ll a, ll b){
    if(b==1) return a;
    ll p = a_up_b(a, b-1), ret=1;
    while(p--) ret*=a;
    return ret;
}

ll get_ans(ll a, ll b, ll MOD){
    if(MOD==1) return 1;
    if(b==1) return a%MOD;
    ll phi_mod = phi(MOD);
    ll p = get_ans(a, b-1, phi_mod);
    bool islarger;
    if(b-1>=5) islarger = true;
    else if(b-1>=3 && a>=3) islarger = true;
    else if(b-1==2 && a>=9) islarger = true;
    else islarger = a_up_b(a, b-1)>phi_mod;
    ll ret = islarger?pow(a, p+phi_mod, MOD):pow(a, a_up_b(a, b-1), MOD);

    return ret;
}

int main()
{
    ll a, b;
    scanf("%lld%lld", &a, &b);
    if(a==1){ printf("1\n"); return 0; }
    if(a==2){
        if(b==1) printf("2\n");
        else if(b==2) printf("4\n");
        else if(b==3) printf("16\n");
        else if(b==4) printf("65536\n");
        else printf("%08lld\n", get_ans(a, b, 10000000));
        return 0;
    }
    if(b==2){
        if(a<=8) printf("%lld\n", a_up_b(a,b));
        else printf("%08lld\n", get_ans(a, b, 100000000));
        return 0;
    }
    if(b==1){
        printf("%lld\n", a);
        return 0;
    }
    printf("%08lld\n", get_ans(a, b, 100000000));
}