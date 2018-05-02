#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int MAXN=105;
const int MAXM=1005;
const int INF=0x3f3f3f3f;

int n,a,c,l,v0,v1,last,ans1,ans2;
double ans;

int f(int a,int b,int c){
    //double d=((b-a-1)*180-((b-a-1)*(n-2)*180)/n)/2;
    int d=((b-a-1)*180);
    //double e=((c-b-1)*180-((c-b-1)*(n-2)*180)/n)/2;
    int e=((c-b-1)*180);
    int f=((n-2)*180)-d-e;
    return f;
}

int main(){
    scanf("%d%d",&n,&a);
    ans=360*n;
    for(int i=2;i<=n-1;i++){
        int l,r,lmid,rmid;
        l=i+1; r=n;
        while(l<=r){
            lmid = l + (r - l)/3;  
            rmid = r - (r - l)/3;  
            int ansa=f(1,i,lmid),ansb=f(1,i,rmid);
            if (abs(ansa-a*n)<abs(ansb-a*n)) r=rmid-1;
            else l=lmid+1;
            if (abs(ansa-a*n)<ans) ans=abs(ansa-a*n),ans1=i,ans2=lmid;
            if (abs(ansb-a*n)<ans) ans=abs(ansb-a*n),ans1=i,ans2=rmid;
        }
    }
    printf("%d %d %d\n",1,ans1,ans2);
    return 0;
}
