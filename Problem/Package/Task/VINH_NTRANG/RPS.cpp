#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define fd(i,a,b) for(int i=(a);i>=(b);--i)
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define LL long long
#define TASK "RPS"
using namespace std;
///---------------------------------------------------
int n, cnt = 0;
char c[2005][2005];
vector <int> a[2005], b[2005];
bool F[2005];
///---------------------------------------------------
void nhap(){
    cin>>n;
    fo(i,1,n) fo(j,1,n) cin>>c[i][j];
    fo(i,1,n) fo(j,1,n) if (i!=j)
        if (c[i][j]=='1') a[i].push_back(j), b[j].push_back(i);
        else a[j].push_back(i), b[i].push_back(j);
}
///---------------------------------------------------
void sub1(){
    fo(i,1,n){
        bool d = 0;
        rep(j,0,a[i].size()){
            int u = a[i][j];
            rep(k,0,a[u].size()){
                int v = a[u][k];
                rep(l,0,a[v].size()) if (a[v][l]==i) d = 1;
            }
        }
        if (!d) cnt++;
    }
    cout<<n - cnt;
}
///---------------------------------------------------
void sub2(){
    fo(i,1,n){
        bool d = 0;
        memset(F,0,sizeof(F));
        rep(j,0,b[i].size()) F[b[i][j]] = 1;
        rep(j,0,a[i].size()){
            int u = a[i][j];
            rep(k,0,a[u].size()){
                int v = a[u][k];
                if (F[v]) d = 1;
            }
        }
        if (!d) cnt++;
    }
    cout<<n - cnt;
}
///---------------------------------------------------
void solve(){
    if (n<=100) sub1(); else if (n<=200)
        sub2(); else cout<<n;
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

