#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define fi first
#define se second

using namespace std;
typedef pair<int,int> ii;

int n,m,l,a[12][700005],b[12][700005];
int w;

char k;
int main()
{
    freopen("DANCE.INP","r",stdin);
    freopen("DANCE.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n>>l>>m>>w;
    FOR(i,1,m)
        FOR(j,1,n) cin>>a[i][j];
    int dem=0;
    FOR(i,1,m)
        FOR(j,1,l) cin>>b[i][j];
    FOR(i,1,n-l+1)
        {
            int tong=0;
          FOR(j,1,m)
            FOR(k,1,l) tong+=a[j][k+i-1]*b[j][k];
            if (tong>w) dem++;
        }
    cout<<dem;




}
