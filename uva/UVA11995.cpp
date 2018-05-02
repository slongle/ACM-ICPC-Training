#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int MAXN=1005;
const int MAXM=3005;
const LL INF=1e15;

int n,x[MAXN][2],tag1,tag2,tag3;
string ans;
stack <int> A;
queue <int> B;
priority_queue <int> C;

int check_stack(){
    while(!A.empty()) A.pop();
    for(int i=1;i<=n;i++){
        if (x[i][0]==1) A.push(x[i][1]);
        else {
            if (A.empty()) return 0;
            if (A.top()!=x[i][1]) return 0;
            else A.pop();
        }
    }
    return 1;
}

int check_queue(){
    while(!B.empty()) B.pop();
    for(int i=1;i<=n;i++){
        if (x[i][0]==1) B.push(x[i][1]);
        else{
            if (B.empty()) return 0;
            if (B.front()!=x[i][1]) return 0;
            else B.pop();
        }
    }
    return 1;
}

int check_priority_queue(){
    while (!C.empty()) C.pop();
    for(int i=1;i<=n;i++){
        if (x[i][0]==1) C.push(x[i][1]);
        else{
            if (C.empty()) return 0;
            if (C.top()!=x[i][1]) return 0;
            else C.pop();
        }
    }
    return 1;
}

int main(){
    while(scanf("%d",&n)!=EOF){
        int num=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&x[i][0],&x[i][1]);
            if (x[i][0]==2) num++;
        }
        tag1=check_stack();
        tag2=check_queue();
        tag3=check_priority_queue();
        if (tag1==1 && tag2==0 && tag3==0) ans="stack";
        if (tag1==0 && tag2==1 && tag3==0) ans="queue";
        if (tag1==0 && tag2==0 && tag3==1) ans="priority queue";
        if (tag1+tag2+tag3==0) ans="impossible";
        if (tag1+tag2+tag3>=2) ans="not sure";
        if (num==0) ans="not sure";
        cout<<ans<<endl;
    }
    return 0;
}
