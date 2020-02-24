#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define IN freopen("input.txt","r",stdin)
#define OUT freopen("output.txt","w",stdout)
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

ll x[1005], y[1005], a[1005], b[1005];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll sumX = 0, sumA = 0, sumB = 0, sumY = 0;
    FOR (i, 1, n) {
    	cin >> x[i] >> y[i];
    	sumX += x[i];
    	sumY += y[i];
    }
    FOR (i, 1, n) {
    	cin >> a[i] >> b[i];
    	sumA += a[i];
    	sumB += b[i];
    }

    ll X1 = (sumX + sumA - n * a[1]) / n;
    ll Y1 = (sumY + sumB - n * b[1]) / n;

    cout << X1 + a[1] << " " << Y1 + b[1] << endl;


 	   
	
    return 0;
    
}