#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
#define FOR(i,a,b) for(ll i=a ; i<=b ; i++)
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

ll n, k, a, b, l;
ll x = 1e18, y = -1;

void update() {
	ll res = n * k / __gcd(n * k, abs(l));

	x = min(x, res);
	y = max(y, res);

}

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> k >> a >> b;


    FOR (u, 1, n) {
    	l = u * k + b - a;
    	update();

    	l = u * k + b + a;
    	update();

		l = u * k - b + a;
    	update();
		
		l = u * k - b - a;
    	update();
    }
	

	cout << x << " " << y << endl;	
    return 0;
}