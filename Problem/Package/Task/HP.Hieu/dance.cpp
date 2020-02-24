#include <bits/stdc++.h>

#define rep(i,a,b) for (int i = a,_b = b;i <= _b;++i)
#define per(i,a,b) for (int i = a,_b = b;i >= _b;--i)
#define fore(i,c) for (__typeof(c) i = c.begin();i!=c.end();i++)

#define i64 long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back

#define All(x) x.begin(),x.end()
#define rAll(x) x.rbegin(),x.rend()
#define SZ(x) (int) x.size()

using namespace std;

i64 Read() {i64 x = 0; char c = getchar(); bool neg = false;while (c!='-' && (c < '0' || c > '9')) c=getchar(); if (c=='-') neg=true, c = getchar();while (c>='0' && c<='9') x = x*10+c-'0',c=getchar();if (neg) x = -x; return x;}
void Write(i64 x) {if (x < 0) {putchar('-'); Write(-x); return;};if (x > 9) Write(x/10);putchar(x % 10 + '0');}

const int
        maxl = 30001,
        maxn = 70001;

int n,l,m,W;
int T[11][maxn];
int P[11][maxl];

bool Check(int c) {
    int val = 0;
    rep(i,1,m) rep(j,1,l) {
        val += P[i][j] * T[i][c+j-1];
        if (val > W) return true;
    }
    return false;
}

void Solve() {
    int ans = 0;
    rep(i,1,n-l+1) ans += Check(i);
    printf("%d",ans);
}

#define task "dance"
main() {
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    scanf("%d %d %d %d",&n,&l,&m,&W);
    rep(i,1,m) rep(j,1,n) scanf("%d",&T[i][j]);
    rep(i,1,m) rep(j,1,l) scanf("%d",&P[i][j]);
    Solve();
}
//cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC <<" s.\n";
