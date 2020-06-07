#include<bits/stdc++.h>
using namespace std;

int n;

char w1[30][30];
char w2[30][30];
int lowest_w2[30][200];
int ans = 999999;
bool chk[30];

void DFS(int node, int s_w1, int s_w2){
    for(int i=0; i<=s_w1; ++i){
        if(s_w2 >= lowest_w2[node][i]) return;
    }
    lowest_w2[node][s_w1] = s_w2;
    if(node == 1){
        ans = min(ans, s_w1*s_w2);
        return;
    }
    for(int next=0; next<n; ++next){
        if(w1[node][next]=='.') continue;
        if(chk[next]) continue;
        chk[next] = true;
        DFS(next, s_w1 + (w1[node][next]-'0'), s_w2 + (w2[node][next]-'0'));
        chk[next] = false;
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; ++i) scanf("%s", w1[i]);
    for(int i=0; i<n; ++i) scanf("%s", w2[i]);
    for(int i=0; i<n; ++i){
        for(int j=0; j<200; ++j)
            lowest_w2[i][j] = 200;
    }
    chk[0] = true;
    DFS(0, 0, 0);
    printf("%d\n", ans==999999?-1:ans);
}