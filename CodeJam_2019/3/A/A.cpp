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
typedef pair < ll, ll > II;

ll m = 1e10;
ll n = 1e12;

// ll m = 10;
// ll n = 50;

set<II> s;
map<ll, ll> d;
		
ll move(ll p, bool mine) {
	auto u = (--s.lower_bound({p, n + 1}));

	s.erase(u);

	ll st = u->first;
	ll len = u->second;

	II u1 = II(st, p - st);
	II u2 = II(p + m, st + len - (p + m));
	if (u1.second >= m) {
		s.insert(u1);
		if (mine) {
			d[u1.first] = u2.first;
			d[u2.first] = u1.first;
		}
	}
	if (u2.second >= m) s.insert(u2);
	return st;
}

int main()
{//IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t, w;
	cin >> t >> w;

	FOR (z, 1, t) {
		s.clear();
		d.clear();
		s.insert({1, n});

		while (1) {
			ll p;
			cin >> p;

			if (p == -1) return 0;
			if (p < 0) break;

			ll u = move(p, 0);

			if (d[u]) {
				ll v = d[u];
				cout << p - u + v << endl;
				move(p - u + v, 0);
				continue;
			}

			bool isDone = 0;

			for (auto i: s) {
				if (!d[i.first] && i.second % 2 == 0) {
					isDone = 1;
					ll nextMove = i.first + (i.second - m) / 2;
					move(nextMove, 1); 
					cout << nextMove << endl;
					break;
				}
			}

			if (!isDone) {
				for (auto i: s) {
					if(!d[i.first]) {
						ll nextMove = i.first;
						move(nextMove, 0);
						cout << nextMove << endl;
						isDone = 1;
						break;
					}
				}
			}

			if (!isDone) {
				ll nextMove = s.begin()->first;
				move(nextMove, 0);
				cout << nextMove << endl;
				d[d[nextMove]] = 0;
			}
			// for (auto i: s) {
			// 	cout << i.first << " " << i.second << endl;
			// }
		}
	}


	return 0;
}