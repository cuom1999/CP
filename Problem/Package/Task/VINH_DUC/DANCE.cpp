#include <bits/stdc++.h>
using namespace std;
//===
int n,m,l,w;
int a[7005][15],f[7005][15];
//===
void    mf()
{
    freopen("DANCE.INP","r",stdin);
    freopen("DANCE.OUT","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
//===
void    doc()
{
    cin>>n>>m>>l>>w;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++) cin>>a[i][j];
    for (int i=1;i<=m;i++)
        for (int j=1;j<=l;j++) cin>>f[i][j];
}
//===
int     tong(int x)
{
    int tmp=0;
    for (int i=1;i<=l;i++)
        for (int j=1;j<=m;j++) tmp=tmp+a[j][x+i-1]*f[j][i];
    return(tmp);
}
//===
void    solve()
{
    int kq=0;
    for (int i=1;i<=n-l+1;i++)
        if(tong(i)>=w) kq++;
    cout<<kq<<endl;
}
//===
int main()
{
    mf();
    doc();
    solve();
}
