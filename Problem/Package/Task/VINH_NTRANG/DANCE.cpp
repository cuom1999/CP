#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define fd(i,a,b) for(int i=(a);i>=(b);--i)
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define LL long long
#define TASK "DANCE"
using namespace std;
///---------------------------------------------------
LL n, l, m, w, t[15][70005], p[15][30005], res = 0;
///---------------------------------------------------
void nhap(){
    cin>>n>>l>>m>>w;
    fo(i,1,m) fo(j,1,n) cin>>t[i][j];
    fo(i,1,m) fo(j,1,l) cin>>p[i][j];
}
///---------------------------------------------------
void solve(){
    fo(d,1,n-l+1){
         LL tmp = 0;
         fo(i,1,m) fo(j,d,d+l-1) tmp+=t[i][j]*p[i][j-d+1];
         if (tmp>w) res++;
    }
    cout<<res;
}
///---------------------------------------------------
int main(){
    #ifndef ONLINE_JUDGE
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    nhap();
    solve();
}
