#include <bits/stdc++.h>

using namespace std;
  long long l,r,luu[1000];
  int d,t,sum;
  bool f[1000005];


void kiemtra(long long x)
{
    int du;
    int need;
    need=0;
    while (x>0)
     {
        du=x%10;
        need=need+du*du;
        x=x/10;
     }
     if (need==1)
     {
         return;
     }
     if (f[need]==true)
     {
         sum=sum+1;
         return;
     }
     f[need]=true;
     d=d+1;
     luu[d]=need;
    kiemtra(need);
}
int main()
{
    freopen("PEARL.inp","r",stdin);
    freopen("PEARL.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    cin>>l>>r;
    sum=0;
    memset(f,false,sizeof(f));
    while (l<=r)
    {
        d=0;
        kiemtra(l);
        for (int i=1; i<=d; i++)
            f[luu[i]]=false;
        l=l+1;
    }
    cout<<sum;
}
