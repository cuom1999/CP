#include<cstdio>
#include<iostream>
using namespace std;
int t;
long long First,Last;
long long Cal(long long x)
{
    if (x>1) return (x-1)/9+1;
    return 1;
}
void sol()
{
    scanf("%d",&t);
    while (t--)
    {
        int counter=0;

        scanf("%lld%lld",&First,&Last);
        printf("%lld\n",Last-First+1-Cal(Last)+Cal(First-1));
    }
}
int main()
{
    freopen("pearl.inp","r",stdin);
    freopen("pearl.out","w",stdout);
    sol();
}
