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

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());

bool solve(vector<II> &a, vector<II> &b) {
	shuffle(all(a), gen);
	shuffle(all(b), gen);

	int gcd1 = 0;
	for (auto i: a) {
		gcd1 = __gcd(gcd1, i.first);
	}

	if (gcd1 != 1) {
		for (int i = 0; i < b.size(); i++) {
			if (!gcd1 || b[i].first % gcd1) {
				a.pb(b[i]);
				b.erase(b.begin() + i);
				break;
			}
		}
	}
	else {
		gcd1 = 0;
		for (auto i: b) {
			gcd1 = __gcd(gcd1, i.first);
		}
		if (gcd1 != 1) {
			for (int i = 0; i < a.size(); i++) {
				if (!gcd1 || a[i].first % gcd1) {
					b.pb(a[i]);
					a.erase(a.begin() + i);
					break;
				}
			}
		}
	}

	gcd1 = 0;
	int gcd2 = 0;
	for (auto i: a) {
		gcd1 = __gcd(gcd1, i.first);
	}
	for (auto i: b) {
		gcd2 = __gcd(gcd2, i.first);
	}
	// cout << a.size() << " " << b.size() << " " << gcd1 << " " << gcd2 << endl;
	// cout << gcd1 << " " << gcd2 << endl;

	return (gcd1 == 1 && gcd2 == 1);
}
int a[100005];
ll Rand(ll l, ll r){
    uniform_int_distribution<ll> rnd(l,r);
    return rnd(gen);
}

int pre[100005];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	srand(time(0));

	int n;
	cin >> n;

	int g = 0;
	FOR (i, 1, n) {
		cin >> a[i];
		g = __gcd(g, a[i]);
	}
	if (g > 1) {
		cout << "NO";
		return 0;
	}

	vector<II> x, y, v;

	FOR (i, 1, n) {
		v.pb({a[i], i});
	}

	sort(all(v));

	for (int i = 0; i < v.size(); i++) {
		if (i >= 2 && v[i].first == v[i - 1].first && v[i - 1].first == v[i - 2].first) {
			pre[v[i].second] = pre[v[i - 1].second];
		}
		else {
			pre[v[i].second] = v[i].second;
		}
	}

	FOR (i, 1, n) {
		if (pre[i] != i) continue;
		if (Rand(0, 1) % 2) {
			x.pb({a[i], i});
		}
		else {
			y.pb({a[i], i});
		}
	}

	int cnt = 5000000 / n;
	// cnt = 20;
	int cur = 0;
	while (cur <= cnt) {
		cur++;
		bool res = solve(x, y);
		if (res) {
			vector<int> ans(n + 1);

			cout << "YES\n";
			for (auto i: x) {
				// cout << i.first << " ";
				ans[i.second] = 1;
			}
			for (auto i: y) {
				// cout << i.first << " ";
				ans[i.second] = 2;
			}
			FOR (i, 1, n) {
				if (!ans[i]) ans[i] = ans[pre[i]];
			}
			FOR (i, 1, n) cout << ans[i] << " ";
			return 0;
		}
	}
	cout << "NO\n";



	return 0;
}