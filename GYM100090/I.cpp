#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const int xp[]={-1,-1,-1,0,0,1,1,1};
const int yp[]={-1,0,1,-1,1,-1,0,1};
const int MAXN=200010;
const int MAXM=2e5+10;
const int INF=1e9+7;
const LL mod=1e9+7;
 
struct Node{
    int pos,val;
    Node(int pos,int val):pos(pos),val(val) {}
    bool operator < (const Node& a) const{
        return val<a.val;
    }
};
 
int n,pos,q,len,ans[MAXN],x[MAXN][2];
priority_queue <Node> pq;
 
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x[i][0],&x[i][1]);
    }
    int tt=0;
    for(int i=1;i<=1e6+200000;i++){
        for(int j=tt+1;j<=n;j++)
            if (x[j][0]<=i) {pq.push(Node(j,x[j][1]-x[j][0])); tt=j;}
            else break;
        if (pq.empty()) continue;
        Node a=pq.top(); pq.pop();
        ans[a.pos]=i;
    }
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    printf("\n");
    return 0;
}