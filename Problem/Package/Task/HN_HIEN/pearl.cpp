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
#define maxm 1011

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i,n) for (int i=0;i<(n);i=i+1)

#define TranQuynhNGA "pearl"

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
long n , m ;
ll L , R ;
void read()
{
    cin >> L >> R ;
}
long F[maxn] ;
long tongcs ( long k )
{
    long res = 0 ;
    while ( k > 0 )
    {
        res += sqr(k%10) ;
        k = k / 10 ;
    }
    return res ;
}
long dd[2000]  ;
void Init()
{
    F[1458] = 0 ;
    for ( long i = 1 ; i <= 1458; i ++ ) F[i] = -1 ;
    for ( long i = 1458 ; i >= 1 ; i -- )
    {
        long k = i ;
        for ( long j = 1458 ; j >= 1 ; j -- ) dd[j] = 0 ;
        while ( true )
        {
            if ( tongcs(k) == 1 )
            {
                F[i] = 1 ;
                break ;
            }
            if ( dd[tongcs(k)] )
            {
                F[i] = 0 ;
                break ;
            }
            if ( tongcs(k) > i )
            {
                F[i] = F[tongcs(k)] ;
                break ;
            }
            k = tongcs(k) ;
            dd[k] = 1 ;
        }
    }
}
void sub1()
{
    ll ans = 0 ;
    for ( long long i = L ; i <= R ; i ++ )
    {
        long long k = tongcs(i) ;
        if ( F[k] == 0 )
        {
            ans ++ ;
        }
    }
    cout << ans << endl ;
}

int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(NULL) ; cout.tie(NULL) ;
    freopen( TranQuynhNGA".inp" , "r" , stdin ) ;
    freopen( TranQuynhNGA".out" , "w" , stdout ) ;
    Init() ;
//    for ( long i = 1 ; i <= 1458 ; i ++ )
//    {
//        if ( F[i] ) cout << i << " " ;
//    }
    long te ;
    cin >> te ;
        while ( te -- )
        {
            read() ;
            sub1() ;
        }

return 0 ;

}
