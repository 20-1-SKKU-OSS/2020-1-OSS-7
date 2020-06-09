#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char str[20];
bool used[30];
bool notzero[30];
char ans[11];
int cnt[30];

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int U;
        scanf("%d", &U);
        memset(used, 0, sizeof(used));
        memset(notzero, 0, sizeof(notzero));
        memset(cnt, 0, sizeof(cnt));
        for(int i=1; i<=10000; ++i){
            ll X;
            scanf("%lld%s", &X, str);
            int l = strlen(str);
            for(int j=0; j<l; ++j) used[str[j]-'A'] = true;
            notzero[str[0]-'A'] = true;
            ++cnt[str[0]-'A'];
        }
        for(int i=0; i<26; ++i)
            if(used[i] && !notzero[i]) ans[0] = i+'A';
        for(int i=1; i<10; ++i){
            int l, m = -1;
            for(int j=0; j<26; ++j){
                if(used[j]==false) continue;
                if(m < cnt[j]){ m = cnt[j]; l=j; }
            }
            ans[i] = l + 'A';
            cnt[l] = 0;
        }
        printf("Case #%d: %s\n", tt, ans);
    }
}