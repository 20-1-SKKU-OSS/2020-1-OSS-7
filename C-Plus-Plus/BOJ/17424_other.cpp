#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

struct Mat{
    ll cnt[4][4];
    Mat(int x){
        memset(cnt, 0, sizeof(cnt));
        if(x==0) cnt[0][0]=cnt[0][3]=cnt[1][2]=cnt[2][1]=cnt[3][0]=1;
        else if(x==1) cnt[0][2]=cnt[2][0]=1;
        else if(x==2) cnt[0][1]=cnt[1][0]=1;
        else if(x==3) cnt[0][0]=1;
        else cnt[0][0]=cnt[1][1]=cnt[2][2]=cnt[3][3]=1;
    }
};

//1-base
struct SegTree{
    typedef struct Mat T; // Change this if you need
    T id = T(-1); // identity element (sum:0, mul:1, ...etc)
    T initval = T(-1);

    int S;
    vector<T> tree;
    T combine(T a, T b){
        // Real value, parent <- combine(child1, child2)
        T ret = T(-1);
        for(int i=0; i<4; ++i){
            for(int j=0; j<4; ++j){
                ret.cnt[i][j] = 0;
                for(int k=0; k<4; ++k){
                    ret.cnt[i][j] += a.cnt[i][k]*b.cnt[k][j];
                }
                ret.cnt[i][j] %= MOD;
            }
        }
        return ret;
    }

    SegTree(int N){
        for(S=1;S<N;S<<=1);
        tree.resize(S*2, initval);
    }
    void set_value(int i, T val){ set_value(i, val, 1, 1, S); }
    void set_value(int i, T val, int idx, int nl, int nr){
        if(i<nl || nr<i) return;
        if(nl==i && nr==i){
            tree[idx] = val;
            return;
        }
        int mid = (nl + nr) / 2;
        set_value(i, val, idx*2, nl, mid);
        set_value(i, val, idx*2+1, mid+1, nr);
        tree[idx] = combine(tree[idx*2], tree[idx*2+1]);
    }
    T query(int l, int r){ return query(l, r, 1, 1, S); }
    T query(int l, int r, int idx, int nl, int nr){
        if(r<nl || nr<l) return id;
        if(l<=nl && nr<=r) return tree[idx];
        int mid = (nl + nr) / 2;
        return combine( query(l, r, idx*2, nl, mid) , query(l, r, idx*2+1, mid+1, nr) );
    }
};

int arr[100010];

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    SegTree ans(n);
    for(int i=1; i<=n; ++i) ans.set_value(i, Mat(0));
    for(;q--;){
        int type, r, c;
        scanf("%d%d%d", &type, &r, &c); --r;
        arr[c] ^= (1<<r);
        ans.set_value(c, arr[c]);
        printf("%lld\n", ans.query(1,n).cnt[0][0]);
    }
}