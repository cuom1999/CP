#include <bits/stdc++.h>

using namespace std;

int n, *dx, z, *q, fir, fina, *d, ans;
vector < int > *ke;

template < typename T > inline void read(T &x)
{
    char c;
    bool nega = false;
    while ((!isdigit(c = getchar())) && c != '-');
    if (c == '-')
    {
        c = getchar();
        nega = 1;
    }
    x = c - 48;
    while (isdigit(c = getchar()))
        x = x * 10 + c - 48;
    if (nega)
        x = -x;
}

bool bfs(int xp)
{
    ++z;
    fir = fina = 1;
    q[1] = xp;
    d[xp] =  0;
    while (fir <= fina)
    {
        int u = q[fir];
        ++fir;
        for (int v: ke[u])
            if (dx[v] <= z)
            {
                if (d[u] < 2)
                    q[++fina] = v;
                d[v] = d[u] + 1;
                dx[v] = z + 1;
            }
    }
    if (dx[xp] > z)
        return true;
    return false;
}

int main()
{
    if (fopen ("RPS.inp", "r"))
    {
        freopen ("RPS.inp", "r", stdin);
        freopen ("RPS.out", "w", stdout);
    }
    read(n);
    char ch;
    ke = new vector < int > [n + 1];
    dx = new int [n + 1];
    q = new int [n + 1];
    d = new int [n + 1];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            dx[i] = d[i] = 0;
            ch = getchar();
            while (ch == '\n' || ch == ' ') ch = getchar();
            if (ch == '1')
                ke[i].push_back(j);
        }
    }
    for (int i = 1; i <= n; ++i)
        if (bfs(i))
            ++ans;
    cout << ans;
}
