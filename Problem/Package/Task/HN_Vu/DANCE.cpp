///TranNhatVu
///Hacker
#include<bits/stdc++.h>

#define bit(n,i) (((n)>>(i))&1)
#define cntbit(n) __builtin_popcount(n)
#define el; cout<<"\n";
#define fi first
#define file "dance"
#define	f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define Fo(i,a,b) for(int i=a;i<=b;i++)
#define lb lower_bound
#define len length()
#define ll long long
#define maxn 70010
#define MOD 1000000007
#define mp make_pair
#define oo 2003012500
#define pb push_back
#define pi acos(-1)
#define pii pair<int,int>
#define reset(x) memset(x,0,sizeof(x))
#define se second
#define sz size()
#define ub upper_bound
#define ull unsigned long int

using namespace std;
///declare:
int n, m, l, w, a[11][maxn], b[11][maxn/2], ans;
int check(int pos)
{
    int sum = 0;
    f1(j, m) for (int i=pos; i<=pos+l-1; i++)
        sum += a[j][i] * b[j][i-pos+1];
    return (sum > w);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    cin >> n >> l >> m >>w;
    f1(i, m) f1(j, n) cin >> a[i][j];
    f1(i, m) f1(j, l) cin >> b[i][j];
    f1(i, n-l+1) if(check(i))ans++;
    cout << ans;
    return 0;
}
