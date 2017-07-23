 #include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
const int xp[]={-1,-1,-1,0,0,1,1,1};
const int yp[]={-1,0,1,-1,1,-1,0,1};
const int MAXN=200010;
const int MAXM=2e5+10;
const int INF=1e9+7;
const LL mod=1e9+7;
 
int n,x[MAXN];
set <int> S;
set <int> :: iterator it;
 
int main(){
    scanf("%d",&n);
    S.clear();
    int ans,a;
    LL sum=0;    
    scanf("%d",&a);
    S.insert(a); x[a]=0;
    for(int i=2;i<=n;i++){
        scanf("%d",&a);
        it=S.lower_bound(a);
        if (it==S.end()){
            it--;
            ans=x[*it]+1;
            it++;
        }
        if (it==S.begin()){
            ans=x[*it]+1;
        }
        if (it!=S.begin() && it!=S.end()){
            ans=x[*it]+1;
            it--;
            ans=max(ans,x[*it]+1);
        }
        S.insert(a);
        x[a]=ans;
        sum+=ans;
    }
    printf("%lld",sum);
    return 0;
}