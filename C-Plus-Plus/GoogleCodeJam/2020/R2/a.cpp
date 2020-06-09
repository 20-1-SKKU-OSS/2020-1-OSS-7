#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
#define F first
#define S second
#define MP make_pair

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        ll L, R; bool sw = false;
        scanf("%lld%lld", &L, &R);
        ll a = 0, l=0, mid, r=2000000000;
        if(L!=R){
            while(l<=r){
                mid = (l+r)/2;
                if((L>R?(L-R):(R-L)) >= ((mid*(mid+1))/2)){
                    a = mid;
                    l = mid+1;
                }
                else r = mid-1;
            }
            if(L>R) L -= a*(a+1)/2;
            else R -= a*(a+1)/2;
        }
        if(L<R){
            sw = true;
            L ^= R ^= L ^= R;
        }
        l = 0, r = 2000000000;
        ll k;
        while(l<=r){
            mid = (l+r)/2;
            if(L >= (a*mid+mid*mid) && R >= (a*mid + mid*(mid+1))){
                k = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        //printf("%lld %lld\n", a, k);
        L -= a*k + k*k;
        R -= a*k + k*k + k;
        ll ans = a+k+k;
        while(L >= ans+1){ ++ans; L -= ans; }
        printf("Case #%d: %lld %lld %lld\n", tt, ans, sw?R:L, sw?L:R);
    }
}