#include<bits/stdc++.h>
using namespace std;

char str[1010];

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int X, Y;
        scanf("%d%d%s", &X, &Y, str);
        int l = strlen(str);
        int ans;
        for(ans=1; ans<=l; ++ans){
            if(str[ans-1]=='S') --Y;
            if(str[ans-1]=='N') ++Y;
            if(str[ans-1]=='E') ++X;
            if(str[ans-1]=='W') --X;
            if(abs(X) + abs(Y) <= ans) break;
        }
        if(ans>l) printf("Case #%d: IMPOSSIBLE\n", tt);
        else printf("Case #%d: %d\n", tt, ans);
    }
}