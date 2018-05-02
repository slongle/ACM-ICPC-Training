#include <bits/stdc++.h>
using namespace std;

int x[10],y[10],a,b;

int main(){
	for(int i=1;i<=6;i++) scanf("%d",&x[i]);
	for(int i=1;i<=6;i++) scanf("%d",&y[i]);
	a=0; b=0;
	for(int i=1;i<=6;i++)
		for(int j=1;j<=6;j++){
			if (x[i]>y[j]) a++;
			if (x[i]<y[j]) b++;
		}
	double ans=(1.0*a)/(a+b);
	printf("%.5f\n",ans);
	return 0;
}