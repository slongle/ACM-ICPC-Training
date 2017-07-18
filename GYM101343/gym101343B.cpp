#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> P;
typedef long long LL;
const int MAXN=1e4+10;
const int MAXM=317;
const int INF=0x3f3f3f3f;
const int xp[]={1,0,-1,0};
const int yp[]={0,1,0,-1};
const int mod=1e9+7;
 
int n,m,t,g[MAXN],pos[15];
LL f[MAXN],sum[MAXN];
char x[MAXN];
 
int main(){
	scanf("%d",&n); getchar();
	scanf("%s",x+1); n=strlen(x+1);
	sum[0]=1; f[0]=1; g[0]=0;
	memset(pos,0,sizeof(pos));
	for(int i=1;i<=n;i++){
		int v=x[i]-'0';
		g[i]=max(g[i-1],pos[v]);
		if (g[i]-1==-1) f[i]=sum[i-1];
		else f[i]=(sum[i-1]-sum[g[i]-1]+mod)%mod;
		sum[i]=(sum[i-1]+f[i])%mod;
		pos[v]=i;
	}
	printf("%d\n",f[n]);
	return 0;
}