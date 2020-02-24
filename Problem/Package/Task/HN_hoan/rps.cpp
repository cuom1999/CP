#include <bits/stdc++.h>

using namespace std;
const long N=2002;
long n,ans;
typedef bitset<N>ii;
ii a[N],b[N];
ii res;
void nhap()
{
    cin>>n;
    char val;
    for(long i=0;i<n;++i)
    {
        for(long j=0;j<n;++j)
        {
            cin>>val;
            if(val=='1')a[i].set(j);
            else
                b[i].set(j);
        }
    }
}
void lam()
{
    for(long i=0;i<n;++i)
    {
        for(long j=0;j<n;++j)
        {
            if(a[i].test(j)==0)continue;
            res=(b[i]&a[j]);
            if(res.count()!=0)
            {
                ans++;
                break;
            }
        }
    }
    cout<<ans<<"\n";

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("rps.inp","r",stdin);
    freopen("rps.out","w",stdout);
    nhap();
    lam();
    return 0;
}
