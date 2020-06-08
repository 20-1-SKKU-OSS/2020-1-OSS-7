#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define F first
#define S second
#define ll long long
#define pll pair<ll,ll>

int main()
{
    int T;
    scanf("%d", &T);
    for(int tt=1; tt<=T; ++tt){
        int n;
        scanf("%d", &n);
        pll a(1,0), b(0,1), t;
        pll ans(n/2, n-n/2);
        while(true){
            t.F = a.F + b.F;
            t.S = a.S + b.S;
            pll tmp(b.S*n, -b.F*n);
            if(t.F*tmp.F + t.S*tmp.S == -n){
                tmp.F *= -1;
                tmp.S *= -1;
            }
            //printf("t: %lld %lld\n", t.F, t.S);
            //printf("before: %lld %lld\n", tmp.F, tmp.S);
            if(tmp.S < 0){
                ll diff = tmp.F - tmp.S;
                ll X = (diff+t.F+t.S-1)/(t.F+t.S);
                tmp.S += t.F*X;
                tmp.F -= t.S*X;
            }
            else{
                ll diff = tmp.S - tmp.F;
                ll X = diff/(t.F+t.S);
                tmp.S -= t.F*X;
                tmp.F += t.S*X;
            }
            //printf("after : %lld %lld\n\n", tmp.F, tmp.S);
            if(tmp.F <= 0 || tmp.S <= 0) break;
            if(ans.S>tmp.S || (ans.S==tmp.S && ans.F>tmp.F))
                ans = tmp;
            a = b; b = t;
        }
        printf("%lld %lld\n", ans.F, ans.S);
    }
    return 0;
}