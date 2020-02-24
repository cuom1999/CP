#include <bits/stdc++.h>
using namespace std;
#define tag "PEARL"
#define maxn 10000007
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
int n;
bool t[maxn]={0,1,0,0,0,0,0,0,0,0,1};
int c[maxn];
int sum2(int x)
{
    int ss=0;
    while(x>0)
    {
        ss+=(x%10)*(x%10);
        x/=10;
    }
    return ss;
}
bool yes(int x)
{
    while(1)
    {
        if (x/10==0) return t[x%10];
        x=sum2(x);
    }
    return 0;
}
int main()
{
    freopen(tag".inp","r",stdin); freopen(tag".out","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i=11;i<100;i++) t[i]=yes(i);
    for (int i=100;i<maxn;i++) t[i]=t[sum2(i)];
    c[0]=0;
    for (int i=1;i<maxn;i++) c[i]=c[i-1]+t[i];
    int t,l,r;
    inp(t);
    while(t--)
    {
        inp(l); inp(r);
        out((r-l+1)-(c[r]-c[l-1])),putchar('\n');
    }
    return 0;
}
