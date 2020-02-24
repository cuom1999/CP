#include <bits/stdc++.h>
typedef int64_t ll;
template<typename T> inline void read(T &x)
{
    x = 0; char c; bool p = false;
    while(!isdigit(c = getchar())) if(c == '-') p = true;
    do x = x * 10 + c - 48; while(isdigit(c = getchar()));
    if(p) x = -x;
}
template<typename T> void Write(T x)
{
    if(x > 9) Write(x / 10);
    putchar(x % 10 + 48);
}

using namespace std;

ll n, m, l, w, a[21][70001], b[21][70001], res;
void trau()
{
    int f1 = n - l + 1;
    for(int pos = 1; pos <= f1; pos++)
    {
        ll tg = 0;
        for(int i = 1; i <= m; i++)
        {
            int kk = 1;
            for(int j = pos; j <= pos + l - 1; j++)
            {
                tg += a[i][j] * b[i][kk];
                kk++;
            }
        }
        if(tg > w) res++;
    }
    Write(res);
}

int main()
{
    freopen("dance.inp", "r", stdin);
    freopen("dance.out", "w", stdout);
    read(n); read(l); read(m); read(w);
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++) read(a[i][j]);
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= l; j++) read(b[i][j]);
    trau();

}
