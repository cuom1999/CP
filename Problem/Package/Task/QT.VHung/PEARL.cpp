#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define fi first
#define se second

using namespace std;
typedef pair<int,int> ii;

int giatri(ll so)
{
    int gt=0;
    while(so) gt+=(so%10)*(so%10),so=so/10;
    return gt;
}
int kt[3005];
int main()
{
    freopen("PEARL.INP","r",stdin);
    freopen("PEARL.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    ll t,l,r;
    cin>>t;
        FOR(i,1,2000)
        {
            int so=i;
            int demtam=0;
            while(so!=1 && demtam<=500) so=giatri(so),demtam++;
            if (so==1) kt[i]=1;
        }
    FOR(i,1,t)
    {
        int d=0;
        cin>>l>>r;
        while(l<=r)
         {
             ll so=l;
             so=giatri(so);
             if (kt[so]==0) d++;
             l++;
         }
         cout<<d<<endl;
    }



}
