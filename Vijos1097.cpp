#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef long long LL;
const int MAXN=1e5+10;
const int MAXM=317;
const int INF=0x3f3f3f3f;
const int xp[]={1,0,-1,0};
const int yp[]={0,1,0,-1};
const int mod=1e9+7;

struct Node{
	int v;
	bool operator < (const Node & a) const{
		return v > a.v;
	}
};

int n,ans;
priority_queue <Node> pq;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		Node a;
		scanf("%d",&a.v);
		pq.push(a);
	}
	ans=0;
	while(pq.size()>1){
		Node a,b;
		a=pq.top(); pq.pop();
		b=pq.top(); pq.pop();
		ans+=a.v+b.v;
		a.v+=b.v;
		pq.push(a);
	}
	printf("%d\n",ans);
	return 0;
}