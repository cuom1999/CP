#include <iostream>
#include <bits/stdc++.h>
#define fi "pearl.inp"
#define fo "pearl.out"
#define maxn 8000001

using namespace std;
int64_t t,n,m;
int64_t gg[maxn], dd[maxn], xh[maxn];

int tinh(int x)
{
    xh[x]=1;

    int64_t d=0, tg;
    while(x >0)
    {
        tg=x%10;
        ++d;
        gg[d]=tg;
        x=x/10;
    }
    int64_t sum=0;
    for(int i=1; i<=d; ++i)
    {
        sum= sum+ gg[i]*gg[i];
    }

    if(dd[sum]==1) {return(0);}
    else if(xh[sum]!= 0) return(1);
    else tinh(sum);
}
void pro1(int n, int m)
{
    int64_t tg, ans=0;
    for(int i=1; i<=2000; ++i) dd[i]=0;
    dd[1]=1;
    for(int i=2; i<=2000; ++i)
    {
        for(int j=1; j<=2000; ++j) {xh[j]=0;}
        if(tinh(i)==0) {dd[i]=1;} //++ans; cout<<i<<endl;}
    }
    //cout<<tinh(2942002);
    for(int i=n; i<=m; ++i)
    {
        tg =tinh(i);
        if(tg==1) {++ans; }
    }
    cout<<ans<<endl;
}

void sub1()
{
    cin>>t;
    for(int i=1; i<=t; ++i)
    {
        cin>>n>>m;
        pro1(n,m);
    }
}

int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    sub1();
}
