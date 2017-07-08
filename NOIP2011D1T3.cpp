#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=200010;
const int MAXM=55;
const LL INF=1e15;
const LL mod=10007;

int n,m,x[10][10],y[10][10],ans[10][3],tag_halt,kind[15];

void check_g(){
    int tag,pos,pos2;
    for(int i=1;i<=5;i++){
        pos=-1;
        while(pos!=0){
            pos=0; pos2=0;
            for(int j=1;j<=7;j++){
                if (x[i][j]==0 && x[i][j-1]!=0) pos=j;
                if (pos!=0 && x[i][j]!=0) {pos2=j; break;}
            }
            if (pos2==0) break;
            for(int j=0;pos2+j<=7;j++)
                swap(x[i][pos+j],x[i][pos2+j]);
        }
    }
}

int check_clear(){
    memset(y,0,sizeof(y));
    for(int i=1;i<=5;i++)
        for(int j=1;j<=7;j++){
            if (y[i][j]==1 || x[i][j]==0) continue;
            int color=x[i][j],num=1;
            for(int k=1;k+j<=7;k++)
                if (x[i][k+j]==color) num++;
                else break;
            if (num>=3){ 
                for(int k=0;k<num;k++)
                    y[i][k+j]=1;
            }
            num=1;
            for(int k=1;k+i<=5;k++)
                if (x[k+i][j]==color) num++;
                else break;
            if (num>=3){
                for(int k=0;k<num;k++)
                    y[i+k][j]=1;
            }
        }
    int num=0;
    for(int i=1;i<=5;i++)
        for(int j=1;j<=7;j++)
            if (y[i][j]==1) x[i][j]=0,num++;
    return num;
}

int getsum(){
    int sum=0;
    for(int i=1;i<=5;i++)
        for(int j=1;j<=7;j++)
            if (x[i][j]!=0) sum++;
    return sum;
}

int getkind(){
    memset(kind,0,sizeof(kind));
    for(int i=1;i<=5;i++)
        for(int j=1;j<=7;j++)
            kind[x[i][j]]++;
    int a=0;
    for(int i=1;i<=10;i++)
        if (kind[i]!=0 && kind[i]<3) a=-1;
    return a;
}

void check(int a){
    if (getsum()==0) {m=a+1; tag_halt=1;}
}

void dfs(int a){
    if (a==0) {check(a); return;}
    if (getkind()==-1) return;
    check(a);
    if (tag_halt==1) return;
    int z[10][10];
    memcpy(z,x,sizeof(z));
    for(int i=1;i<=5;i++)   
        for(int j=1;j<=7;j++){
            if (x[i][j]==x[i+1][j] || x[i][j]==0) continue;
            if (i+1<=5){
                swap(x[i][j],x[i+1][j]);
                ans[a][0]=i-1; ans[a][1]=j-1; ans[a][2]=1;
                int tag=1;
                while(tag!=0){
                    check_g();
                    tag=check_clear();
                }        
                dfs(a-1);
                if (tag_halt==1) return;
                memcpy(x,z,sizeof(x));
            }
            if (i-1>=1 && x[i-1][j]==0){
                swap(x[i][j],x[i-1][j]);
                ans[a][0]=i-1; ans[a][1]=j-1; ans[a][2]=-1;
                int tag=1;
                while(tag!=0){
                    check_g();
                    tag=check_clear();
                }                        
                dfs(a-1);
                if (tag_halt==1) return;
                memcpy(x,z,sizeof(x));
            }
        }
}

int main(){
    tag_halt=0;
    scanf("%d",&n);
    for(int i=1;i<=5;i++){
        x[i][0]=-1;
        for(int j=1;j<=8;j++){
            scanf("%d",&x[i][j]);
            if (x[i][j]==0) break;
        }
    }
    dfs(n);
    if (tag_halt!=1) printf("-1\n");
    else{
        for(int i=n;i>=m;i--)
            printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
    }
    return 0;
}
