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
		int a,b;
		scanf("%d",&n); scanf("%d",&a); x[1]=a;
		for(int i=2;i<=n;i++){
			scanf("%d",&b);
			x[i]=b;
			a=gcd(a,b);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			ans+=x[i]/a;
		printf("%d %d\n",a,ans);
	}
	return 0;
}