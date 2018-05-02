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
 
int n,m,t,x[100010],y[100010];
 
int check(int a){
	memset(y,0,sizeof(y));
	int num=0;
	for(int i=1;i<=n;i++){
		if (y[i]==1) continue;
		for(int j=i;j<=n;j++)
			if (x[j]<=x[i]+a-1) y[j]=1;
			else break;
		num++;
	}
	if (num<=m) return 1;
	else return 0;
}
 
int main(){
	scanf("%d",&t);	
	while(t--){
		int mm=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d",&x[i]),mm=max(mm,x[i]);
		sort(x+1,x+n+1);
		int l=1,r=mm,mid,ans;
		while(l<=r){
			mid=(l+r)/2;
			if (check(mid)==1) ans=mid,r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}