#include <bits/stdc++.h>

using namespace std;
ifstream fi ("dance.inp");
ofstream fo ("dance.out");
long long n,m,l,w;
int a[10][7001];
int b[10][3001];
long long kq[7001];
void nhap()
{
    fi>>n>>l>>m>>w;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            fi>>a[i][j];
    for (int i=1; i<=m; i++)
        for (int j=1; j<=l; j++)
            fi>>b[i][j];
}
int dem=0;
void xuli()
{
    for (int i=1; i<=n-l+1; i++)
    {
        for (int j=1; j<=m; j++)
            for (int x=i; x<i+l; x++)
                kq[i]=kq[i]+a[j][x]*b[j][x-i+1];
    }
for (int i=1;i<=n;i++)
    if(kq[i]>w) dem++;
    fo<<dem;
}
int main()
{
    nhap();
    xuli();
    return 0;
}
