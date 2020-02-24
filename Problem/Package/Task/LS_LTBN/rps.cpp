#include<bits/stdc++.h>
#define maxn 2010
using namespace std;
int n, bf[maxn], visited[maxn];
vector<int> bes[maxn];
bool edge[maxn][maxn], choose[maxn], res_check;

void getmark(int u, int x)
{
    int v= bf[u];
    choose[v]= 1;
    if ( v == x ) return;
    else
        getmark(v, x);
}
void dfs(int u, int x, int cur)
{
    if ( cur == 3 && u == x )
    {
        res_check= 1;
        getmark(u, u);
        return;
    }
    if ( cur > 3 ) return;
    for (int i=0; i<bes[u].size(); i++)
    {
        int v= bes[u][i];
        if ( visited[v] != x )
        {
            visited[v]= x;
            bf[v]= u;
            dfs(v, x, cur+1);
        }
    }
}

void SomethingElse()
{
    for (int i=1; i<=n; i++)
    {
        dfs(i, i, 0);
    }
    int res= 0;
    for (int i=1; i<=n; i++)
        if ( choose[i] == 1 )
            res++;
    cout<< res;
}
bool mchoose[maxn];
bool bcheck(int x, int y, int z)
{
    if ( edge[x][y] == 1 && edge[y][z] == 1 && edge[z][x] == 1 )
        return true;
    if ( edge[x][z] == 1 && edge[z][y] == 1 && edge[y][x] == 1 )
        return true;
    return false;
}
void sexyBuffalo()
{
    for (int i=1; i<=n; i++)
        for (int j=i+1; j<=n; j++)
            for (int k=j+1; k<=n; k++)
            {
                if ( bcheck(i, j, k) )
                    mchoose[i]= 1, mchoose[j]= 1, mchoose[k]= 1;
            }
    int cnt= 0;
    for (int i=1; i<=n; i++)
        if ( mchoose[i] == 1 )
            cnt++;

    cout<< cnt;
}
int main()
{
    freopen("rps.inp", "r", stdin);
    freopen("rps.out", "w", stdout);
    cin>> n;

    char ch= getchar();

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            ch= getchar();
            if ( ch == '1' )
            {
                bes[i].push_back(j);
                if ( n <= 200 ) edge[i][j]= 1;
            }
        }
        ch= getchar();
    }

    if ( n <= 200 ) sexyBuffalo();
    else SomethingElse();
}

