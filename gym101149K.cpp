#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
const int MAXN=2e5+10;
const int INF=0x3f3f3f3f;

int a,b,c,d;

int main(){
	scanf("%d%d%d%d",&a,&b,&c,&d);
	double ans=1.0*(a-c)*(a-c)+(b-d)*(b-d);
	ans*=0.916297857297023;
	printf("%0.15f",ans);
	return 0;
}