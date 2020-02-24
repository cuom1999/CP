#include<cstdio>
#include<stdlib.h>
#include<iostream>
using namespace std;
const int limit=1e5+100;
int n,l,m,w;
long long total,Min;
long long dp[limit],sum[limit][100];
int a[limit][100],b[limit][100];
void in()
{
    bool ze[2]={true,true};
    scanf("%d%d%d%d",&n,&l,&m,&w);
    for (int y=1;y<=m;y++)
        for (int x=1;x<=n;x++)
        {
            scanf("%d",&a[x][y]);
            sum[x][y]=sum[x-1][y]+sum[x][y-1]+a[x][y]-sum[x-1][y-1];
            if (a[x][y]) ze[0]=false;
        }
    for (int y=1;y<=m;y++)
        for (int x=1;x<=l;x++)
        {
            scanf("%d",&b[x][y]);
            if (b[x][y]) ze[1]=false;
            Min=min(Min,1ll*b[x][y]);
        }
    if (ze[0] || ze[1] && w)
    {
        printf("0");
        exit(0);
    }
}
bool check(int t)
{
    if (sum[t][m]-sum[t-1][m]==0 && w) return false;
    if ((sum[t][m]-sum[t-l][m])*Min>=w) return true;
    long long res=0,pointer=0;
    for (int x=t-l+1;x<=t;x++)
    {
        pointer++;
        for (int y=1;y<=m;y++)
        {
            res+=1ll*a[x][y]*1ll*b[pointer][y];
            if (res>=w) return true;
        }
    }
    return res>=w;
}
void so()
{
    int res=0;
    for (int x=l;x<=n;x++)
    {
       if (check(x)) res++;
    }
    printf("%d",res);
}
int main()
{

    freopen("dance.inp","r",stdin);
    freopen("dance.out","w",stdout);
    in();
    so();
}
