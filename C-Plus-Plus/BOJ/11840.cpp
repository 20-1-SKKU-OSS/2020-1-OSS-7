#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, X;

vector<ll> arr;

struct Trie{
    int c[2];
    int ridx;
};
Trie trie[8000010];
int S = 0;

void trie_insert(ll val, int idx){
    int cur = 0;
    for(int i=31; i>=0; --i){
        int x = (val>>i)&1;
        if(trie[cur].c[x] == 0){
            ++S; trie[cur].c[x] = S;
        }
        cur = trie[cur].c[x];
        trie[cur].ridx = max(trie[cur].ridx, idx);
    }
}

int main()
{
    scanf("%lld%lld", &N, &X); --X;
    arr.push_back(0); trie_insert(0, 0);
    for(int i=0; i<N; ++i){
        ll x;
        scanf("%lld", &x); x ^= arr[i];
        arr.push_back(x);
        trie_insert(x, i+1);
    }
    //for(int i=0; i<=S; ++i) printf("%d %d %d %d\n", i, trie[i].c[0], trie[i].c[1], trie[i].ridx);
    int ansi=0, ansk=0;
    for(int l=0; l<=N; ++l){
        int cur = 0;
        for(int i=31; i>=0; --i){
            int x = (X>>i)&1;
            int g = (arr[l]>>i)&1;
            g ^= x;
            if(x == 1){
                if(trie[cur].c[g] == 0) break;
                cur = trie[cur].c[g];
            }
            else{
                if(trie[cur].c[g^1] != 0){
                    int r = trie[trie[cur].c[g^1]].ridx;
                    if(ansk < r-l){
                        ansk = r-l; ansi = l+1;
                    }
                }
                if(trie[cur].c[g] == 0) break;
                cur = trie[cur].c[g];
            }
        }
    }
    printf("%d %d\n", ansi, ansk);
}