#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> Interval;
typedef long long LL;
const int MAXN=500010;
const int MAXM=200010;
const LL INF=1e15;
const int mod=998244353;

int n,m,T,a,b;
LL prefix_sum[MAXN];

LL sum(int l,int r){
    return prefix_sum[r]-prefix_sum[l-1];
}

LL sum(Interval a){
    return sum(a.first,a.second);
}

Interval MMAX(Interval a,Interval b){
    LL v1=sum(a), v2=sum(b);
    if (v1!=v2) return v1>v2 ? a : b;
    return a<b ? a : b; 
}

struct Node{
    int pre;
    int suf;
    Interval sub;
};

struct IntervalTree{
    Node seg[4*MAXN];
    
    Node maintain(int l, int r, Node v3, Node v4){
        Interval v1,v2;
        Node v;
        
        v1=make_pair(l,v3.pre);
        v2=make_pair(l,v4.pre);
        v.pre=MMAX(v1,v2).second;
        
        v1=make_pair(v4.suf,r);
        v2=make_pair(v3.suf,r);
        v.suf=MMAX(v1,v2).first;
        
        v.sub = MMAX( v3.sub, v4.sub);
        v1 = make_pair( v3.suf, v4.pre );
        v.sub = MMAX( v.sub, v1);
        
        return v;
    }
    
    void build(int a,int l,int r){
        if (l==r){
            seg[a].pre = seg[a].suf = l;
            seg[a].sub = make_pair(l,r);
            return;
        }
        int mid=(l+r)/2;
        build(a*2,l,mid);
        build(a*2+1,mid+1,r);
        seg[a] = maintain(l,r,seg[a*2],seg[a*2+1]);
    }
    
    Node query(int a,int l,int r,int ql,int qr){        
        if (l==ql && qr==r) return seg[a];
        int mid=(l+r)/2;
        Node v1,v2;
        if (qr<=mid) return query(a*2,l,mid,ql,qr);
        if (ql>mid) return query(a*2+1,mid+1,r,ql,qr);
        if (ql<=mid && qr>mid){
            v1 = query(a*2,l,mid,ql,mid);
            v2 = query(a*2+1,mid+1,r,mid+1,qr);
            return maintain(ql,qr,v1,v2);
        }
    }
    
};

IntervalTree Tree;

int main(){
    T=0;
    while(scanf("%d%d",&n,&m)!=EOF){
        T++; printf("Case %d:\n",T);
        prefix_sum[0]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a);
            prefix_sum[i]=prefix_sum[i-1]+(LL)a;
        }
        Tree.build(1,1,n);
        for(int i=1;i<=m;i++){
            scanf("%d%d",&a,&b);
            Node p;
            p = Tree.query(1,1,n,a,b);
            printf("%d %d\n",p.sub.first,p.sub.second);
        }
    }
    return 0;
}
