#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define pmod 1000000007
#define maxn 100005
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(int i=a ; i<=b ; i++)
#define FORD(i,a,b) for(int i=a ; i>=b ; i--)
#define INF 1000000000
#define ll long long int
#define eps (1e-8)
#define sq(x) ( (x)*(x) )

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

ll gcd( ll a, ll b){
    if (a==0) return b;
    if (b==0) return a;
    if (a<b) return gcd(b%a,a);
    return gcd(a%b,b);
}
/*solve ax+by=gcd(a,b) */
ll ext_euclid(ll a, ll b, ll &x, ll &y) {
    ll xx=y=0;
    ll yy=x=1;
    while (b){
        ll q=a/b;
        ll t=b; b=a%b; a=t;
        t=xx; xx=x-q*xx; x=t;
        t=yy; yy=y-q*yy; y=t;
    }
    return a;
}
ll x,y;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ext_euclid(8,12,x,y);
    //cout<<x<<" "<<y<<endl;
    ll v=ceil(3);
    cout<<v<<endl;
         return 0;
}
