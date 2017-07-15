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
 
int n,m,t,q,x[1010];
 
int gcd(int a,int b){
	if (b==0) return a;
	else return gcd(b,a%b);
}
 
int main(){
	scanf("%d",&t);	
	while(t--){
		scanf("%d%d%d",&n,&m,&q);
		if (n<=m){
			if (n==q) printf("Yes\n");
			else printf("No\n");
			continue;
		}
		int a;
		a=(n-m)/(m-1);
		n-=m;
		n-=a*(m-1);
		if (a%2==1) n++;
		else n=m-n;
		if (n==q) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}