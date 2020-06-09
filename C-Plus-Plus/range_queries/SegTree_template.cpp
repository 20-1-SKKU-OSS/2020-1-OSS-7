#include<vector>
#include<iostream>
using namespace std;

//1-based Segment Tree with Lazy propagation.
template<typename T>
class SegTree{
public:
    // Edit these values if you need
    // In this example, T is integer.
    T id = 0; // identity element (sum:0, mul:1, ...etc)
    T initval = 0, unused = 0;

    int S;
    vector<T> tree;
    vector<T> lazy;
    T combine(T a, T b){
        // Real value, parent <- combine(child1, child2)
        // In this example, combine function returns the sum of two integers.
        return a + b;
    }
    T lazy_prop(T a, T b){
        // Lazy value, child <- lazy_prop(child, parent) & node <- lazy_prop(node, val)
        // In this example, lazy saves the value to be add to the range[left, right].
        return a + b;
    }
    void unlazy(int idx, int nl, int nr){
        // update Real value when its lazy is applied
        // In this example, tree[idx] should be save the sum of the values in range[left, right].
        tree[idx] += lazy[idx] * (nr-nl+1);
    }

    SegTree(int N){
        for(S=1;S<N;S<<=1);
        tree.resize(S*2, initval);
        lazy.resize(S*2, unused);
    }
    void propagate(int idx, int nl, int nr){
        if(lazy[idx] == unused) return;
        if(idx < S){
            lazy[idx*2]   = lazy_prop(lazy[idx*2], lazy[idx]);
            lazy[idx*2+1] = lazy_prop(lazy[idx*2+1], lazy[idx]);
        }
        unlazy(idx, nl, nr);
        lazy[idx] = unused;
    }
    void update(int l, int r, T val){ update(l, r, val, 1, 1, S); }
    void update(int l, int r, T val, int idx, int nl, int nr){
        propagate(idx, nl, nr);
        if(r<nl || nr<l) return;
        if(l<=nl && nr<=r){
            lazy[idx] = lazy_prop(lazy[idx], val);
            propagate(idx, nl, nr);
            return;
        }
        int mid = (nl + nr) / 2;
        update(l, r, val, idx*2, nl, mid);
        update(l, r, val, idx*2+1, mid+1, nr);
        tree[idx] = combine(tree[idx*2], tree[idx*2+1]);
    }
    void set_value(int i, T val){ set_value(i, val, 1, 1, S); }
    void set_value(int i, T val, int idx, int nl, int nr){
        propagate(idx, nl, nr);
        if(i<nl || nr<i) return;
        if(nl==i && nr==i){
            tree[idx] = val;
            lazy[idx] = unused;
            propagate(idx, nl, nr);
            return;
        }
        int mid = (nl + nr) / 2;
        set_value(i, val, idx*2, nl, mid);
        set_value(i, val, idx*2+1, mid+1, nr);
        tree[idx] = combine(tree[idx*2], tree[idx*2+1]);
    }
    T query(int l, int r){ return query(l, r, 1, 1, S); }
    T query(int l, int r, int idx, int nl, int nr){
        propagate(idx, nl, nr);
        if(r<nl || nr<l) return id;
        if(l<=nl && nr<=r) return tree[idx];
        int mid = (nl + nr) / 2;
        return combine( query(l, r, idx*2, nl, mid) , query(l, r, idx*2+1, mid+1, nr) );
    }
};

int main()
{
    int N;
    cout << "Input the number of data: ";
    cin >> N; // Number of datas
    SegTree<int> segtree(N);
    cout << "Input the " << N << " values" << endl;
    for(int i=1; i<=N; ++i){
        int x;
        cin >> x;
        segtree.set_value(i, x);
    }
    while(true){
        int mode;
        cout << "Input the mode (0:quit, 1:add value in range, 2:get sum of range): ";
        cin >> mode;
        if(mode == 0) break;
        if(mode == 1){
            int l, r, val;
            cout << "Input the left and right index (1~" << N << "): ";
            cin >> l >> r;
            cout << "Input the value that you want to add in range: ";
            cin >> val;
            segtree.update(l, r, val);
            cout << "Update finished\n" << endl;
        }
        else if(mode == 2){
            int l, r;
            cout << "Input the left and right index (1~" << N << "): ";
            cin >> l >> r;
            cout << "The sum of values in range[" << l << ", " << r << "]: " << segtree.query(l, r) << endl << endl;
        }
    }
}