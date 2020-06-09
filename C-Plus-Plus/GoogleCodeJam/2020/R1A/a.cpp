#include<bits/stdc++.h>
using namespace std;

string pre, post, mid;
char str[110];

int main()
{
    int tt, T;
    scanf("%d", &T);
    for(tt=1; tt<=T; ++tt){
        int n;
        scanf("%d", &n);
        pre = ""; post = ""; mid = "";
        int c;
        for(c=1; c<=n; ++c){
            scanf("%s", str);
            int l = strlen(str);
            int p=0, q=l-1;
            string P, Q;
            while(p<l && str[p]!='*') ++p;
            P = string(str, str+p);
            while(q>=0 && str[q]!='*') --q;
            Q = string(str+q+1, str+l);

            int prel = pre.length(), pl = P.length();
            if(prel <= pl && P.substr(0, prel) == pre) pre = P;
            else if(prel >= pl && pre.substr(0, pl) == P);
            else break;

            int postl = post.length(), ql = Q.length();
            if(postl <= ql && Q.substr(ql-postl, ql) == post) post = Q;
            else if(postl >= ql && post.substr(postl-ql, postl) == Q);
            else break;

            for(int i=p+1; i<q; ++i){
                if(str[i]!='*') mid += str[i];
            }
        }
        if(c<=n){
            ++c;
            while(c<=n){ scanf("%s", str); ++c; }
            printf("Case #%d: *\n", tt);
        }
        else printf("Case #%d: %s\n", tt, (pre+mid+post).c_str());
    }
}