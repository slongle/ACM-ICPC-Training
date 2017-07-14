#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
const int MAXN=2e5+10;
const int MAXM=2e5+10;
const LL inf=100000;
const LL mod=11e9+7;

struct Node{
	int a,b,c,d;
}x[MAXN];

bool cmp(Node p,Node q){
	int num=0;
	if (p.a>q.a) num++;
	if (p.b>q.b) num++;
	if (p.c>q.c) num++;
	return (num>=2);
}

int n,m;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&x[i].a,&x[i].b,&x[i].c);
		x[i].d=i;
	}
	sort(x+1,x+n+1,cmp);
	int pos=1,sum=0;
	for(int i=1;i<n;i++)
		if (cmp(x[n],x[i])) {printf("0\n"); return 0;}
	printf("1\n%d\n",x[n].d);
	return 0;	
}