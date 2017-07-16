#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> P;
typedef long long LL;
const int MAXN=1e4+10;
const int MAXM=1e5;
const int INF=0x3f3f3f3f;
const int xp[]={1,0,-1,0};
const int yp[]={0,1,0,-1};
const int mod=1e9+7;
 
int n,m,t,num[30],len,edge[3*MAXM][3],dis[MAXN],vis[MAXN];
char x[MAXN][30];
 
int check(int a,int b){
	memset(num,0,sizeof(num));
	for(int i=1;i<=strlen(x[a]+1);i++){
		if ('A'<=x[a][i] && x[a][i]<='Z') x[a][i]+=32;
		num[x[a][i]-'a'+1]++;
	}
	int ans=0;
	for(int i=1;i<=strlen(x[b]+1);i++){
		if ('A'<=x[b][i] && x[b][i]<='Z') x[b][i]+=32;
		if (num[x[b][i]-'a'+1]>0) ans++,num[x[b][i]-'a'+1]=0;
	}
	return ans;
}
 
void link(int a,int b,int c){
	len++;
	edge[len][0]=b; edge[len][1]=c;
	if (edge[a][0]==0) edge[a][2]=len;
	else edge[edge[a][0]][2]=len;
	edge[a][0]=len;
} 
 
void SPFA(int s,int t){
	queue <int> q;
	for(int i=1;i<=n;i++){
		dis[i]=INF;
		vis[i]=0;
	}
	vis[s]=1; dis[s]=0; q.push(s);
	while(!q.empty()){
		int v=q.front(); q.pop(); vis[v]=0;
		for(int i=edge[v][2];i!=0;i=edge[i][2]){
			if (dis[edge[i][0]]>dis[v]+edge[i][1]){
				dis[edge[i][0]]=dis[v]+edge[i][1];
				if (vis[edge[i][0]]==0){
					vis[edge[i][0]]=1;
					q.push(edge[i][0]);
				}
			}
		}
	}
	printf("%d\n",dis[t]);
}
 
int main(){
	scanf("%d%d",&n,&m); len=n;
	for(int i=1;i<=n;i++) scanf("%s",x[i]+1);
	memset(edge,0,sizeof(edge));
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		int l=check(a,b);
		link(a,b,l);
		link(b,a,l);
	}
	int s,t;
	scanf("%d%d",&s,&t);
	SPFA(s,t);
	return 0;
}