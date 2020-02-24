#include    <bits/stdc++.h>
#define		file "pearl"
#define     LL  long long
#define     fto(i,a,b)  for (int i=a; i<=b; ++i)
#define     fdo(i,a,b)  for (int i=a; i>=b; --i)
using   namespace   std;
int     t,res;
LL      l,r;
bool    d[205],m[205];
//-------------------------
void    input()
{
    #ifndef ONLINE_JUDGE
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
}
//-------------------------
bool    kt(int a)
{
    if (a==1) return true;
    if (m[a]==true) return false;
    int z=0;
    int x=a;
    while (x!=0)
    {
        z+=(x%10)*(x%10);
        x/=10;
    }
    while (z%10==0) z/=10;
    m[z]=true;
    return kt(z);
}
//-------------------------
bool    ok(LL a)
{
    LL z=0;
    while (a!=0)
    {
        z+=(a%10)*(a%10);
        a/=10;
    }
    if (z<=200) return d[z];
    else return ok(z);
}
//-------------------------
void    sub1()
{
    d[1]=true;
    fto(i,2,200)
    {
        memset(m,false,sizeof(m));
        d[i]=kt(i);
    }
    while (t--)
    {
        cin>>l>>r;
        res=0;
        for (LL i=l; i<=r; ++i)
            if (ok(i)) res++;
        cout<<res<<"\n";
    }
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
