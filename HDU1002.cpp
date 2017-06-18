#include <bits/stdc++.h> 
using namespace std;

const int MAXN=1005;

int a[MAXN],b[MAXN],c[MAXN],t,temp1,temp2,len,p,pos;
char d[MAXN],e[MAXN],f[MAXN],g[MAXN];

int main(){
    scanf("%d",&t); p=0;
    while(t--){
        memset(d,'\0',sizeof(d));
        memset(e,'\0',sizeof(e));
        memset(f,'\0',sizeof(f));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        p++;
        printf("Case %d:\n",p);
        scanf("\n%s",g+1);
        printf("%s + ",g+1);
        len=strlen(g+1);
        for(int i=1;i<=len;i++) if (g[i]!='0'){pos=i; break;}
        for(int i=pos;i<=len;i++) d[i-pos+1]=g[i];
        scanf("%s",g+1);
        printf("%s = ",g+1);
        len=strlen(g+1);
        for(int i=1;i<=len;i++) if (g[i]!='0'){pos=i; break;}
        for(int i=pos;i<=len;i++) e[i-pos+1]=g[i];
        len=strlen(d+1);
        for(int i=1;i<=len;i++) a[len-i+1]=d[i]-'1'+1;
        len=strlen(e+1);
        for(int i=1;i<=len;i++) b[len-i+1]=e[i]-'1'+1;
        len=max(strlen(d+1),strlen(e+1));
        temp1=0; temp2=0;
        for(int i=1;i<=len;i++){
            temp1=temp2+a[i]+b[i];
            c[i]=temp1%10;
            temp2=temp1/10;
        }
        if (temp2!=0) c[++len]=temp2;
        for(int i=1;i<=len;i++) f[len-i+1]='1'+c[i]-1;
        printf("%s\n",f+1);
        if (t!=0) printf("\n");
    }
    return 0;
}