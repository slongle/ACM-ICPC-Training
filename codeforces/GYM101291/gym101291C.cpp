#include <bits/stdc++.h>
using namespace std;

const int INF=0x3f3f3f3f;

char x[60][60],s[60];
int dp[60][60][60],n,m,xR,yR,xE,yE,len;

int check(int xx,int yy){
	if (xx>n || xx<1 || yy>m || yy<1 || x[xx][yy]=='#') return 0;
	else return 1;
}

void dfs(int xx,int yy,int num,int val){
	if (num>len) return;
	if (dp[xx][yy][num]<=val) return;
	dp[xx][yy][num]=val;
	if (s[num+1]=='U'){
		if (check(xx-1,yy)) dfs(xx-1,yy,num+1,val);
		else dfs(xx,yy,num+1,val);
	}
	else{
		if (check(xx-1,yy)) dfs(xx-1,yy,num,val+1);
	}
	if (s[num+1]=='D'){
		if (check(xx+1,yy)) dfs(xx+1,yy,num+1,val);
		else dfs(xx,yy,num+1,val);
	}
	else{
		if (check(xx+1,yy)) dfs(xx+1,yy,num,val+1);
	}
	if (s[num+1]=='L'){
		if (check(xx,yy-1)) dfs(xx,yy-1,num+1,val);
		else dfs(xx,yy,num+1,val);
	}
	else{
		if (check(xx,yy-1)) dfs(xx,yy-1,num,val+1);
	}
	if (s[num+1]=='R'){
		if (check(xx,yy+1)) dfs(xx,yy+1,num+1,val);
		else dfs(xx,yy,num+1,val);
	}
	else{
		if (check(xx,yy+1)) dfs(xx,yy+1,num,val+1);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	getchar();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			x[i][j]=getchar();
			if (x[i][j]=='R') {xR=i; yR=j;}
			if (x[i][j]=='E') {xE=i; yE=j;}
		}
		getchar();
	}
	len=0;
	while((s[++len]=getchar())!=EOF){
		if (s[len]=='\n') {len--; break;}
	}
	memset(dp,INF,sizeof(dp));
	dfs(xR,yR,0,0);
	int ans=INF;
	for(int i=0;i<=len;i++) ans=min(ans,dp[xE][yE][i]);
	printf("%d\n",ans);
	return 0;
}