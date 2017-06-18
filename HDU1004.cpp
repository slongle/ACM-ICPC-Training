#include <bits/stdc++.h>
#include <string>
using namespace std;

string x[1005],z;
int n,y[1005],pos,tag;

int main(){
    while(scanf("%d",&n),n!=0){
        memset(y,0,sizeof(y));
        for(int i=1;i<=n;i++){
            cin>>z;
            //scanf("\n&s",&z);
            tag=0;
            for(int j=1;j<=y[0];j++)
                if (x[j]==z) 
                {tag=1; y[j]++; break;}
            if (tag==0) {y[++y[0]]=1; x[y[0]]=z;}
        }
        pos=1;
        for(int i=2;i<=y[0];i++)
            if (y[i]>y[pos]) pos=i;
        //printf("%s\n",x[pos]);
        cout<<x[pos]<<endl;
        
    }
    return 0;
}
