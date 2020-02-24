#include <bits/stdc++.h>
using namespace std;

long long t,l,r;
bool dx[1500];

template <typename T> inline void read(T & x)
{
    x=0; char c; bool p=false;
    while(!isdigit(c=getchar())) if(c=='-') p=true;
    do x=x*10+c-48; while(isdigit(c=getchar()));
    if(p) x=-x;
}
template <typename T> void Write(T x) {if (x > 9) Write(x/10); putchar(x%10+48);}
template <typename T> void write(T x) {if (x < 0) {putchar('-'); x = -x;} Write(x);}

bool check(long long x)
{
    int kq = 0;
    while(x > 0)
    {
        int dv = x % 10;
        kq += dv*dv;
        x /= 10;
    }
    if(kq == 1) return true;
    if(dx[kq]) return false;
    dx[kq] = true;
    check(kq);
}

int main()
{
    freopen("PEARL.inp","r",stdin); freopen("PEARL.out","w",stdout);
    read(t);
    while(t--)
    {
        long long res = 0;
        read(l); read(r);
        for(long long i = l; i <= r; i++)
        {
            memset(dx, false, sizeof(dx));
            if(!check(i)) res++;
        }
        write(res); putchar('\n');
    }
}
