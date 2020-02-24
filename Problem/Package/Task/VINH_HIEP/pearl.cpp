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
#define TASK "pearl"
using   namespace   std;
const int maxn = 2000;
int t,ok[maxn],a[25],b[25];
LL  F[25][maxn][2][2],A,B;
///--------------------------
bool     test(int X){
    if (ok[X] != -1) return ok[X];
    if (X == 4) return (ok[X] = 1);
    if (X == 1) return (ok[X] = 0);
    int sum = 0;
    while (X > 0) {
        sum += (X % 10) * (X % 10);
        X /= 10;
    }
    return (ok[X] = test(sum));
}
///--------------------------
LL  f(int i,int sum,bool oka,bool okb){
    LL &rs = F[i][sum][oka][okb];
    if (rs != -1) return rs;
    if (i > 19) return (rs = test(sum));
    rs = 0;
    for(int j = (1 - oka) * a[i]; j <= max(b[i],okb * 9); ++j)
        rs += f(i + 1,sum + j * j, oka | (j > a[i]), okb | (j < b[i]));
    return rs;
}
///--------------------------
void    solve(){
    memset(ok,-1,sizeof(ok));
    cin >> t;
    fo(tt,1,t){
        cin >> A >> B;
        fd(i,19,1) a[i] = (A % 10), A/= 10;
        fd(i,19,1) b[i] = (B % 10), B/= 10;
        memset(F,-1,sizeof(F));
        cout << f(1,0,0,0) << '\n';
    }
}
///--------------------------
int     main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    	freopen(TASK".inp", "r", stdin);
    	freopen(TASK".out", "w", stdout);
    #endif //ONLINE_JUDGE
    solve();
}




