#include<bits/stdc++.h>
using namespace std;
typedef int64_t lli;
lli l, r;
int f[2010];


int get_digsum(lli x)
{
    int sum= 0;
    while ( x > 0 )
    {
        sum+= (x%10)*(x%10);
        x/= 10;
    }
    return sum;
}

bool F(int x)
{
    if ( f[x] != -1 ) return f[x];
    int y= get_digsum(x);
    if ( y < 10 )
    {
        if ( y == 1 || y == 7 )
            f[x]= 1;
        else
            f[x]= 0;
        return f[x];
    }
    f[x]= F(y);
    return f[x];

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("pearl.inp", "r", stdin);
    freopen("pearl.out", "w", stdout);

    for (int i=0; i<2000; i++) f[i]= -1;
    for (int i=0; i<2000; i++) F(i);

    int test; cin>> test;
    for (int i=1; i<=test; i++)
    {
        cin>> l>> r;
        int cnt= 0;
        for (lli x=l; x<=r; x++)
        {
            int y= get_digsum(x);
            if ( f[y] == 0 ) cnt++;
        }
        cout<< cnt;
    }
}
