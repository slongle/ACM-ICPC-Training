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
 
int n,m,t;
char x[MAXN],y[MAXN];
 
int main(){
	scanf("%d",&t);	
	while(t--){
		scanf("%d",&n); getchar();
		scanf("%s",x+1); getchar();
		scanf("%s",y+1); getchar();
		LL ans=1;
		int tag=1;
		for(int i=n;i>=1;i--){
			if (y[i]=='1' && x[i]=='1') ans=(ans*2)%mod;
			if (y[i]=='0' && x[i]=='1') {tag=0; break;}
		}
		if (tag==0) printf("IMPOSSIBLE\n");
		else printf("%I64d\n",ans);
	}
	return 0;
}