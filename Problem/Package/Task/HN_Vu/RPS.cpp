///TranNhatVu
///Hacker
#include<bits/stdc++.h>

#define bit(n,i) (((n)>>(i))&1)
#define cntbit(n) __builtin_popcount(n)
#define el; cout<<"\n";
#define fi first
#define file "RPS"
#define	f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
#define Fo(i,a,b) for(int i=a;i<=b;i++)
#define lb lower_bound
#define len length()
#define ll long long
#define maxn 2002
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
int n;
char c[maxn][maxn];
int dd[maxn], ans;
bool check (int x, int y, int z)
{
    if(c[x][y] == '1' && c[y][z] == '1' && c[z][x] == '1') return 1;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    cin >> n;
    f1(i, n) f1(j, n)
        cin >> c[i][j];
    f1(i, n-2)
        Fo(j, i+1, n-1)
            Fo(k, j+1, n)
                if(check (i, j, k)|| check(i, k, j) || check(j, i, k) || check(j, k, i) || check(k, i, j) || check(k, j, i))
                    dd[i]=dd[j]=dd[k]=1;
    f1(i, n) ans += dd[i];
    cout << ans;
    return 0;
}
