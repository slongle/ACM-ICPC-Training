#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
const int MAXN=1e5+10;
const int MAXM=2e5+10;
const LL INF=1e15+7;
const LL mod=1e9+7;
 
int n,m,num[30];
char x[MAXN];
 
int main(){
	scanf("%s",x+1);
	n=strlen(x+1);
	memset(num,0,sizeof(num));
	for(int i=1;i<=n;i++) num[x[i]-'a'+1]++;
	int mm=0;
	for(int i=1;i<=26;i++) mm=max(mm,num[i]);
	LL sum=INF; int ans=2;
	for(int i=2;i<=max(2,mm+1);i++){
		LL sum2=0;
		for(int j=1;j<=26;j++) sum2+=(LL)(num[j]%i)*num[j];
		if (sum2<sum){ans=i; sum=sum2;}
	}
	printf("%d\n",ans);
	return 0;	
}