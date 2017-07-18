#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
const int MAXN=2e5+10;
const int MAXM=2e5+10;
const LL inf=100000;
const LL mod=11e9+7;

int n,m,len,edge[MAXN*3][2],T1,T2,a,b,vis[MAXN],z[MAXN],x[MAXN],y[MAXN],pp[MAXN][2];
queue <int> S;

void link(int a,int b){
	len++; edge[len][0]=b;
	if (edge[a][0]==0) edge[a][1]=len;
	else edge[edge[a][0]][1]=len;
	edge[a][0]=len;
}

void SPFA(int a,int *dis){
	for(int i=1;i<=n;i++){
		dis[i]=2*MAXN;
		vis[i]=0;
	}
	dis[a]=0; S.push(a); vis[a]=1;
	while(!S.empty()){
		int v=S.front(); S.pop(); vis[v]=0;
		for(int i=edge[v][1];i!=0;i=edge[i][1]){
			if (dis[edge[i][0]]<=dis[v]+1) continue;
			dis[edge[i][0]]=dis[v]+1;
			if (vis[edge[i][0]]==0) {vis[edge[i][0]]=1; S.push(edge[i][0]);}
		}
	}
}

int main(){
	scanf("%d%d%d%d",&n,&m,&T1,&T2);
	n++; T1++; T2++; len=n; memset(edge,0,sizeof(edge));
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		a++; b++;
		pp[i][0]=a; pp[i][1]=b;
		link(a,b);
	}
	SPFA(1,x);
	len=n; memset(edge,0,sizeof(edge));
	for(int i=1;i<=m;i++)
		link(pp[i][1],pp[i][0]);
	SPFA(T1,y);
	SPFA(T2,z);
	int ans=10*MAXN;
	for(int i=1;i<=n;i++)
		ans=min(ans,x[i]+y[i]+z[i]);
	cout<<ans<<endl;
	return 0;	
}