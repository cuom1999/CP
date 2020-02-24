#include<bits/stdc++.h>
long long n,i,j,h,k,t,dd,d,m,f[1460],l,r,ff[20][1460],a[1000];
bool kt[1460];
using namespace std;
long long figure(long long x)
{
    long long res=0,t;
    while (x>0)
    {
        t=x%10;
        res+=t*t;
        x/=10;
    }
    return res;
}
void xl(long long i)
{
    long long j;
    kt[i]=true;
    j=figure(i);
    if (kt[j]==false) xl(j);
    f[i]=f[j];
}
long long xll(long long r,long long x)
{
    long long res=0;
    long long i,j,t,rr=r%10;
    for(j=0;j<rr;j++)
        for(i=1;i<=dd;i++)
    {
    t=figure(r/10)+j*j;
    if (a[i]>=t) res+=ff[x][a[i]-t];
    }
    return res;
}
long long dem(long long r)
{
    long long rr,res=0,i,x=0;
    for(i=0;i<=r%10;i++) if (f[figure(r-i)]==1) res++;
    while (r>=10)
    {
        r/=10;x++;
        if (r%10!=0) res+=xll(r,x);
    }
    return res;
}
int main()
{
    freopen("pearl.inp","r",stdin);
    freopen("pearl.out","w",stdout);
    kt[1]=true;
    f[1]=1;
    for(i=2;i<=1458;i++) if (kt[i]==false) xl(i);
    for(i=1;i<=1458;i++) if (f[i]==1) dd++,a[dd]=i;
    for(i=0;i<=9;i++) ff[1][i*i]=1;
    for(i=0;i<=18;i++) ff[i][0]=1;
    for(i=2;i<=18;i++) for(j=1;j<=1458;j++) for(h=0;h<=9;h++) if (j>=h*h) ff[i][j]+=ff[i-1][j-h*h];
    d=0;
    for(i=1;i<=1458;i++) if (f[i]==1) d+=ff[2][i];
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>l>>r;
        cout<<r-l+1-(dem(r)-dem(l-1))<<endl;
    }
}
