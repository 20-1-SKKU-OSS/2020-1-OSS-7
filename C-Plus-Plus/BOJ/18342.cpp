#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef priority_queue<double, vector<double>, greater<double>> min_heap;
const double MAX_X = 2000000.0;

#define pii pair<int,int>
#define F first
#define S second
#define MP make_pair

int N;
int chtid[10010];
vector<pii> lines;
queue<int> line_queue;

struct Line {
	mutable int k, m, idx;
    mutable double p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(double x) const { return p < x; }
};

struct DCHT : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const double inf = INFINITY;
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = ((double)(y->m - x->m))/((double)(x->k - y->k));
		return x->p >= y->p;
	}
	void add(int idx) {
        int k = lines[idx].F, m = lines[idx].S;
		auto z = insert({k, m, idx, 0.0}), y = z++, x = y;
		while (isect(y, z)){ line_queue.push(z->idx); z = erase(z); }
		if (x != begin() && isect(--x, y)){ line_queue.push(y->idx); isect(x, y = erase(y)); }
		while ((y = x) != begin() && (--x)->p >= y->p){
            line_queue.push(y->idx);
			isect(x, erase(y));
        }
	}
	void query(double x, min_heap &pq) {
        if(empty()) return;
		auto t = lower_bound(x), l=t, r=t;
        double tmp = t->k * x + t->m;
        if(pq.size()>=8 && tmp <= pq.top()) return;
        else{
            if(pq.size()>=8) pq.pop();
            pq.push(tmp);
        }
        for(int c=0; c<7 && l!=begin(); ++c){
            --l;
            tmp = l->k * x + l->m;
            if(pq.size()>=8 && tmp <= pq.top()) break;
            else{
                if(pq.size()>=8) pq.pop();
                pq.push(tmp);
            }
        }
        ++r;
        for(int c=0; c<7 && r!=end(); ++c){
            tmp = r->k * x + r->m;
            if(pq.size()>=8 && tmp <= pq.top()) break;
            else{
                if(pq.size()>=8) pq.pop();
                pq.push(tmp);
            }
            ++r;
        }
	}
}cht[8];

void cht_insert(int idx){ // insert in cht[?] y=ax+b
    int a = lines[idx].F, b = lines[idx].S;
    line_queue.push(idx);
    while(!line_queue.empty()){
        int X = line_queue.front();
        line_queue.pop();
        if(chtid[X]>=8) continue;
        cht[chtid[X]].add(X);
        ++chtid[X];
    }
}

double sum_of_top8(double X){
    min_heap pq;
    double ret = 0.0;
    for(int i=0; i<8; ++i){
        cht[i].query(X, pq);
    }
    while(!pq.empty()){ ret += pq.top(); pq.pop(); }
    return ret;
}

double get_answer(){
    double l=1.0/MAX_X, r=MAX_X, mid, ans;
    int bs_cnt = 0;
    while(bs_cnt < 60){
        mid = (l+r)/2;
        ++bs_cnt;
        if(sum_of_top8(mid) >= 0){
            ans = mid;
            l = mid;
        }
        else r = mid;
    }
    return ans;
}

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; ++i){
        int p, w;
        scanf("%d%d", &p, &w);
        lines.push_back(MP(-w, p));
    }
    for(int i=1; i<=N; ++i){
        cht_insert(i-1);
        if(i<8) continue;
        // printf("\nNow %d calculated\n", i);
        // for(int j=0; j<8; ++j){
        //     printf("%dth set\n", j);
        //     for(auto x : cht[j]){
        //         printf("%d ", x.idx);
        //     }
        //     printf("\n");
        // }
        printf("%.12lf\n", get_answer());
    }
}