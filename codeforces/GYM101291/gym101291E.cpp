#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const int MAXN=500;
const int MAXM=110;
const LL INF=1e17;
const LL mod=10007;
 
struct abcd{
    int a,b;
    bool operator < (const abcd &aa) const{
        return a > aa.a;
    }
};
 
int n,m,x[MAXN];
LL now,sum;
priority_queue <abcd> pq;
 
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&x[i]);
        abcd item;
        item.a=x[i]; item.b=i;
        if (i<=m) pq.push(item);
    }
    now=0; sum=0; int pos=m+1;
    for(int i=1;i<=n;i++){
        now+=pq.top().a;
        pq.pop();
        sum+=now;
        abcd item;
        if (pos<=n){
            item.a=x[pos]; item.b=pos;
            pq.push(item);
            pos++;
        }
    }
    printf("%lld\n",sum);
    return 0;
}