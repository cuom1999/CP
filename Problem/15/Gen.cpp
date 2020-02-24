#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("input.txt","w",stdout)
#define FOR(i,a,b) for(int i=a ; i<=b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define INF 1000000000
#define ll long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )
#define all(x) x.begin(),x.end()
#define flog2(n) 64 - __builtin_clzll(n) - 1
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;


long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}


int main()
{OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    srand(time(NULL));
    ll N=100000;
    ll n=Rand(90000,N); ll C=Rand(90000,N);
    cout<<n<<" "<<C<<"\n";
    FOR (i,1,n){
    	ll U=100;
    	ll x=Rand(0,U), y=Rand(0,U);
    	while (x+y==0){
    		x=Rand(0,U), y=Rand(0,U);
    	}
    	cout<<x/100.0<<" "<<y/100.0<<"\n";
    }

         return 0;
}