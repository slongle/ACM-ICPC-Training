#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
const int MAXN=5e5+10;
const int INF=0x3f3f3f3f;

int n,m;
char x[MAXN];

int main(){
	int len=0,a=0,b=0,c=0;
	while(x[++len]=getchar()){
		if (x[len]=='\n') {len--; break;}
		if (x[len]=='(') a++;
		if (x[len]==')') b++;
		if (x[len]=='?') c++;
	}
	if ((a+b+c)%2!=0) {printf("Impossible"); return 0;}
	a=(b+c-a)/2; b=0; c=0;
	for(int i=1;i<=len;i++){
		if (x[i]=='?'){
			if (a>0) x[i]='(';
			else x[i]=')';
			a--;
		}
		if (x[i]=='(') b++;
		else c++;
		if (c>b) {printf("Impossible"); return 0;}
	}
	for(int i=1;i<=len;i++) printf("%c",x[i]);
	printf("\n");
	return 0;
}