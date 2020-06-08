#include<bits/stdc++.h>
using namespace std;
int n;
char str[5] = "MOLA";
char arr[510][510];

pair<int,int> dp[510][510];
bool chk[510][510];

pair<int,int> f(int r, int c){
    if(r==1 && c==1) return dp[1][1] = make_pair(0,arr[1][1]==str[0]?1:0);
    if(chk[r][c]) return dp[r][c];

    pair<int,int> ret1 = make_pair(0, 0);
    pair<int,int> ret2 = make_pair(0, 0);
    // (r-1, c)
    if(r>1){
        pair<int,int> tmp = f(r-1, c);
        ret1.first = tmp.first;
        if(arr[r][c] == str[tmp.second])
            ret1.second = tmp.second+1;
        else
            ret1.second = arr[r][c]==str[0]?1:0;
        
        if(ret1.second == 4){
            ++ret1.first;
            ret1.second = 0;
        }
    }
    // (r, c-1)
    if(c>1){
        pair<int,int> tmp = f(r, c-1);
        ret2.first = tmp.first;
        if(arr[r][c] == str[tmp.second])
            ret2.second = tmp.second+1;
        else
            ret2.second = arr[r][c]==str[0]?1:0;

        if(ret2.second == 4){
            ++ret2.first;
            ret2.second = 0;
        }
    }

    dp[r][c] = ret1>ret2?ret1:ret2;
    chk[r][c] = true;
    return dp[r][c];
}
int main()
{
    int i, j;
    scanf("%d", &n);
    for(int i=1; i<=n; ++i) scanf("%s", arr[i]+1);
    printf("%d\n", f(n, n).first);
}