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
#define sz(M) (int) M.size()

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > II;
typedef pair < II, ll > III;

const int MAXN = 1000005; 
ll x[MAXN], y[MAXN], a[MAXN];
vector<III> V;
vector<III> P;

ll d[1000005];
class hull_optimizer {
	struct line {
		long long m, b, value;
		double xlo;
		bool is_query, query_max;

		line(long long m, long long b, long long v, bool is_query, bool query_max)
		: m(m), b(b), value(v), xlo(-std::numeric_limits<double>::max()),
		is_query(is_query), query_max(query_max) {}

		double intersect(const line &l) const {
			if (m == l.m) {
				return std::numeric_limits<double>::max();
			}
			return (double)(l.b - b)/(m - l.m);
		}

		bool operator<(const line &l) const {
			if (l.is_query) {
				return query_max ? (xlo < l.value) : (l.value < xlo);
			}
			return m < l.m;
		}
	};

	std::set<line> hull;
	bool query_max;

	typedef std::set<line>::iterator hulliter;

	bool has_prev(hulliter it) const {
		return it != hull.begin();
	}

	bool has_next(hulliter it) const {
		return (it != hull.end()) && (++it != hull.end());
	}

	bool irrelevant(hulliter it) const {
		if (!has_prev(it) || !has_next(it)) {
			return false;
		}
		hulliter prev = it, next = it;
		--prev;
		++next;
		return query_max ? (prev->intersect(*next) <= prev->intersect(*it))
		: (next->intersect(*prev) <= next->intersect(*it));
	}

	hulliter update_left_border(hulliter it) {
		if ((query_max && !has_prev(it)) || (!query_max && !has_next(it))) {
			return it;
		}
		hulliter it2 = it;
		double value = it->intersect(query_max ? *--it2 : *++it2);
		line l(*it);
		l.xlo = value;
		hull.erase(it++);
		return hull.insert(it, l);
	}

public:
	hull_optimizer(bool query_max = false) : query_max(query_max) {}

	void add_line(long long m, long long b) {
		line l(m, b, 0, false, query_max);
		hulliter it = hull.lower_bound(l);
		if (it != hull.end() && it->m == l.m) {
			if ((query_max && it->b < b) || (!query_max && b < it->b)) {
				hull.erase(it++);
			} else {
				return;
			}
		}
		it = hull.insert(it, l);
		if (irrelevant(it)) {
			hull.erase(it);
			return;
		}
		while (has_prev(it) && irrelevant(--it)) {
			hull.erase(it++);
		}
		while (has_next(it) && irrelevant(++it)) {
			hull.erase(it--);
		}
		it = update_left_border(it);
		if (has_prev(it)) {
			update_left_border(--it);
		}
		if (has_next(++it)) {
			update_left_border(++it);
		}
	}

	long long query(long long x) const {
		line q(0, 0, x, true, query_max);
		hulliter it = hull.lower_bound(q);
		if (query_max) {
			--it;
		}
		return it->m*x + it->b;
	}
};

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;
	FOR (i, 1, n) {
		ll x, y, c;
		cin >> x >> y >> c;
		V.pb(III(II(x, y), c));
	}

	sort(all(V));
	for (auto i: V) {
		while (P.size() && P.back().first.second <= i.first.second) {
			P.pop_back();
		}
		P.pb(i);
	}
	n = P.size();

	FOR (i, 1, n) {
		x[i] = P[i - 1].first.first;
		y[i] = P[i - 1].first.second;
		a[i] = P[i - 1].second;
	}
	hull_optimizer ch(1);

	ch.add_line(0, 0);

	FOR (i, 1, n) {
		d[i] = ch.query(y[i]) + x[i] * y[i] - a[i];
		ch.add_line(-x[i], d[i]);
		//cout << i << " " << d[i] << endl;
		//cout << i << " " << d[i] << " " << M.size() << " " << pointer << endl;
	}

	ll res = 0;
	FOR (i, 1, n) res = max(res, d[i]);
	cout << res << endl;

	return 0;
}