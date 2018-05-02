#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
const int MAXN=2e5+10;
const int INF=0x3f3f3f3f;

struct Node{
	int v,w,p;
	bool operator < (const Node &a) const{
		return v>a.v;
	}
}x[MAXN],y[MAXN];

int n,m,ans[MAXN];
set <P> s;
set <P> :: iterator it;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {scanf("%d%d",&x[i].v,&x[i].w); x[i].p=i;}
	sort(x+1,x+n+1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++) {scanf("%d%d",&y[i].v,&y[i].w); y[i].p=i;}
	sort(y+1,y+m+1);
	int pos=1;
	s.clear();
	for(int i=1;i<=n;i++){
		for(int j=pos;j<=m+1;j++)
			if (y[j].v>=x[i].v && j<=m) s.insert(P(y[j].w,y[j].p));
			else {pos=j; break;}
		/*while(pos<=m && y[pos].v>=x[i].v){
			s.insert(P(y[pos].w,y[pos].p));
			pos++;
		}*/
		it=s.lower_bound(P(x[i].w,-1));
		if (it==s.end()) {printf("-1\n"); return 0;}
		ans[x[i].p]=(*it).second;
		s.erase(it);
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}