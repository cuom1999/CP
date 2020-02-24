#include <bits/stdc++.h>

using namespace std;
char a[2001][2001],bt[2001][2001],btbt[2001][2001];
int n,d;

int main()
{
    freopen("RPS.inp","r",stdin);
    freopen("RPS.out","w",stdout);
    cin>>n;d=0;
    for (int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            bt[j][i]=a[i][j];
        }
    for (int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            btbt[i][j]='0';
    for (int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if (bt[i][j]=='1')
            {
                for (int k=1;k<=n;k++)
                if (bt[k][i]=='1') btbt[k][j]='1';
            }
        }

    }
    for (int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
           if ((a[i][j]==btbt[i][j]) and (a[i][j]=='1'))
           {
               d++;
               break;
           }
    }
        cout<<d;
}
