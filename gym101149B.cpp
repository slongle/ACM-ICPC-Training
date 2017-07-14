#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
const int MAXN=2e5+10;
const int MAXM=1000;
const LL inf=100000;
const LL mod=11e9+7;

struct Node{
	int a,b;
	bool operator < (const Node &node) const{
		return b>node.b || (b==node.b && a<node.a);
	}
}x[MAXN];

int n;

void dfs(int a,int b,int pos){
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i].a,&x[i].b);
		x[i].b=x[i].a-x[i].b;
	}
	sort(x+1,x+n+1);
	LL ans=0,now=0; 
	for(int i=1;i<=n;i++){
		if (x[i].a>=now) x[i].a-=now,now=0;
		else now-=x[i].a,x[i].a=0;
		ans+=x[i].a;
		now+=x[i].b;
	}
	cout<<ans<<endl;
    return 0;
}