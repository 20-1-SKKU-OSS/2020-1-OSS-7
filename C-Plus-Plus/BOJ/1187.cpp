#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll N, a[2048];
bool ans[2048];

struct A{
    ll val;
    int idx1, idx2;
};
A arr[2100][2100];

void back(int p, int idx){
    if(p==0){
        //printf("%d ", arr[p][idx].val);
        ans[idx] = true;
        return;
    }
    back(p-1, arr[p][idx].idx1);
    back(p-1, arr[p][idx].idx2);
}
int main()
{
    scanf("%lld", &N);
    for(int i=1; i<2*N; ++i){
        scanf("%lld", &a[i]);
        arr[0][i].val = a[i];
        arr[0][i].idx1 = arr[0][i].idx2 = -1;
    }
    ll tmp = 1, p = 1, l = 2*N-1;
    while(tmp<N){
        //arr[p][1~]
        ll t = 1, c = 0;
        for(ll i=2; i<=l-1; i+=2){
            //arr[p-1][t], arr[p-1][i], arr[p-1][i+1]
            ++c;
            if((arr[p-1][t].val + arr[p-1][i].val) % (1LL<<p) == 0){
                arr[p][c].val = arr[p-1][t].val + arr[p-1][i].val;
                arr[p][c].idx1 = t;
                arr[p][c].idx2 = i;
                t = i+1;
            }
            else if((arr[p-1][t].val + arr[p-1][i+1].val) % (1LL<<p) == 0){
                arr[p][c].val = arr[p-1][t].val + arr[p-1][i+1].val;
                arr[p][c].idx1 = t;
                arr[p][c].idx2 = i+1;
                t = i;
            }
            else if((arr[p-1][i].val + arr[p-1][i+1].val) % (1LL<<p) == 0){
                arr[p][c].val = arr[p-1][i].val + arr[p-1][i+1].val;
                arr[p][c].idx1 = i;
                arr[p][c].idx2 = i+1;
            }
        }
        l = c; ++p; tmp*=2;
    }
    back(p-1, 1);
    for(int i=1; i<=2*N-1; ++i){
        if(ans[i]) printf("%d ", a[i]);
    }
    printf("\n");

    // for(int i=0; i<=2; ++i){
    //     for(int j=1; j<=2*N-1; ++j){
    //         printf("%d %d %d\n", arr[i][j].val, arr[i][j].idx1, arr[i][j].idx2);
    //     }
    //     printf("\n");
    // }
}