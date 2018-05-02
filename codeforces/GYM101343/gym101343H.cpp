#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
const int MAXN=2e5+10;
const int MAXM=2e5+10;
const int INF=1e9+7;
const LL mod=1e9+7;
 
int n,m,pos[55],ans[MAXN],x[MAXN];
 
int main(){
	scanf("%d",&n);
	memset(pos,0,sizeof(pos));
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	for(int i=n;i>=1;i--){
		int temp=INF;
		for(int j=x[i]+1;j<=50;j++)
			if (pos[j]!=0) temp=min(temp,pos[j]);
		if (temp==INF) ans[i]=-1;
		else ans[i]=x[temp];
		pos[x[i]]=i;
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;	
}