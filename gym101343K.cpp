#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const int xp[]={-1,-1,-1,0,0,1,1,1};
const int yp[]={-1,0,1,-1,1,-1,0,1};
const int MAXN=1e5+10;
const int MAXM=2e5+10;
const LL INF=1e15+7;
const LL mod=1e9+7;
 
int n,m,y[5][5],num[15],ans;
char x[5][5];
 
void check(){
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++){
			int tag=0;
			if (y[i][j]==9) continue;
			for(int k=0;k<=7;k++){
				int a=i+xp[k],b=j+yp[k];
				if (a<1 || a>3 || b<1 || b>3) continue;
				if ((y[a][b]-y[i][j])==1) {tag=1; break;}
			}
			if (tag==0) return;
		}
	ans++;
}
 
void dfs(int a,int b){
	if (b==4) {dfs(a+1,1); return;}
	if (a==4 && b==1) {check(); return;}
	if (y[a][b]==0){
		for(int i=1;i<=9;i++)
			if (num[i]==0){
				num[i]=1; y[a][b]=i;
				dfs(a,b+1);
				num[i]=0; y[a][b]=0;
			}
	}
	else dfs(a,b+1);
}
 
int main(){
	ans=0;
	scanf("%s",x[1]+1); getchar();
	scanf("%s",x[2]+1); getchar();
	scanf("%s",x[3]+1); getchar();
	memset(num,0,sizeof(num));
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++){
			y[i][j]=x[i][j]-'0';
			num[y[i][j]]++;
		}
	dfs(1,1);
	printf("%d\n",ans);
	return 0;	
}