#include<bits/stdc++.h>
using namespace std;

bool chk[510][1010];
int back[510][1010];
int arr[1010];

int main()
{
    int N;
    scanf("%d", &N);
    for(int i=1; i<2*N; ++i){
        scanf("%d", &arr[i]);
    }
    chk[0][0] = true;
    for(int i=1; i<2*N; ++i){
        int x = arr[i];
        for(int j=N; j>=1; --j){
            for(int k=0; k<N; ++k){
                if(chk[j][k]) continue;
                if(!chk[j-1][(k-x+N)%N]) continue;
                back[j][k] = i;
                chk[j][k] = true;
            }
        }

        // for(int j=0; j<=N; ++j){
        //     for(int k=0; k<N; ++k) printf("%d ", back[j][k]);
        //     printf("\n");
        // }
        // printf("\n");
    }
    int p = 0;
    for(int i=N; i>=1; --i){
        printf("%d ", arr[back[i][p]]);
        p = (p - arr[back[i][p]] + N) % N;
    }
    printf("\n");
    return 0;
}