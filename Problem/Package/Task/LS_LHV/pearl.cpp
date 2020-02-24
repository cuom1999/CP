#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for (int i=a; i<=b; i++)
#define Rep(i,a,b) for (int i=a; i<b; i++)
#define Ford(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
const int N=1500;
int T,dx[N],s[20];
ll a,b,f[20][N][2],d[N];
int tinh(int x)
{
    int res=0;
    while (x>0)
    {
        int a=x%10;
        res+=a*a;
        x=x/10;
    }
    return res;
}
int check(int x)
{
    if (x==0) return 0;
    int cnt=x;
    while (dx[x]!=cnt)
    {
        if (d[x]!=-1) return d[x];
        dx[x]=cnt;
        x=tinh(x);
    }
    if (x==1) return 0;
    return 1;
}
ll F(int pos, ll sum, int ok)
{
    if (pos==0) return d[sum];
    if (f[pos][sum][ok]!=-1) return f[pos][sum][ok];
    ll res=0;
    int lim=(ok?s[pos]:9);
    For(i,0,lim) res+=F(pos-1,sum+i*i,ok&(i==s[pos]));
    return f[pos][sum][ok]=res;
}
ll solve(ll x)
{
    int len=0;
    while (x>0)
    {
        s[++len]=int(x%10);
        x=x/10;
    }
    memset(f,-1,sizeof(f));
    return F(len,0,1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("pearl.inp","r",stdin);
    freopen("pearl.out","w",stdout);
    memset(d,-1,sizeof(d));
    For(i,0,1458) d[i]=check(i);
    cin >> T;
    while (T--)
    {
        cin >> a >> b;
        cout << solve(b)-solve(a-1) << '\n';
    }
}
