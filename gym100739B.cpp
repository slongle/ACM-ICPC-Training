#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long LL;
const int MAXN=1e5+10;
const int MAXM=317;
const int INF=0x3f3f3f3f;
const int xp[]={1,0,-1,0};
const int yp[]={0,1,0,-1};
const int mod=1e9+7;

int n,m,f[MAXM][MAXM],x[MAXN];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&x[i]);
	int t=sqrt(n);
	memset(f,0,sizeof(f));
	for(int i=1;i<=t;i++)
		for(int j=0;j<n;j++)
			f[i][j%i]+=x[j];
	for(int i=1;i<=m;i++){
		int a,b,ans=0;
		scanf("%d%d",&a,&b);
		if (b<=t) ans=f[b][a];
		else{
			for(int j=a;j<n;j+=b)
				ans+=x[j];
		}
		printf("%d\n",ans);
	}
	return 0;
}