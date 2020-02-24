#include <bits/stdc++.h>

using namespace std;
ifstream fi ("DANCE.INP");
ofstream fo ("DANCE.OUT");

int const maxn=70001,maxl=30001;
int n,l,m,W,TempW;
int T[11][maxn],P[11][maxl];
int ans=0;

void NhapDL()
{
    fi>>n>>l>>m>>W;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            fi>>T[i][j];
    for (int i=1; i<=m; i++)
        for (int j=1; j<=l; j++)
            fi>>P[i][j];
}

void Xuli()
{
    for (int j=1; j<=n-l+1; j++)
    {
        TempW=0;
        for (int u=j; u<=j+l-1; u++)
            for (int i=1; i<=m; i++)
            {
                TempW+=T[i][u]*P[i][u-j+1];
            }
        if (TempW>W) ans++;
    }
    fo<<ans<<endl;
}

int main()
{
    NhapDL();
    Xuli();
    return 0;
}
