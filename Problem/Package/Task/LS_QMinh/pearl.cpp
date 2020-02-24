#include <bits/stdc++.h>
template<typename T> inline void read(T &x)
{
    x = 0; char c; bool p = false;
    while(!isdigit(c = getchar())) if(c == '-') p = true;
    do x = x * 10 + c - 48; while(isdigit(c = getchar()));
}
template<typename T> void Write(T x)
{
    if(x > 9) Write(x / 10);
    putchar(x % 10 + 48);
}
typedef int64_t ll;
using namespace std;
ll t, l, r;

ll num(ll k)
{
    int tg = 0;
    while(k > 0)
    {
        k = k / 10;
        tg++;
    }
    return tg;
}

ll change(ll a)
{
    ll tg = 0;
    while(a > 0)
    {
        ll k = a % 10;
        tg += k * k;
        a = a / 10;
    }
    return tg;
}

void trau()
{
    ll res = 0;
    for(long long i = l; i <= r; i++)
    {
        ll k = i;
        while(num(k) > 1)
        {
            k = change(k);
        }
        if(k == 2 || k == 3 || k == 4 || k == 6 || k == 8 || k == 9 || k == 5) res++;
    }
    Write(res); putchar('\n');
}

bool dd[200001];
void prepare()
{
    for(int i = 1; i <= 1600; i++)
    {
        ll k = i;
        while(num(k) > 1)
        {
            k = change(k);
        }
        if(k == 2 || k == 3 || k == 4 || k == 6 || k == 8 || k == 9 || k == 5) dd[i] = true;
    }
}

ll dx[19][2][2001];
vector<int> Make(ll k)
{
    vector<int> tg;
    while(k > 0)
    {
        tg.push_back(k % 10);
        k = k / 10;
    }
    reverse(tg.begin(), tg.end());
    return tg;
}
vector<int> tg;
ll Dpdigits(int pos, bool ok, int sum)
{
    if(pos >= tg.size())
    {
        if(dd[sum]) return 1;
        else return 0;
    }
    if(dx[pos][ok][sum] != -1) return dx[pos][ok][sum];
    ll minh = 0;
    if(ok == false)
    {
        for(int i = 0; i <= tg[pos]; i++)
        {
            if(i == tg[pos])
                minh += Dpdigits(pos + 1, 0, sum + i * i);
            else
                minh += Dpdigits(pos + 1, 1, sum + i * i);
        }
        dx[pos][ok][sum] = minh;
        return minh;
    }
    else
    {
        for(int i = 0; i <= 9; i++)
        {
            minh += Dpdigits(pos + 1, 1, sum + i * i);
        }
        dx[pos][ok][sum] = minh;
        return minh;
    }

}

void QHD()
{
    memset(dx, -1, sizeof(dx));
    ll res = 0;
    tg = Make(r);
    res = Dpdigits(0, 0, 0);
    memset(dx, -1, sizeof(dx));
    tg = Make(l - 1);
    Write(res - Dpdigits(0, 0, 0)); putchar('\n');
}

int main()
{
    freopen("pearl.inp", "r", stdin);
    freopen("pearl.out", "w", stdout);
    read(t);
    prepare();
    for(int iTest = 1; iTest <= t; iTest++)
    {
        read(l); read(r);
        QHD();
    }
}
