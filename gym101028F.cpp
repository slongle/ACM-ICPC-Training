#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> P;
typedef long long LL;
const int MAXN=1100;
const int MAXM=317;
const int INF=0x3f3f3f3f;
const int xp[]={1,0,-1,0};
const int yp[]={0,1,0,-1};
const int mod=1e9+7;
 
int n,m,t;
char x[MAXN],y[10],z[10];
 
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s %s",x+1,y+1);
		getchar();
		int ans=0;
		n=strlen(x+1);
		for(int i=1;i+3<=n;i++){
			int tag=1;
			for(int j=0;j<=3;j++)
				if (x[i+j]!=y[j+1]) {tag=0; break;}
			if (tag==1) {ans=1; break;}
		}
		if (ans==1) {printf("good\n"); continue;}
		z[1]=y[2]; z[2]=y[3]; z[3]=y[4];
		for(int i=1;i+2<=n;i++){
			int tag=1;
			for(int j=0;j<=2;j++)
				if (x[i+j]!=z[j+1]) {tag=0; break;}
			if (tag==1) {ans=1; break;}
		}
		if (ans==1) {printf("almost good\n"); continue;}
		z[1]=y[1]; z[2]=y[3]; z[3]=y[4];
		for(int i=1;i+2<=n;i++){
			int tag=1;
			for(int j=0;j<=2;j++)
				if (x[i+j]!=z[j+1]) {tag=0; break;}
			if (tag==1) {ans=1; break;}
		}
		if (ans==1) {printf("almost good\n"); continue;}
		z[1]=y[1]; z[2]=y[2]; z[3]=y[4];
				for(int i=1;i+2<=n;i++){
			int tag=1;
			for(int j=0;j<=2;j++)
				if (x[i+j]!=z[j+1]) {tag=0; break;}
			if (tag==1) {ans=1; break;}
		}
		if (ans==1) {printf("almost good\n"); continue;}
		z[1]=y[1]; z[2]=y[2]; z[3]=y[3];
				for(int i=1;i+2<=n;i++){
			int tag=1;
			for(int j=0;j<=2;j++)
				if (x[i+j]!=z[j+1]) {tag=0; break;}
			if (tag==1) {ans=1; break;}
		}
		if (ans==1) {printf("almost good\n"); continue;}
		printf("none\n");
	}
	return 0;
}