#include <bits/stdc++.h>
#define LL long long
using namespace std;

int a,b;

int main(){
    while(scanf("%d",&a)!=EOF){
        b=0;
        for(int i=1;i<=a;i++)
            b+=i;
        printf("%d\n\n",b);
    }
    return 0;
}