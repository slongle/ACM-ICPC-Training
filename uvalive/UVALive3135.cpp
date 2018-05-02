#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int MAXN=1e5+10;
const int MAXM=3005;
const LL INF=1e15;

struct Item{
    int Qnum,Period,Time;
    bool operator < (const Item &a) const{
        return Time>a.Time || (Time==a.Time && Qnum>a.Qnum);
    }
};

int m;
char a[20];
priority_queue<Item> A;

int main(){
    while(scanf("%s",a),a[0]!='#'){
        Item c;
        scanf("%d%d",&c.Qnum,&c.Period);
        c.Time=c.Period;
        A.push(c);
    }
    scanf("%d",&m);
    while(m--){
        Item c=A.top();
        A.pop();
        printf("%d\n",c.Qnum);
        c.Time+=c.Period;
        A.push(c);
    }
    return 0;
}
