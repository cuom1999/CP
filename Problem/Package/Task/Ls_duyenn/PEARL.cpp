#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int T, a[20], n;
ll L, R;
bool *rev;
bool dx[20][1500][2];
ll f[20][1500][2];

inline ll calc(ll u)
{
    ll tmp = 0;
    while (u)
    {
        ll v = u % (ll)10;
        tmp += v * v;
        u /= (ll)10;
    }
    return tmp;
}
inline void pre()
{
    rev = new bool [1460];
    rev[0] = false;
    rev[1] = true;
    for (int i = 2; i <= 1458; ++i)
    {
        rev[i] = false;
        ll u = (ll)i;
        for (int j = 1; j <= 1458; ++j)
        {
            u = calc(u);
            if (u == (ll)1)
            {
                rev[i] = true;
                break;
            }
        }
    }
}
ll F(int I, int tt, int ok)
{
    if (I > n)
        if (rev[tt]) return (ll)0;
        else return (ll)1;
    if (dx[I][tt][ok]) return f[I][tt][ok];
    if (!ok)
    {
        for (int i = 0; i < a[I]; ++i)
            f[I][tt][ok] += F(I + 1, tt + i * i, true);
        f[I][tt][ok] += F(I + 1, tt + a[I] * a[I], false);
    }
    else
    {
        for (int i = 0; i <= 9; ++i)
            f[I][tt][ok] += F(I + 1, tt + i * i, true);
    }
    dx[I][tt][ok] = true;
    return f[I][tt][ok];
}
void Solve()
{
    cin >> L >> R;
    L -= (ll)1;
    n = 0;
    while (L)
    {
        a[++n] = L % (ll)10;
        L /= (ll)10;
    }
    memset (f, 0, sizeof(f));
    memset (dx, 0, sizeof(dx));
    reverse(a + 1, a + 1 + n);
    ll r1 = F(1, 0, 0);
    n = 0;
    while (R)
    {
        a[++n] = R % (ll)10;
        R /= (ll)10;
    }
    reverse(a + 1, a + 1 + n);
    memset (f, 0, sizeof(f));
    memset (dx, 0, sizeof(dx));
    ll r2 = F(1, 0, 0);
    cout << r2 - r1 << '\n';
}
int main()
{
    if (fopen ("PEARL.inp", "r"))
    {
        freopen ("PEARL.inp", "r", stdin);
        freopen ("PEARL.out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    pre();
    cin >> T;
    while (T--)
        Solve();
}
