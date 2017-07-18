#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
const int MAXN=2e5+10;
const int MAXM=2e5+10;
const LL inf=100000;
const LL mod=11e9+7;

int n,mm;
vector <int> vis;
map<int ,vector<int> > edge;

int check(int a,int b){
	printf("? %d %d\n",a,b);
	fflush(stdout);
	char c=getchar(); getchar();
	if (c=='<'){
		if (!edge.count(b)) edge[b]=vector<int>();
		edge[b].push_back(a);
		mm=b;
		return a;
	}
	else{
		if (!edge.count(a)) edge[a]=vector<int>();
		edge[a].push_back(b);
		mm=a;
		return b;
	}
}

int main(){
	scanf("%d",&n); getchar();
	for(int i=0;i<=n;i++) 
		if (i==0) vis.push_back(0);
		else vis.push_back(1);
	int sum=n; 
	while(sum>1){
		int ff=1;
		for(int i=1;i<=n;i++){
			if (i<ff || vis[i]==0) continue;
			for(int j=i+1;j<=n;j++){
				if (vis[j]==0) continue;
				int p=check(i,j); 
				vis[p]=0;
				sum--;
				ff=j+1;
				break;
			}
		}
	}
	sum=edge[mm].size(); int tt=mm;
	if (sum==1) {printf("! %d",edge[tt][0]); return 0;}
	for(int i=1;i<=n;i++) vis[i]=1;
	while(sum>1){
		int ff=0;
		for(int i=0;i<edge[tt].size();i++){
			if (i<ff || vis[edge[tt][i]]==0) continue;
			for(int j=i+1;j<edge[tt].size();j++){
				if (vis[edge[tt][j]]==0) continue;
				int p=check(edge[tt][i],edge[tt][j]);
				vis[p]=0;
				sum--;
				ff=j+1;
				break;
			}
		}
	}
	printf("! %d",mm);
	return 0;	
}