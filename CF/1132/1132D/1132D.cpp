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

int n;
ll k;
ll a[200005], b[200005];
ll s[200005];

bool solve(ll x) {

	FOR (i, 1, k) s[i] = 0;

	FOR (i, 1, n) {
		ll val = a[i];
		int cnt = 0;
		while (val / b[i] < k - 1 && cnt <= k - 1) {
			cnt++;

			s[val / b[i] + 1]++;

			val += x;
		}
	}

	FOR (i, 1, k - 1) {
		s[i] += s[i - 1];
		if (s[i] > i) return 0;
	}


	return 1;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> n >> k;

    FOR (i, 1, n) cin >> a[i];

    FOR (i, 1, n) cin >> b[i];
	
    ll L = 0, R = 1e18;

    while (L < R) {
    	ll mid = (L + R) / 2;
    	if (solve(mid)) {
    		R = mid;
    	}
    	else {
    		L = mid + 1;
    	}
    }


    if (solve(L)) {
    	cout << L << endl;
    }
    else {
    	cout << -1 << endl;
    }

    return 0;
}