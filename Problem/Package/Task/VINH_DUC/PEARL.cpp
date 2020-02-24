#include<bits/stdc++.h>
using namespace std;
//===
int T;
long long l,r;
//===
void    mf()
{
    freopen("PEARL.INP","r",stdin);
    freopen("PEARL.OUT","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
//===
void    doc()
{
    cin>>T;
}
//===
bool    check(long long k)
{
    while (k>44)
    {
        long long tmp=0;
        while (k>0)
        {
            tmp=tmp+(k%10)*(k%10);
            k=k/10;
        }
        k=tmp;
    }
    if (k==44 || k==32 || k==23 || k==31 || k==13 || k==1 || k==10) return(1);
    return(0);
}
//===
void    solve()
{
    cin>>l>>r;
    long long res=0;
    for (int i=l;i<=r;i++)
        if (check(i)==0) res++;
    cout<<res<<"\n";
}
//===
int main()
{
    mf();
    doc();
    while (T--) solve();
}

