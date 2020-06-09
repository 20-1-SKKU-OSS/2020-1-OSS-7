#include<bits/stdc++.h>
using namespace std;

struct A{
    int s, e, idx;
    char X;
};

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int n;
        vector<A> arr;
        scanf("%d", &n);
        for(int i=1; i<=n; ++i){
            int x, y;
            scanf("%d%d", &x, &y);
            arr.push_back({x,y,i,'\0'});
        }
        sort(arr.begin(), arr.end(), [&](A a, A b){ return a.s==b.s?a.e>b.e:a.s<b.s; });
        int C=0, J=0;
        bool sw = true;
        for(int i=0; i<n; ++i){
            if(max(C,J) <= arr[i].s){
                arr[i].X = C>J?'C':'J';
                if(C>J) C = arr[i].e;
                else J = arr[i].e;
            }
            else if(min(C,J) <= arr[i].s){
                arr[i].X = C>J?'J':'C';
                if(C>J) J = arr[i].e;
                else C = arr[i].e;
            }
            else{ sw=false; break; }
        }
        sort(arr.begin(), arr.end(), [&](A a, A b){ return a.idx < b.idx; });
        printf("Case #%d: ", tt);
        if(sw){
            for(auto x : arr) printf("%c", x.X);
            printf("\n");
        }
        else printf("IMPOSSIBLE\n");
    }
}