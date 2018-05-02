#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> P;
typedef long long LL;
const int MAXN=110;
const int MAXM=317;
const int INF=0x3f3f3f3f;
const int xp[]={1,0,-1,0};
const int yp[]={0,1,0,-1};
const int mod=1e9+7;
 
int n,m,t;
char x[MAXN],y[MAXN];
 
int main(){
	scanf("%d",&t); getchar();	
	while(t--){
		scanf("%s",x+1); getchar();
		n=strlen(x+1);
		int num1=0,num2=0,num3=0;
		for(int i=1;i<=n;i++){
			if (('a'<=x[i] && x[i]<='z') || ('A'<=x[i] && x[i]<='Z')) num1++;
			if ('0'<=x[i] && x[i]<='9') num2++;
			if (x[i]=='@' || x[i]=='?' || x[i]=='!') num3++;
		}
		if (num1<4) {printf("The last character must be a letter.\n"); continue;}
		if (num2<4) {printf("The last character must be a digit.\n"); continue;}
		if (num3<2) {printf("The last character must be a symbol.\n"); continue;}
		printf("The last character can be any type.\n");
	}
	return 0;
}