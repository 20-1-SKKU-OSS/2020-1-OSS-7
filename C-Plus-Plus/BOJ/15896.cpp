#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define M 32
#define MOD 1999

ll N;
ll A_[1000010], B_[1000010];

struct MPair{
    ll cnt, minv, maxv;
};
MPair A[M][2], B[M][2]; // A[k][b]: for A[i] which k-th bit is b, its min and max of A[i]&((1<<k)-1)

int main()
{
    scanf("%lld", &N);
    for(int k=0; k<M; ++k){
        for(int b=0; b<2; ++b){
            A[k][b].cnt  = B[k][b].cnt  = 0;
            A[k][b].minv = B[k][b].minv = (1LL<<k);
            A[k][b].maxv = B[k][b].maxv = -1;
        }
    }
    for(int i=1; i<=N; ++i){
        scanf("%lld", &A_[i]);
        for(int k=0; k<M; ++k){
            ll b = (A_[i]>>k)&1, u = A_[i]&((1LL<<k)-1);
            ++A[k][b].cnt;
            A[k][b].minv = min(A[k][b].minv, u);
            A[k][b].maxv = max(A[k][b].maxv, u);
        }
    }
    for(int i=1; i<=N; ++i){
        scanf("%lld", &B_[i]);
        for(int k=0; k<M; ++k){
            ll b = (B_[i]>>k)&1, u = B_[i]&((1LL<<k)-1);
            ++B[k][b].cnt;
            B[k][b].minv = min(B[k][b].minv, u);
            B[k][b].maxv = max(B[k][b].maxv, u);
        }
    }

    ll ans1 = 0, ans2 = 0;
    //&+
    for(int k=0; k<M; ++k){
        ans1 += ((1LL<<k)%MOD) * (A[k][1].cnt%MOD) * (B[k][1].cnt%MOD);
        ans1 %= MOD;
    }
    //+&
    for(int k=0; k<M; ++k){
        bool c1, c2, c3, c4;
        c1 = c2 = c3 = c4 = false;
        if(A[k][0].cnt==0 || B[k][0].cnt==0 || A[k][0].minv+B[k][0].minv>=(1LL<<k)) c1 = true;
        if(A[k][0].cnt==0 || B[k][1].cnt==0 || A[k][0].maxv+B[k][1].maxv< (1LL<<k)) c2 = true;
        if(A[k][1].cnt==0 || B[k][0].cnt==0 || A[k][1].maxv+B[k][0].maxv< (1LL<<k)) c3 = true;
        if(A[k][1].cnt==0 || B[k][1].cnt==0 || A[k][1].minv+B[k][1].minv>=(1LL<<k)) c4 = true;
        if(c1 && c2 && c3 && c4) ans2 |= (1LL<<k);
    }
    printf("%lld %lld\n", ans1, ans2);
}