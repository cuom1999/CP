#include <bits/stdc++.h>

using namespace std;

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

int n, m, l;
int W, **T, **P;

inline void ReadInput()
{
    if (fopen ("DANCE.inp", "r"))
    {
        freopen ("DANCE.inp", "r", stdin);
        freopen ("DANCE.out", "w", stdout);
    }
    read(m); read(l); read(n); read(W);
    T = new int *[n + 1];
    P = new int *[n + 1];
    for (int i = 0; i <= n; ++i)
    {
        T[i] = new int [m + 1];
        P[i] = new int [l + 1];
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            read(T[i][j]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= l; ++j)
            read(P[i][j]);

}
inline void Solve()
{
    int ans = 0;
    for (int i = m - l + 1; i > 0; --i)
    {
        int sum = 0;
        int last = i + l - 1;
        for (int j = 1; j <= n; ++j)
            for (int k = i; k <= last; ++k)
                sum += T[j][k] * P[j][k - i + 1];
        if (sum > W)
          ++ans;
    }
    cout << ans;
}
int main()
{
    ReadInput();
    Solve();
}
