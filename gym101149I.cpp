#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
const int MAXN=2e5+10;
const int MAXM=2e5+10;
const LL inf=100000;
const LL mod=11e9+7;

int n,m,len,edge[MAXN*3][2],a,b,vis[MAXN],num[MAXN],pos;

void link(int a,int b){
	len++; edge[len][0]=b;
	if (edge[a][0]==0) edge[a][1]=len;
	else edge[edge[a][0]][1]=len;
	edge[a][0]=len;
}

int main(){
	scanf("%d%d",&n,&m); 
	len=n; memset(edge,0,sizeof(edge));
	memset(num,0,sizeof(num));
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		num[a]++; num[b]++;
		link(a,b);
		link(b,a);
	}
	memset(vis,0,sizeof(vis));
	pos=1;
	for(int i=2;i<=n;i++)
		if (num[i]<num[pos]) pos=i;
	vis[pos]=1;
	for(int i=edge[pos][1];i!=0;i=edge[i][1])
		vis[edge[i][0]]=1;
	for(int i=1;i<=n;i++)
		printf("%d ",vis[i]^1);
	printf("\n");
    return 0;
}