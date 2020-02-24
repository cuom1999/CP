//    ^Bjerg^
#include <bits/stdc++.h>
#define maxn 2005
#define CLMS "RPS"
#define ft first
#define sd second
#define PB push_back
#define MP make_pair
#define endl "\n"
using namespace std;
bitset < maxn > f1[maxn];
bitset < maxn > f2[maxn];
long n;
char a[maxn][maxn];
void nhap()
{
    cin >> n;
    for(long i=1;i<=n;++i)
    {
        for(long j=1;j<=n;++j)
        {
            cin >> a[i][j];
            if(i<j)
            {
                if(a[i][j]=='1')
                {
                    f1[i].set(j);
                    f2[j].set(i);
                }
                else
                {
                    f2[i].set(j);
                    f1[j].set(i);
                }
            }
        }
    }
}
void sub1()
{
    long res=0;
    for(long i=1;i<=n;++i)
    {
        for(long j=1;j<=n;++j)
        {
            long cur=0;
            for(long u=1;u<=n;++u)
            {
                if(a[i][j]=='1' && a[j][u]=='1' && a[u][i]=='1')
                {
                    cur++;
                }
            }
            if(cur>0)
            {
                res+=cur;
                res-=(cur-1)*2;
            }
        }
    }
    cout << res;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(CLMS".inp","r",stdin);
    freopen(CLMS".out","w",stdout);
    nhap();
    if(n<=200)
    {
        sub1();
        return  0;
    }
    long res=0;
    for(long i=1;i<=n;++i)
    {
        for(long j=i+1;j<=n;++j)
        {
            if(i!=j)
            {
                if(a[i][j]=='1')
                {
                     bitset < maxn > f;
                     f=(f1[j]&f2[i]);
                     long x=f.count();
                     res+=x;
                     if(x)res-=(x-1)*2;
                }
                else
                {
                     bitset < maxn > f;
                     f=(f2[j]&f1[i]);
                     long x=f.count();
                     res+=x;
                     if(x)res-=(x-1)*2;
                }
            }
        }
    }
    cout << res;
    return 0;
}
