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
 
int n,m,t,q;
char x[MAXN][MAXN];
 
int main(){
	scanf("%d",&t);	
	while(t--){
		scanf("%d%d%d",&n,&m,&q); 
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				x[i][j]='.';
		while(q--){
			int a,b,c,d; char e;	
			scanf("%d%d%d%d %c",&a,&b,&c,&d,&e); getchar();
			for(int i=a;i<=c;i++)
				for(int j=b;j<=d;j++)
					x[i][j]=e;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				printf("%c",x[i][j]);
			printf("\n");
		}
	}
	return 0;
}