#include <bits/stdc++.h>
using namespace std;

const int maxn = 70010;

long long n, L, m, w, a[11][maxn] , p[11][maxn], res = 0;

template <typename T> inline void read(T & x)
{
    x=0; char c; bool p=false;
    while(!isdigit(c=getchar())) if(c=='-') p=true;
    do x=x*10+c-48; while(isdigit(c=getchar()));
    if(p) x=-x;
}
template <typename T> void Write(T x) {if (x > 9) Write(x/10); putchar(x%10+48);}
template <typename T> void write(T x) {if (x < 0) {putchar('-'); x = -x;} Write(x);}

void legendary_buffalo()
{
    for(int id = 1; id <= n - L + 1; id++)
    {
        long long sum = 0;
        for(int i = 1; i <= m; i++)
            for(int j = id; j <= id + L - 1; j++)
        {
            sum += (a[i][j] * p[i][j - id + 1]);
        }
        if(sum > w) res++;
    }
    cout << res;
}

int main()
{
    freopen("DANCE.inp","r",stdin); freopen("DANCE.out","w",stdout);
    read(n); read(L); read(m); read(w);
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
           read(a[i][j]);
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= L; j++)
           read(p[i][j]);
    legendary_buffalo();
}
