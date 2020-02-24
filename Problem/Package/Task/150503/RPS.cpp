#include<bits/stdc++.h>
long long n,i,j,h,k,t,d,m,a[100005 ];
char f[2005][2005];
using namespace std;
bool xl(long long i)
{
    for(h=1;h<=n;h++) if (h!=i) for(k=1;k<=n;k++) if (k!=h&&k!=i&&f[i][h]=='1'&&f[h][k]=='1'&&f[k][i]=='1') return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("RPS.inp","r",stdin);
    freopen("RPS.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++) for(j=1;j<=n;j++) cin>>f[i][j];
    for(i=1;i<=n;i++) if (xl(i)) d++;
    cout<<d;
}
