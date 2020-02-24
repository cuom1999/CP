#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(),x.end()
#define rep(i,x) for(ll _x=x,i=0;i<_x;++i)
#define finc(i,a,b) for(ll _b=b,i=a;i<=_b;++i)
#define fdec(i,a,b) for(ll _b=b,i=a;i>=_b;--i)
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr)
ll calc(ll x){
    ll ans=0;
    while (x){
        ans+=(x%10)*(x%10);
        x/=10;
    }
    return ans;
}
ll F[1501];
void dfs(ll u){
    F[u]=0;
    ll v=calc(u);
    if (F[v]==-1) dfs(v);
    F[u]=F[v];
}
void init(){
    finc(i,0,1500) F[i]=-1; F[1]=1;
    finc(i,0,1500) if (F[i]==-1) dfs(i);
}
ll A[19],P[19][1501][2];
ll calc(ll i,ll S,ll ok){
    if (i==19) return 1-F[S];
    ll &rr=P[i][S][ok];
    if (rr!=-1) return rr;
    rr=0;
    ll t=A[i]; if (ok) t=9;
    finc(x,0,t){
        ll nextok=ok; if (x!=A[i]) nextok=1;
        ll nextS=S+x*x;
        rr+=calc(i+1,nextS,nextok);
    }
    return rr;
}
ll findres(ll x){
    if (x==1e18) --x;
    fdec(i,18,1) A[i]=x%10,x/=10;
    memset(P,255,sizeof(P));
    return calc(1,0,0);
}
void solve(){
    ll L,R; cin >> L >> R;
    cout << findres(R)-findres(L-1) << '\n';
}
int main(){
    fast_io;
    freopen("pearl.inp","r",stdin);
    freopen("pearl.out","w",stdout);
    init();
    ll T; cin >> T;
    while (T--) solve();
    return 0;
}





