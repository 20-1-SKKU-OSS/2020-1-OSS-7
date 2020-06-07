#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

struct A{
    ll cnt[4][4];
    A(int l, int r){
        if(l<0 || r<0){
            cnt[0][0] = -1;
            return;
        }
        for(int i=0; i<4; ++i){
            for(int j=0; j<4; ++j){
                // actually, arr filled l,r , but we want to fill like i,j was already filled
                if((l&(~i)) || (r&(~j))){ cnt[i][j] = 0; continue; }
                if(i==0 && j==0) cnt[i][j] = 2;
                else if(i==1 && j==1) cnt[i][j] = 1;
                else if(i==2 && j==2) cnt[i][j] = 1;
                else if(i==3 && j==0) cnt[i][j] = 1;
                else if(i==0 && j==3) cnt[i][j] = 1;
                else if(i==3 && j==3) cnt[i][j] = 1;
                else cnt[i][j] = 0;
            }
        }
    }
};

const A ZERO(3,3);

int arr[200010];

//1-base
struct SegTree{
    typedef A T; // Change this if you need
    T id = T(-1,-1); // identity element (sum:0, mul:1, ...etc)
    T initval = T(0,0);

    int S;
    vector<T> tree;
    T combine(T a, T b, int mid){
        // Real value, parent <- combine(child1, child2)
        if(a.cnt[0][0]<0) return b;
        if(b.cnt[0][0]<0) return a;
        T ret(0,0);
        mid = mid*2;
        int car = arr[mid], cbl = arr[mid+1];
        for(int al=0; al<4; ++al){
            for(int br=0; br<4; ++br){
                // ret.cnt[al][br] = ( a.cnt[al][car] * b.cnt[cbl][br] ) % MOD;
                // if(car&1 == 0 && cbl&1 == 0) ret.cnt[al][br] = ( ret.cnt[al][br] + ( a.cnt[al][car|1] * b.cnt[cbl|1][br] ) ) % MOD;
                // if(car&2 == 0 && cbl&2 == 0) ret.cnt[al][br] = ( ret.cnt[al][br] + ( a.cnt[al][car|2] * b.cnt[cbl|2][br] ) ) % MOD;
                // if(car&3 == 0 && cbl&3 == 0) ret.cnt[al][br] = ( ret.cnt[al][br] + ( a.cnt[al][car|3] * b.cnt[cbl|3][br] ) ) % MOD;
                ret.cnt[al][br] = 0;
                for(int f=0; f<4; ++f){
                    if((car&f) == 0 && (cbl&f) == 0) ret.cnt[al][br] += ( a.cnt[al][car|f] * b.cnt[cbl|f][br] ) % MOD;
                    ret.cnt[al][br] %= MOD;
                }
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
        tree[idx] = combine(tree[idx*2], tree[idx*2+1], mid);
    }
    T query(int l, int r){ return query(l, r, 1, 1, S); }
    T query(int l, int r, int idx, int nl, int nr){
        if(r<nl || nr<l) return id;
        if(l<=nl && nr<=r) return tree[idx];
        int mid = (nl + nr) / 2;
        return combine( query(l, r, idx*2, nl, mid) , query(l, r, idx*2+1, mid+1, nr) , mid );
    }
};

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i=n+1; i<200000; ++i) arr[i] = 3;
    SegTree ans((n+1)/2);
    for(int i=1; i<=(n+1)/2; ++i) ans.set_value(i,A(arr[i*2-1],arr[i*2]));
    for(;q--;){
        int type, r, c;
        scanf("%d%d%d", &type, &r, &c); --r;
        arr[c] ^= (1<<r);
        c = (c+1)/2;
        ans.set_value(c, A(arr[c*2-1],arr[c*2]));
        printf("%lld\n", ans.query(1, (n+1)/2).cnt[arr[1]][arr[(n+1)/2*2]]);
    }
}