#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> P;
typedef long long LL;
const int MAXN=110;
const int MAXM=317;
const int INF=0x3f3f3f3f;
const int xp[]={1,0,-1,0};
const int yp[]={0,1,0,-1};
const int mod=1000000007;
 
int n,m,t,a,b,q,x[100010];
 
int main(){
	scanf("%d",&t);	
	while(t--){
		scanf("%d%d%d",&n,&a,&b);
		memset(x,INF,sizeof(x));
		for(int i=1;i<=n;i++){
			int c=(i*a)%n;
			c++;
			if (x[c]==INF) x[c]=i;
			else break;
		}
		int ans=INF;
		for(int i=1;i<=n;i++){
			int c=(i*b)%n;
			c++;
			if (x[c]!=INF) ans=min(ans,max(i,x[c]));
		}
		printf("%d\n",ans);	
	}
	return 0;
}