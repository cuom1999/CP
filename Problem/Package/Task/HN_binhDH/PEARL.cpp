//    ^Bjerg^
#include <bits/stdc++.h>
#define maxn 2005
#define CLMS "PEARL"
#define ft first
#define sd second
#define PB push_back
#define MP make_pair
#define endl "\n"
using namespace std;
bool av[1505];
vector < long > v;
long n,a[maxn];
long long F1[20][maxn],F2[20][maxn];
long get(long x)
{
    long res=0;
    while(x)
    {
        res+=(x%10)*(x%10);
        x/=10;
    }
    return res;
}
bool dfs(long x)
{
    if(x==1) return true;
    if(av[x]==true) return false;
    av[x]=true;
    return dfs(get(x));
}
void tao()
{
    for(long i=1;i<=1500;++i)
    {
        memset(av,0,sizeof(av));
        if(dfs(i)==true)
        {
            v.PB(i);
        }
    }
    memset(av,0,sizeof(av));
    for(auto x:v)
    {
        av[x]=true;
    }
}
long long lam(long long x)
{
    memset(F1,0,sizeof(F1));
    memset(F2,0,sizeof(F2));
    for(long i=1;i<=19;++i)
    {
        a[i]=x%10;
        x/=10;
        if(x==0)
        {
            n=i;
            break;
        }
    }
    reverse(a+1,a+1+n);
    long cur=0;
    for(long i=1;i<=n;++i)
    {
        for(long u=1500;u>=0;--u)
        {
            for(long j=9;j>=0;--j)
            {
                if(u<j*j) continue;
                long c=j*j;
                F2[i][u]+=F2[i-1][u-c];
                if(j<a[i] && u-c==cur)
                {
                    F2[i][u]++;
                }

            }
        }
        cur+=a[i]*a[i];
    }
    long long dem=0;
    F2[n][cur]++;
    for(auto x:v)
    {
        dem+=F2[n][x];
    }
    return dem;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(CLMS".inp","r",stdin);
    freopen(CLMS".out","w",stdout);
    long res=0;
    tao();
    long t;
    cin >> t;
    while(t--)
    {
        long long l,r;
        cin >> l >> r;
        l--;
        cout << (r-l)-lam(r)+lam(l)<<endl;
    }
    return 0;
}
