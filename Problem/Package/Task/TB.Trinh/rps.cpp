#include <bits/stdc++.h>

using namespace std;
ifstream fi ("rps.inp");
ofstream fo ("rps.out");
int n;
vector<int> g[20001];
int s[20001][20001];
void nhap2()
{
    fi>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            char k;
            fi>>k;
            if(k=='1') s[i][j]=1;
            else if(i!=j) s[j][i]=1;
        }
}
bool check(int z)
{
    for (int x=1;x<=n;x++)
        for (int y=1;y<=n;y++)
        if(s[z][x]==1&&s[x][y]==1&&s[y][z]==1) return false;
        else if(s[x][z]==1&&s[z][y]==1&&s[y][x]==1) return false;
    return true;
}
void xuli2()
{
    int dem=0;
    for (int i=1;i<=n;i++)
      if(check(i)==true)dem++;
      fo<<n-dem;
}
int main()
{
    nhap2();
    xuli2();
    return 0;
}
