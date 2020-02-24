#include <bits/stdc++.h>
using namespace std;
#define tag "DANCE"
void inp(int &number)
{
    bool negative = false;
    register int c;

    number = 0;
    c = getchar();
    if (c=='-')
    {
        negative = true;
        c = getchar();
    }
    while (c>47 && c<58)
        number = number*10+ (c-48),c=getchar();
    if (negative)
        number *= -1;
}
void out(int x)
{
	if (x>9) out(x/10);
	putchar(x%10 + 48);
}
///-------------------------------------------------
#define maxN 70007
#define maxL 30007
int n,m,l,W;
int a[11][maxN],p[11][maxL];
int main()
{
    freopen(tag".inp","r",stdin); freopen(tag".out","w",stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    inp(n); inp(l); inp(m); inp(W);
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            inp(a[i][j]);
    for (int i=1;i<=m;i++)
        for (int j=1;j<=l;j++)
            inp(p[i][j]);
    /// sol:
    int ans=0;
    long long sum;
    for (int col=1;col<=n-l+1;col++)
    {
        sum=0;
        for (int j=col;j<=col+l-1;j++)
            for(int i=1;i<=m;i++)
                sum+=((((long long)a[i][j])*p[i][j-col+1]));
        ans+=(sum>W);
    }
    out(ans);
    return 0;
}
