#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> P;
typedef long long LL;
const int MAXN=1100;
const int MAXM=317;
const int INF=0x3f3f3f3f;
const int xp[]={1,0,-1,0};
const int yp[]={0,1,0,-1};
const int mod=1e9+7;
 
int n,m,t;
char x[MAXN],y[10],z[10];
 
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			int a;
			scanf("%d",&a);
			m-=a;
		}
		if (m==1500) printf("Correct\n");
		else printf("Bug\n");
	}
	return 0;
}