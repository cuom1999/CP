#include    <bits/stdc++.h>
#define		file "rps"
#define     LL  long long
#define     fto(i,a,b)  for (int i=a; i<=b; ++i)
#define     fdo(i,a,b)  for (int i=a; i>=b; --i)
using   namespace   std;
int     n;
vector  <int> a[2005],b[2005];
bool    F[2005];
//-------------------------
void    input()
{
    #ifndef ONLINE_JUDGE
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    fto(i,1,n)
    fto(j,1,n)
    {
        char ch;
        cin>>ch;
        if (i==j) continue;
        if (ch=='1')
        {
            a[i].push_back(j);
            b[j].push_back(i);
        }
        else
        {
            a[j].push_back(i);
            b[i].push_back(j);
        }
    }
}
//-------------------------
void    sub1()
{
    int cnt=0;
    fto(i,1,n)
    {
        bool d=0;
        for (int j=0; j<a[i].size(); ++j)
        {
            int u=a[i][j];
            for (int k=0; k<a[u].size(); ++k)
            {
                int v=a[u][k];
                for (int l=0; l<a[v].size(); ++l)
                    if (a[v][l]==i) d=1;
            }
        }
        if (!d) cnt++;
    }
    cout<<n-cnt;
}
//-------------------------
void    sub2()
{
    int cnt=0;
    fto(i,1,n)
    {
        bool ok=false;
        memset(F,0,sizeof(F));
        for (int j=0; j<b[i].size(); ++j) F[b[i][j]]=1;
        for (int j=0; j<a[i].size(); ++j)
        {
            int u=a[i][j];
            for (int k=0; k<a[u].size(); ++k)
            {
                int v=a[u][k];
                if (F[v]) ok=true;
            }
        }
        if (!ok) cnt++;
    }
    cout<<n-cnt;
}
//-------------------------
void    solve()
{
    if (n<=100) sub1();
    else sub2();
}
//-------------------------
int     main()
{
    input();
    solve();
}
