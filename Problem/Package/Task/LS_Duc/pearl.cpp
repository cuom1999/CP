#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll res=0;
bool ok[1500];
ll dp[20][1500][2];
bool done[20][1500][2];
int dig[20],cnt;
inline void solve(int x){
    int hihi=x;
    int duc=0;
    while(1){
        ++duc;
        if(duc==100) return ;
        int y=0;
        while(x>0){
            y+=(x%10)*(x%10);
            x/=10;
        }
        if(y==1){
            ok[hihi]=1;
            return;
        }
        x=y;
    }
}
inline ll F(int pos,int sum,bool over){
    if(pos==0){
        return ok[sum];
    }
    if(done[pos][sum][over]) return dp[pos][sum][over];
    done[pos][sum][over]=1;
    int lim=over?dig[pos]:9;
    for(int i=0;i<=lim;i++){
        ll add=F(pos-1,sum+i*i,over&&(i==lim));
        dp[pos][sum][over]+=add;
    }
    return dp[pos][sum][over];
}
inline ll cal(ll x){
    memset(dp,0,sizeof(dp));
    memset(dig,0,sizeof(dig));
    memset(done,0,sizeof(done));
    cnt=0;
    while(x>0){
        dig[++cnt]=x%10;
        x/=10;
    }
    ll ans=0;
    return F(cnt,0,1);
}
int main(){
    freopen("pearl.inp","r",stdin);
    freopen("pearl.out","w",stdout);
    for(int i=1;i<=1499;i++){
        solve(i);
    }
    int test;
    cin>>test;
    while(test--){
        ll L,R;
        cin>>L>>R;
        ll ans=R-L+1;
        if(L==1){
            cout<<ans-(cal(R))<<'\n';
        }
        else{
            cout<<ans-(cal(R)-cal(L-1))<<'\n';
        }
    }
}
