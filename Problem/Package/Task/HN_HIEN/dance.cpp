/// **********************************************************************************************************************
/// ********************************** ~ CODE - Trí Hi?n Diamond ? TQN ~ ******************************************
/// **********************************************************************************************************************
#include <bits/stdc++.h>
#define fi first
#define se second
#define mem0(ZED)  memset(ZED,0,sizeof(ZED))
#define memt(ZED)  memset(ZED,true,sizeof(ZED))
#define mem1(ZED)  memset(ZED,1,sizeof(ZED))
#define mp make_pair
#define PB push_back
#define btcount(x) __builtin_popcount(x)
#define getbit(x,i) ((x>>i)&1)
#define offbit(x,i) (~(1<<i)&x)
#define onbit(x,i) (x|(1<<i))
#define sqr(x) ((x) * (x))
#define INF 9999999999
#define MOD 1000000007
#define maxn 1005000
#define m5 100005
#define maxm 7011

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i,n) for (int i=0;i<(n);i=i+1)

#define TranQuynhNGA "dance"

#define ull unsigned long long
#define uld unsigned long double
#define ld long double
#define ll long long

const long base = 14012001 ;
const ll MM = 1ll * MOD * MOD ;

using namespace std ;

typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <string> vs;

// bit operater
int BIT(int i,ll x) { return(x&(1<<i));}
ll ONBIT(int i,ll x){ return(x|(1<<i));}
ll OFFBIT(int i,ll x){return (x& ~(1<<i));}
ll FLIPBIT(int i,ll x){return (x^(1<<i));}
ll NUMBIT(ll x) {return __builtin_popcount(x);}

// math
template<class T> T GCD(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T LCM(T a, T b) { return a / GCD(a, b) * b; }
long n , m , l , W ;
long a[maxm][maxm] ;
long b[maxm][maxm] ;
long save[maxm][maxm] ;
void read()
{
    cin >> n >> l >> m >> W ;
    for ( long i = 1 ; i <= m ; i ++ )
    {
        for ( long j = 1 ; j <= n ; j ++ )
        {
            cin >> a[i][j] ;
        }
    }
    for ( long i = 1 ; i <= m ; i ++ )
    {
        for ( long j = 1 ; j <= l ; j ++ )
        {
            cin >> b[i][j] ;
        }
    }
}
long ans = 0 ;
void solve()
{
    long c = 0 , h = 0 ;
    long t = 1 , p = min(t + l - 1,n) ;
    while ( p <= n )
    {
        long z = 0 ;
        for ( long i = t ; i <= p ; i ++ )
        {
            long top = 0 ;
            z ++ ;
            for (long j = 1 ; j <= m ; j ++ )
            {
                save[++top][z] = a[j][i] ;
            }
        }
        ll res = 0 ;
        for ( long i = 1 ; i <= m ; i ++ )
        {
            for ( long j = 1 ; j <= l ; j ++ )
            {
                res += save[i][j] * b[i][j] ;
                //cout << save[i][j] << " " ;
            }
            //cout << endl ;
        }
        if ( res > W )
            ans ++ ;
        t ++ ;
        p ++ ;
        //cout << endl ;
        if ( p > n ) break ;
    }
    cout << ans ;
}
int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(NULL) ; cout.tie(NULL) ;
    freopen( TranQuynhNGA".inp" , "r" , stdin ) ;
    freopen( TranQuynhNGA".out" , "w" , stdout ) ;
    read() ;
    solve() ;

return 0 ;

}
