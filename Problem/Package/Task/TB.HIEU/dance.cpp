#include <bits/stdc++.h>

using namespace std;
ifstream fi("dance.inp");
ofstream fo("dance.out");
int n,m,l;
int W;
int t[11][7001];
int p[11][3001];
int kq=0;
bool kt(int x)
{
    int tg=0;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=l;j++)
        tg+=t[i][j+x]*p[i][j];
    if (tg>W) return true;
    return false;
}
int main()
{
    fi>>n>>l>>m>>W;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            fi>>t[i][j];
    for (int i=1;i<=m;i++)
        for (int j=1;j<=l;j++)
            fi>>p[i][j];
    for (int i=0;i<=n-l;i++)
        if (kt(i)==true) kq++;
    fo<<kq;
    return 0;
}
