#include <bits/stdc++.h>

using namespace std;
    int t[15][7005],p[15][3005],w,n,l,m,d;
    long long sum,tong;

int main()
{
    freopen("DANCE.inp","r",stdin);
    freopen("DANCE.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>l>>m>>w;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
          cin>>t[i][j];
    for (int i=1; i<=m; i++)
        for (int j=1; j<=l; j++)
          cin>>p[i][j];
    d=-1;
    sum=0;
    for (int k=1; k<=n-l+1; k++)
    {
        tong=0;
        d=d+1;
        for (int i=1; i<=m; i++)
            for (int j=k; j<=k+l-1; j++)
        {
            tong=tong+t[i][j]*p[i][j-d];
        }
        if (tong>w)
            sum=sum+1;
    }
    cout<<sum;
}
