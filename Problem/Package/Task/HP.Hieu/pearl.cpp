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

const int maxn = 1500;

bool spe[maxn];

int Sum(int x) {
    int ans = 0;
    while (x) {
        ans += (x % 10) * (x % 10);
        x /= 10;
    }
    return ans;
}

bool Specnum(int x) {
    map<int,int> pr;
    do {
        x = Sum(x);
        if (pr[x] == 1) break; else pr[x] = 1;
    } while (x != 1);
    if (x == 1) return false;
    return true;
}

int a[20];
i64 P[20][maxn][2];

void Setup() {
    rep(i,1,1458) spe[i] = Specnum(i);
}

i64 Calc(int i,int j,int ok) {
    if (i == 19) return spe[j];
    i64 &x = P[i][j][ok];
    if (x != -1) return x;
    x = 0;
    int r = a[i]; if (ok) r = 9;
    rep(c,0,r) {
        int nok = ok; if (c != a[i]) nok = 1;
        int nj = j + c*c;
        x += Calc(i+1,nj,nok);
    }
    return x;
}

i64 findans(i64 x) {
    if (x == 1e18) x--;
    per(i,18,1) a[i] = x % 10,x /= 10;
    memset(P,-1,sizeof P);
    return Calc(1,0,0);
}

void Solve() {
    i64 L,R; scanf("%I64d %I64d",&L,&R);
    printf("%I64d\n",findans(R) -  findans(L-1));
}

#define task "pearl"
main() {
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    Setup();
    int T; scanf("%d",&T);
    while (T--) Solve();
}
//cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC <<" s.\n";
