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
typedef pair < ll, ll > II;

ll n, b;
vector<II> divisors;

ll v_p(ll p) {
	ll res = 0;
	ll cur = p;
	FOR (i, 1, 100) {
		res += (n / cur);
		if (cur < 0 || cur > n / p) break;
		cur *= p;
		if (cur < 0 || cur > n) break;
	}
	return res;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> b;

    for (ll i = 2; i <= b / i; i++) {
    	if (b % i == 0) {
    		int cnt = 0;
    		while (b % i == 0) {
    			b /= i;
    			cnt++;
    		}
    		divisors.pb(II(i, cnt));
    	}
    }

    if (b > 1) divisors.pb(II(b, 1));

	ll res = 1e18;
	for (auto i: divisors) {
		ll val = v_p(i.first) / i.second;
		res = min(res, val);
	}
	cout << res << endl;


    return 0;
}