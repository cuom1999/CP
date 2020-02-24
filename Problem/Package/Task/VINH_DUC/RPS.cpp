#include<bits/stdc++.h>
using namespace std;
//===
int n;
vector <int> a[2005],b[2005];
bool F[2005];
//===
void    mf()
{
    freopen("RPS.INP","r",stdin);
    freopen("RPS.OUT","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
//===
void    doc()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            char ch;
            cin>>ch;
            if (i==j) continue;
            if (ch=='1')
            {
                a[i].push_back(j);
                b[j].push_back(i);
            }
            else
            {
                a[j].push_back(i);
                b[i].push_back(j);
            }
        }
}
//===
void    sub1()
{
    int cnt=0;
    for (int i=1;i<=n;i++)
    {
        bool ok=false;
        for (int j=0;j<a[i].size();j++)
        {
            int u=a[i][j];
            for (int k=0;k<a[u].size();k++)
            {
                int v=a[u][k];
                for (int l=0;l<a[v].size();l++)
                    if (a[v][l]==i) ok=true;
            }
        }
        if (!ok) cnt++;
    }
    cout<<n-cnt;
}
//===
void sub2()
{
    int cnt=0;
    for (int i=1;i<=n;i++)
    {
        bool ok=false;
        memset(F,0,sizeof(F));
        for (int j=0;j<b[i].size();j++) F[b[i][j]]=1;
        for (int j=0;j<a[i].size();j++)
        {
            int u=a[i][j];
            for (int k=0;k<a[u].size();k++)
            {
                int v=a[u][k];
                if (F[v]) ok=true;
            }
        }
        if (!ok) cnt++;
    }
    cout<<n-cnt;
}
//===
void solve()
{
    if (n<=100) sub1();
    else sub2();
}
//===
int main()
{
    mf();
    doc();
    solve();
}

