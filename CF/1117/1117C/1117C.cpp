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

ll x1, x2, y1, y2;
string wind;
int n;

char direction[505];
ll x[4] = {0, 0, -1, 1};
ll y[4] = {1, -1, 0, 0};

bool solve(ll res) {
	ll oldRes = res;
	ll x3 = 0, y3 = 0;
	FOR (i, 1, n) {
		x3 += x[direction[wind[i]]];
		y3 += y[direction[wind[i]]];
	}

	x3 *= (res / n);
	y3 *= (res / n);

	res %= n;

	FOR (i, 1, res) {
		x3 += x[direction[wind[i]]];
		y3 += y[direction[wind[i]]];
	}

	ll t = abs(x2 - x1 - x3) + abs(y2 - y1 - y3);

	return (t <= oldRes);
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    direction['U'] = 0;
	direction['D'] = 1;
    direction['L'] = 2;
    direction['R'] = 3;


    cin >> x1 >> y1 >> x2 >> y2;
    cin >> n;
    cin >> wind;

    wind = '0' + wind;

    ll L = 0, R = 1e15;

    while (L < R) {
    	ll mid = (L + R) / 2;
    	if (solve(mid)) {
    		R = mid;
    	}
    	else {
    		L = mid + 1;
    	}
    }

    //cout << L << endl;
    if (!solve(L)) {
    	cout << -1 << endl;
    }
    else {
    	cout << L << endl;
    }


	
    return 0;
}