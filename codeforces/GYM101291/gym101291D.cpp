#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
const int MAXN=1e6+10;
const int MAXM=2e5+10;
const LL inf=100000;
const LL mod=11e9+7;

int x[MAXN],n,m,t;

int main(){
	memset(x,0,sizeof(x));
	scanf("%d%d%d",&n,&m,&t);
	int ans=0,sum=0;
	int a;
	for(int i=1;i<=m;i++){
		scanf("%d",&a);
		x[a]=1;
		if (a<=t)  sum++;
	}
	for(int i=1;i+t-1<=n;i++){
		if (sum>=2){
			sum-=x[i];
			sum+=x[i+t];
			continue;
		}
		ans+=2-sum;
		for(int j=i+t-1;j>=i;j--){
			if (sum>=2) break;
			if (x[j]==1) continue;
			else {x[j]=1; sum++;}
		}
		sum-=x[i];
		sum+=x[i+t];
	}
	cout<<ans<<endl;
	return 0;	
}