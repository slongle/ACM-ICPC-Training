#include <bits/stdc++.h>
using namespace std;

int a,b,n,x[2][2];

void mult(int x[2][2],int y[2][2],int z[2][2]){
    for(int i=0;i<=1;i++)
        for(int j=0;j<=1;j++){
            z[i][j]=0;
            for(int k=0;k<=1;k++){
                z[i][j]+=(x[i][k]*y[k][j])%7;
                z[i][j]%=7;
            }
        }
}

void power(int x[2][2],int n){
    int y[2][2],z[2][2];
    for(int i=0;i<=1;i++)
        for(int j=0;j<=1;j++)
            y[i][j]=x[i][j];
    for(int i=0;i<=1;i++)
        for(int j=0;j<=1;j++)
            if (i==j) x[i][j]=1;
            else x[i][j]=0;
    for(;n>0;n/=2){
        if ((n%2)==1) {mult(x,y,z); memcpy(x,z,sizeof(z));}
        mult(y,y,z); memcpy(y,z,sizeof(z));
    }
}

int main(){
    while(scanf("%d%d%d",&a,&b,&n),a!=0 || b!=0 || n!=0){
        x[0][0]=a; x[0][1]=b;
        x[1][0]=1; x[1][1]=0;
        power(x,n-2);
        printf("%d\n",(x[0][0]+x[0][1])%7);
    }
    return 0;
}
