#include    <bits/stdc++.h>
#define		file "dance"
#define     LL  long long
#define     fto(i,a,b)  for (int i=a; i<=b; ++i)
#define     fdo(i,a,b)  for (int i=a; i>=b; --i)
using   namespace   std;
int     n,l,m,W,a[15][7005],b[15][3005];
int     res,ans;
//-------------------------
void    input()
{
    #ifndef ONLINE_JUDGE
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>l>>m>>W;
    fto(i,1,m)
    fto(j,1,n)
        cin>>a[i][j];
    fto(i,1,m)
    fto(j,1,l)
        cin>>b[i][j];
}
//-------------------------
void    sub1()
{
    res=0;
    fto(i,1,n-l+1)
    {
        ans=0;
        fto(j,1,m)
        fto(k,1,l)
            ans+=b[j][k]*a[j][i+k-1];
        if (ans>W) res++;
    }
    cout<<res;
}
//-------------------------
void    solve()
{
    sub1();
}
//-------------------------
int     main()
{
    input();
    solve();
}
