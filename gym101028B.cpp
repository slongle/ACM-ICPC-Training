
 #include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> P;
typedef long long LL;
const int MAXN=110;
const int MAXM=317;
const int INF=0x3f3f3f3f;
const int xp[]={1,0,-1,0};
const int yp[]={0,1,0,-1};
const int mod=1e9+7;
 
int n,m,t;
char x[MAXN],y[MAXN];
 
int main(){
	scanf("%d",&t); getchar();	
	while(t--){
		scanf("%s %s",x+1,y+1);
		getchar();
		n=strlen(x+1); m=strlen(y+1);
		if (n!=m) {printf("No\n"); continue;}
		int tag=1;
		for(int i=1;i<=n;i++){
			if (x[i]==y[i]) continue;
			if ('A'<=x[i] && x[i]<='Z') x[i]=x[i]+32;
			if ('A'<=y[i] && y[i]<='Z') y[i]=y[i]+32;
			if (x[i]=='b') x[i]='p';
			if (x[i]=='i') x[i]='e';
			if (y[i]=='b') y[i]='p';
			if (y[i]=='i') y[i]='e';
			if (x[i]==y[i]) continue;
			tag=0; break;
		}
		if (tag==0) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}