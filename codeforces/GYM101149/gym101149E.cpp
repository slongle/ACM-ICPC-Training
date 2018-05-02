#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
const int MAXN=2e5+10;
const int MAXM=2e5+10;
const LL inf=100000;
const LL mod=11e9+7;

int n,m,x[MAXN][2];

int main(){
	scanf("%d",&n);
	int mm=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i][0],&x[i][1]);
		mm=max(mm,x[i][0]);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		if (x[i][0]<=mm && mm<=x[i][1]) ans++;
	cout<<ans<<endl;
	return 0;	
}