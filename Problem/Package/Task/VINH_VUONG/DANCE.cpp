#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fo1(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
typedef long long ll;
const int N=7005;
int n,m,l,w,res;
int a[N][15],f[N][15];
//=====================================================================
void file()
{
    freopen("DANCE.INP","r",stdin);
    freopen("DANCE.OUT","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
}
//=====================================================================
int cal(int x)
{
    int sum=0;
    fo(i,1,l)
    fo(j,1,m) sum+=a[j][x+i-1]*f[j][i];
    return sum;
}
//=====================================================================
void solve()
{
    res=0;
    fo(i,1,n-l+1) if(cal(i)>=w) res++;
    cout<<res<<endl;
}
//=====================================================================
void read()
{
    cin>>n>>m>>l>>w;
    fo(i,1,m)
    fo(j,1,n) cin>>a[i][j];
    fo(i,1,m)
    fo(j,1,l) cin>>f[i][j];
    solve();
}
//=====================================================================
int main()
{
    file();
    read();
}
//=====================================================================

