#include <bits/stdc++.h>

using namespace std;
const long N=7e4+4;
long a[11][N],n,l,m,w,b[11][N],ans;
void nhap()
{
    cin>>n>>l>>m>>w;
    for(long i=1;i<=m;++i)
    {
        for(long j=1;j<=n;++j)
            cin>>a[i][j];
    }
    for(long i=1;i<=m;++i)
    {
        for(long j=1;j<=l;++j)
            cin>>b[i][j];
    }
}
void lam()
{
    long res;
    for(long k=1;k<=n-l+1;++k)
    {
        res=0;
        for(long i=1;i<=m;++i)
        {
            for(long j=1;j<=l;++j)
            {
                res=res+a[i][j+k-1]*b[i][j];
            }
        }
        if(res>w)
            ans++;
    }
    cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("dance.inp","r",stdin);
    freopen("dance.out","w",stdout);
    nhap();
    lam();
    return 0;
}
