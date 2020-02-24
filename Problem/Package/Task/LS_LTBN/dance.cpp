#include<bits/stdc++.h>
#define maxn 70010
#define maxm 110
template <typename T> inline void read(T &x)
{
    char c; bool nega= 0;
    while((!isdigit(c=getchar())) && c != '-');
    if(c == '-')
    {
        nega=1;
        c=getchar();
    }
    x=c-48;
    while( isdigit(c=getchar()) )x= x*10+c-48;
    if(nega) x =-x;
}
using namespace std;

int m, n, l, W, a[maxm][maxn], b[maxm][maxn];

bool check(int x)
{
    int sum= 0;
    for (int i=1; i<=m; i++)
    {
        for (int j=1; j<=l; j++)
            sum+= a[i][j+x-1]*b[i][j];
    }
    if ( sum > W )
        return true;
    return false;
}
void sexyBuffalo()
{
    int cnt= 0;

    for (int i=1; i<=n-l+1; i++)
    {
        if ( check(i) )
            cnt++;
    }

    cout<< cnt;
}
int main()
{
    freopen("dance.inp", "r", stdin);
    freopen("dance.out", "w", stdout);
    read(n); read(l); read(m); read(W);
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            read(a[i][j]);
    for (int i=1; i<=m; i++)
        for (int j=1; j<=l; j++)
            read(b[i][j]);

    sexyBuffalo();

    return 0;
}
