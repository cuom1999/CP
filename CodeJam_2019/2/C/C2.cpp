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

II a[15];

// return continued fraction of a / b
vector<int> contFraction(ll a, ll b) {
	vector<int> res;
	while (b) {
		res.pb(a / b);
		a %= b;
		swap(a, b);
	}
	return res;
}

// return fraction form of continued fraction
void computeFraction(vector<int> &contFraction, ll &a, ll &b) {
	vector<int> tmp = contFraction;
	reverse(all(tmp));

	a = tmp[0];
	b = 1;
	for (int i = 1; i < tmp.size(); i++) {
		swap(a, b);
		a += tmp[i] * b;
	}
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	FOR (z, 1, t) {

		cout << "Case #" << z << ": ";
		int n;
		cin >> n;

		ll A = 0, B = 1, C = 2e9, D = 1;

		FOR (i, 1, n) {
			cin >> a[i].first >> a[i].second; 
		}

		FOR (i, 1, n) {
			FOR (j, i + 1, n) {
				if (a[i].first > a[j].first && a[i].second < a[j].second) {
					ll u = a[i].first - a[j].first;
					ll v = a[j].second - a[i].second;
					ll g = __gcd(u, v);
					u /= g; v /= g;

					if (A * v < B * u) {
						A = u, B = v;
					}
				}
				else if (a[i].first > a[j].first) {
					C = -1;
					D = 1;
				}
				else if (a[i].first < a[j].first && a[i].second > a[j].second) {
					ll u = a[j].first - a[i].first;
					ll v = a[i].second - a[j].second;
					ll g = __gcd(u, v);
					u /= g; v /= g;

					if (C * v > D * u) {
						C = u, D = v;
					}
				}
				else if (a[i].first == a[j].first && a[i].second > a[j].second) {
					C = -1;
					D = 1;
				}

			}
		}
		cout << A << " " << B << " " << C << " " << D << endl;  
		if (A * D >= B * C) {
			cout << "IMPOSSIBLE" << endl;
		}

		vector<int> smallFrac = contFraction(A, B);
		vector<int> largeFrac = contFraction(C, D);

		smallFrac.resize(50);
		largeFrac.resize(50);

		vector<int> curFrac;
		bool isEqual = 1;

		FOR (i, 0, 20) {
			if (smallFrac[i] == largeFrac[i] && isEqual) {
				curFrac.pb(i);
			}
			else {
				curFrac.pb(smallFrac[i] + 1);
				ll U, V;
				computeFraction(curFrac, U, V);
				cout << V << " " << U << endl;
				curFrac.pop_back();
				curFrac.pb(smallFrac[i]);
				isEqual = 0;
			}
		}
	}

	return 0;
}