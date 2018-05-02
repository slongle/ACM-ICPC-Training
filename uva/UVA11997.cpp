#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int MAXN=800;
const int MAXM=3005;
const LL INF=1e15;

struct Item{
    int sum,pos;
    Item(int sum,int pos):sum(sum),pos(pos){}
    bool operator < (const Item &a) const{
        return sum > a.sum;
    }
};

int n,x[2][MAXN];
void merge(int *A,int *B,int *C){
    priority_queue <Item> pq;
    for(int i=1;i<=n;i++)
        pq.push(Item(A[i]+B[1],1));
    for(int i=1;i<=n;i++){
        Item a=pq.top(); pq.pop();
        C[i]=a.sum;
        if (a.pos+1>n) continue;
        a.sum=a.sum-B[a.pos]+B[a.pos+1];
        a.pos++;
        pq.push(a);
    }
}

int main(){
    while(scanf("%d",&n)!=EOF){
        memset(x[0],0,sizeof(x[0]));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                scanf("%d",&x[1][j]);
            sort(x[1]+1,x[1]+n+1);
            if (i==1) for(int k=1;k<=n;k++) x[0][k]=x[1][k];
            else merge(x[0],x[1],x[0]);
        }
        for(int i=1;i<=n;i++)
            if (i!=n) printf("%d ",x[0][i]);
            else printf("%d",x[0][i]);
        printf("\n");
    }
    return 0;
}
