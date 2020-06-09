#include<bits/stdc++.h>
using namespace std;

int n;
char str[110];

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        scanf("%s", str);
        printf("Case #%d: ", tt);
        n = strlen(str);
        int d = 0;
        for(int i=0; i<n; ++i){
            int x = str[i]-'0';
            if(d<x) while(d<x){ printf("("); ++d; }
            else while(d>x){ printf(")"); --d; }
            printf("%c", str[i]);
        }
        while(d){ printf(")"); --d; }
        printf("\n");
    }
}