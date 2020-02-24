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
i64 Read() { i64 x = 0; char c = getchar(); bool neg = false;while (c!='-' && (c < '0' || c > '9')) c=getchar(); if (c=='-') neg=true, c = getchar();while (c>='0' && c<='9') x = x*10+c-'0',c=getchar();if (neg) x = -x; return x;}
void Write(i64 x) {if (x < 0) {putchar('-'); Write(-x); return;};if (x > 9) Write(x/10);putchar(x % 10 + '0');}

const int maxn = 1e5 + 2;

int n,dem;
i64 P[maxn],Q[maxn];
int A[maxn],amax,amin;
vector<int> g[maxn];

i64 DFS(int);
void Down(int u,int s,int wmax,int wmin,i64 S) {
    P[s] = max(P[s],S + wmax - wmin);
    if (P[s] >= S + amax - amin) return;
    for (auto &v : g[u])
        Down(v,s,max(wmax,A[v]),min(wmin,A[v]),S - DFS(v) + Q[v]);
}

i64 DFS(int u) {
    if (P[u] != -1) return P[u];
    P[u] = 0;
    for (auto &v : g[u]) Q[u] += DFS(v);
    Down(u,u,A[u],A[u],Q[u]);
    return P[u];
}

void Solve() {
    memset(P,-1,sizeof P);
    amin = amax = A[1];
    rep(i,2,n) {
        amin = min(amin,A[i]);
        amax = max(amax,A[i]);
    }
    Write(DFS(1));
}

#define task "experience"
main() {
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    n = Read();
    rep(i,1,n) A[i] = Read();
    rep(i,2,n) {
        int u = Read(),v = Read();
        g[u].pb(v);
    }
    Solve();
}
//cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC <<" s.\n";
