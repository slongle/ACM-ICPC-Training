#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
const int MAXN=60;
const int INF=0x3f3f3f3f;
const int xp[]={1,0,-1,0};
const int yp[]={0,1,0,-1};

int n,f[210][210][4],ans;
char x[210][210];

void dfs(int a,int b,int c,int d){
	int vis[4]={-1,-1,-1,-1};
	if (f[n][n][0]<=d) return;
	if (a<1 || a>n || b<1 || b>n || x[a][b]=='#') return;
	if (f[a][b][c]<=d) return;
	for(int i=0;i<=3;i++){
		int temp;
		if (i>=c) temp=d+i-c;
		else temp=d+i+4-c;
		if (f[a][b][i]>temp) vis[i]=1,f[a][b][i]=temp;
		
	}
	if (a==n && b==n && c==0) return;
	for(int i=0;i<=3;i++){
		if (vis[i]==-1) continue;
		dfs(a+xp[i],b+yp[i],i,f[a][b][i]+1);
	}
}

int main(){
	scanf("%d",&n);  getchar();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			x[i][j]=getchar();
		getchar();
	}
	memset(f,INF,sizeof(f));
	dfs(1,1,0,0);
	printf("%d\n",f[n][n][0]);
	return 0;
}
close