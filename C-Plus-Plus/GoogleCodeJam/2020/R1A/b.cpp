#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
bool runfull[100];

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        memset(runfull, 0, sizeof(runfull));
        ll n;
        scanf("%lld", &n);
        printf("Case #%d:\n", tt);
        if(n <= 30){
            for(int i=1; i<=n; ++i) printf("%d 1\n", i);
            continue;
        }
        n -= 30;
        for(int i=0; i<30; ++i){
            if(n & (1<<i)) runfull[i] = true;
        }
        int c = 30; bool isright = false;
        for(int i=0; i<30; ++i){
            if(!runfull[i]){
                --c;
                printf("%d %d\n", i+1, isright?(i+1):1);
                continue;
            }
            if(isright) for(int j=i+1; j>=1; --j) printf("%d %d\n", i+1, j);
            else for(int j=1; j<=i+1; ++j) printf("%d %d\n", i+1, j);
            isright = !isright;
        }
        int r = 31;
        while(c){ printf("%d %d\n", r, isright?r:1); ++r; --c; }
    }
}