#include<bits/stdc++.h>
using namespace std;

int arr[110][110];
int cnt[110];

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int n;
        scanf("%d", &n);
        int k=0, r=0, c=0;
        for(int i=1; i<=n; ++i){
            memset(cnt, 0, sizeof(cnt));
            for(int j=1; j<=n; ++j){ scanf("%d", &arr[i][j]); ++cnt[arr[i][j]]; }
            k += arr[i][i];
            for(int j=1; j<=n; ++j){
                if(cnt[j]>1){ ++r; break; }
            }
        }
        for(int i=1; i<=n; ++i){
            memset(cnt, 0, sizeof(cnt));
            for(int j=1; j<=n; ++j) ++cnt[arr[j][i]];
            for(int j=1; j<=n; ++j){
                if(cnt[j]>1){ ++c; break; }
            }
        }
        printf("Case #%d: %d %d %d\n", tt, k, r, c);
    }
}