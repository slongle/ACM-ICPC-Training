#include <bits/stdc++.h>
using namespace std;

char x[5];
int hh,mm,a,b,c,d,ans;

int main(){
    scanf("%s",x);
    hh=(x[0]-'0')*10+(x[1]-'0');
    mm=(x[3]-'0')*10+(x[4]-'0'); 
    for(int i=0;hh+i<=23;i++){       
        d=((hh+i)%10)*10+(hh+i)/10;
        c=hh+i;
        if (d<60 && c*60+d>=hh*60+mm){
            ans=(c-hh)*60+d-mm;
            cout<<ans<<endl;
            return 0;            
        }
    }
    c=24; d=0;
    ans=(c-hh)*60+d-mm;
    cout<<ans<<endl;
    return 0;
}
