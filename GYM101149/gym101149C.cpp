#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
const int MAXN=1e6+10;
const int MAXM=2e5+10;
const LL inf=100000;
const LL mod=11e9+7;

int n,m,ans[MAXN];

int main(){
	scanf("%d",&n);
	for(int i=0;i<=n;i++) ans[i]=-1;
	for(int i=0;i<n;i++) ans[((LL)i*i)%n]=i;
	for(int i=0;i<n;i++) cout<<ans[i]<<' ';
	cout<<endl;
	return 0;	
}