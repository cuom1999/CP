#include    <bits/stdc++.h>
#define stat akjcjalsjcjalscj
#define hash ajkscjlsjclajsc
#define next ackjalscjaowjico
#define prev ajcsoua0wucckjsl
#define y1 alkscj9u20cjeijc
#define left lajcljascjljl
#define right aucouasocjolkjl
#define y0 u9cqu3jioajc
#define	time	jsfdasd
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define fd(i,a,b) for(int i=(a);i>=(b);--i)
#define rep(i,a,b)  for(int i=(a);i<(b);++i)
#define fore(i,a)  for(__typeof((a).begin()) i=(a).begin();i!=(a).end();++i)
#define __unique(V) (V).resize(unique((V).begin(),(V).end())-(V).begin())
#define cntbit(X)   __builtin_popcount((X))
#define bit(S,i) (((S)>>(i))&1)
#define PI	acos(-1)
#define fi  first
#define se  second
#define LL  long long
#define ii  pair<int,int>
#define iii pair<int,ii>
#define TASK "dance"
using   namespace   std;
int n,m,l,W,a[15][30005];
int ans,b[15][70005];
///--------------------------
void    readf(){
    cin >> n >> l >> m >> W;
    fo(i,1,m) fo(j,1,n) cin >> a[i][j];
    fo(i,1,m) fo(j,1,l) cin >> b[i][j];
}
///--------------------------
void    solve(){
    int ans = 0;
    fo(k,1,n - l + 1){
        int sum = 0;
        fo(i,1,m) fo(j,1,l)
            sum += a[i][k + j - 1] * b[i][j];
        ans += (sum > W);
    }
    cout << ans << '\n';
}
///--------------------------
int     main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen(TASK".inp", "r", stdin);
    	freopen(TASK".out", "w", stdout);
    #endif //ONLINE_JUDGE
    readf();
    solve();
}



