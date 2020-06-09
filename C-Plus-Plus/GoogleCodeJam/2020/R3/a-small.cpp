#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
pii dp[70][70][150];
char a[70], b[70];
struct B{
    int bx, by, bz;
}back[70][70][150];

pii f(pii x){ return make_pair(x.first+x.second, abs(x.first-x.second)); }

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        scanf("%s%s", a+1, b+1);
        int la = strlen(a+1), lb = strlen(b+1);
        memset(dp, 0, sizeof(dp));
        memset(back, 0, sizeof(back));
        for(int i=0; i<=la; ++i){
            for(int j=0; j<=lb; ++j){
                dp[i][j][0] = make_pair(i, j);
            }
        }
        for(int i=0; i<=la; ++i){
            for(int j=0; j<=lb; ++j){
                for(int k=1; k<=la+lb; ++k){
                    dp[i][j][k] = {k,k};
                }
            }
        }
    }
}