#include <bits/stdc++.h>
#define FOR(i,a,b) for(long long i=a;i<=b;++i)
#define LL long long
using namespace std;
template <typename T> inline void read(T &x)
{
    bool Neg = false;
    char c;
    for(c=getchar(); c<'0' || c>'9' ;c =getchar() )
        if(c=='-') Neg= true;
    x = c-'0';
    for(c=getchar(); c>='0' && c<='9';c=getchar())
        x= x*10 +c-'0';
    if(Neg) x=-x;
}
const int N = 1e5 +3;
int n,L,m;
LL W;
LL a[11][70009] , b[11][30009] ;
int res = 0;
void Tinh(int P)
{
    LL kq = 0 ;
    for(int i=P-L+1;i<=P;i++)
    FOR(j,1,m){
        kq+= a[j][i] * b[j][i-P+L] ;
        if(kq>W){
            res++ ; return ;
        }
    }
   // cerr << kq <<'\n';
}
int main()
{
    ios::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    freopen("DANCE.inp","r",stdin);
    freopen("DANCE.out","w",stdout);
    cin >> n >> L >>  m >> W;
    FOR(i,1,m)  FOR(j,1,n) cin >> a[i][j] ;
    FOR(i,1,m)  FOR(j,1,L) cin >> b[i][j] ;

    FOR(i,L,n) Tinh(i) ;
    cout << res ;
}
