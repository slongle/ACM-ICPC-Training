#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
const int MAXN=1e5+10;
const int MAXM=2e5+10;
const LL INF=1e15+7;
const LL mod=1e9+7;
 
int n,m,x[MAXN],y[MAXN];
 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	sort(x+1,x+n+1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int a;
		scanf("%d",&a);
		int pos=lower_bound(x+1,x+n+1,a)-x;
		if (pos==n+1) printf("Dr. Samer cannot take any offer :(.\n");
		else printf("%d\n",x[pos]);
	}
	return 0;	
}