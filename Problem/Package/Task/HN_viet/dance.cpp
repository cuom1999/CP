//    KHAz
#include <bits/stdc++.h>
#define maxn 70002
#define Task "dance"
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define pii pair< int , int >
#define reset(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
int n,l,m,w,res;
int t[12][maxn],p[12][3002];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    cin>>n>>l>>m>>w;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
            cin>>t[i][j];
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=l;j++)
            cin>>p[i][j];
    }
    for(int i=1;i<=n-l+1;i++)
    {
        int ans=0;
        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<l;k++)
            {
                ans=ans+t[j][i+k]*p[j][k+1];
            }
        }
        if(ans>w) res++;
       // cout<<ans<<endl;
    }
    cout<<res;

    return 0;
}
