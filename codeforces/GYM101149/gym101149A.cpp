#include bitsstdc++.h
using namespace std;

typedef long long LL;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
const int MAXN=2e5+10;
const int MAXM=2e5+10;
const LL inf=100000;
const LL mod=11e9+7;

int n,m;

int main(){
	scanf(%d,&n);
	int ans=0,a;
	for(int i=1;i=n;i++){
		scanf(%d,&a);
		ans=max(ans,a);
	}
	coutansendl;
	return 0;	
}