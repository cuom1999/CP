//    ^Bjerg^
#include <bits/stdc++.h>
#define maxn 70007
#define maxc 20
#define CLMS "DANCE"
#define ft first
#define sd second
#define PB push_back
#define MP make_pair
#define endl "\n"
using namespace std;
long a[maxc][maxn],p[maxc][maxn];
long long F[maxn];
long n,m,l,w;
long res=0;
void nhap()
{
    cin >> m >> l >> n >> w;
    for(long i=1;i<=n;++i)
    {
        for(long j=1;j<=m;++j) cin >> a[i][j];
    }
    for(long i=1;i<=n;++i)
    {
        for(long j=1;j<=l;++j) cin >> p[i][j];
    }
}
void sub1()
{
    for(long i=1;i<=n;++i)
    {
        for(long j=1;j<=m-l+1;++j)
        {
            for(long x=j;x<=j+l-1;++x)
            {
                F[j]+=1ll*a[i][x]*p[i][x-j+1];
            }
        }
    }
    long long res=0;
    for(long j=1;j<=m-l+1;++j)
    {
        if(F[j]>w) res++;
    }
    cout << res;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(CLMS".inp","r",stdin);
    freopen(CLMS".out","w",stdout);
    nhap();
    sub1();
    return 0;
}
