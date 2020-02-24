#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
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

ll R[7];

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
	int t, w;
	cin >> t >> w;

	FOR (z, 1, t) {
		ll x;

		cout << 200 << endl;
		cin >> x;

		x /= (1LL << 33);

		R[6] = x % (1LL << 7);

		x -= R[6];

		x /= (1LL << 7);

		R[5] = x % (1LL << 10);

		x -= R[5];
		R[4] = x / (1LL << 10);

		cout << 50 << endl;

		cin >> x;

		FOR (i, 4, 6) {
			x -= (1LL << (50 / i)) * R[i]; 
		}

		x /= (1LL << 16);

		R[3] = x % (1LL << 9);

		x -= R[3];

		x /= (1LL << 9);
 
		R[2] = x % (1LL << 25);

		x -= R[2];

		R[1] = x / (1LL << 25);

		FOR (i, 1, 6) cout << R[i] << " ";
		cout << endl;

		int verd;
		cin >> verd;

		if (verd == -1) return 0;  
	}


    return 0;
}