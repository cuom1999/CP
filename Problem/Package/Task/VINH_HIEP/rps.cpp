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
#define TASK "rps"
using   namespace   std;
const int maxn = 2005;
int n,ans,a[maxn][maxn];
char c;
vector <int> suf[maxn],pre[maxn];
///--------------------------
void    readf(){
    cin >> n;
    fo(i,1,n) fo(j,1,n){
        cin >> c;
        a[i][j] = (c == '1');
        if (i == j || a[i][j] == 0) continue;
        suf[i].push_back(j);
        pre[j].push_back(i);
    }
}
///--------------------------
void    solve(){
    ans = 0;
    fo(i,1,n){
        fore(u,suf[i]) fore(v,pre[i]) if (a[*u][*v]){
            ans++;
            goto nxt;
        }
        nxt : ;
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




