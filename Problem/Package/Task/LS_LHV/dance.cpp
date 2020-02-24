#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for (int i=a; i<=b; i++)
#define Rep(i,a,b) for (int i=a; i<b; i++)
#define Ford(i,a,b) for (int i=a; i>=b; i--)
const int N=70005;
const int L=30005;
int m,n,l,k,a[15][N],b[15][N],kq;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("dance.inp","r",stdin);
    freopen("dance.out","w",stdout);
    cin >> n >> l >> m >> k;
    For(i,1,m) For(j,1,n) cin >> a[i][j];
    For(i,1,m) For(j,1,l) cin >> b[i][j];
    For(x,1,n-l+1)
    {
        int res=0;
        For(i,1,m) For(j,x,x+l-1)
        {
            res+=a[i][j]*b[i][j-x+1];
            if (res>k)
            {
                kq++;
                goto line;
            }
        }
        line:;
    }
    cout << kq;
}
