#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
const int MAXN=2e5+10;
const int MAXM=2e5+10;
const LL inf=100000;
const LL mod=11e9+7;

int n,m,x[MAXN];
queue <int> S;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	x[0]=0;
	LL ans=0;
	for(int i=1;i<=n;i++)
		ans+=max(0,x[i]-x[i-1]);
	cout<<ans<<endl;
	return 0;	
}