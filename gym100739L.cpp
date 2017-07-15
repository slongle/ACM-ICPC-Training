#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long LL;
const int MAXN=60;
const int INF=0x3f3f3f3f;
const int xp[]={1,0,-1,0};
const int yp[]={0,1,0,-1};
const int mod=1e9+7;

LL power(LL a,LL b){
	LL c=1;
	while(b!=0){
		if (b%2==1) c=(c*a)%mod;
		a=(a*a)%mod;
		b/=2;
	}
	return c;
}

int main(){
	LL a,b;
	scanf("%lld",&a);
	b=power(2,a);
	printf("%lld\n",b);
	return 0;
}