#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define fd(i,a,b) for(int i=(a);i>=(b);--i)
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define LL long long
#define TASK "PEARL"
using namespace std;
///---------------------------------------------------
LL t, l, r;
///---------------------------------------------------
void nhap(){
    cin>>t;
}
///---------------------------------------------------
bool check(LL x){
    while (x>44){
        LL tmp = 0;
        while (x>0) tmp +=(x%10)*(x%10), x/=10;
        x = tmp;
    }
    if (x==44||x==32||x==23||x==31||x==13||x==1||x==10) return 1;
    return 0;
}
///---------------------------------------------------
void solve(){
    cin>>l>>r;
    LL res = 0;
    fo(i,l,r) if (!check(i)) res++;
    cout<<res<<'\n';
}
///---------------------------------------------------
int main(){
    #ifndef ONLINE_JUDGE
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    nhap();
    while (t--) solve();
}

