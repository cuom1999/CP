//    KHAz
#include <bits/stdc++.h>
#define maxn 404
#define Task "rps"
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define pii pair< int , int >
#define reset(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
int n;
int a[maxn][maxn];
bool dd[maxn];
bool check(int x,int y,int z)
{
    if(a[x][y]==1&&a[y][z]==1&&a[z][x]==1) return true;
    return false;
}
void lam1()
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            char ch;cin>>ch;
            a[i][j]=ch-'0';
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                if(check(i,j,k)||check(i,k,j)||check(j,i,k)||check(j,k,i)||check(k,i,j)||check(k,j,i))
                {
                   dd[i]=1,dd[j]=1,dd[k]=1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++) if(dd[i]) ans++;
    cout<<ans;

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(Task".inp","r",stdin);
    freopen(Task".out","w",stdout);
    cin>>n;
    lam1();
    return 0;
}
