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

struct Point {
	int x, y;
} p[200005];

int fen[200005], dd[200005];

void add(int u, int v) {
	for (int i = u; i <= 200000; i += i & -i) {
		fen[i] += v;
	}
}

int getSum(int u) {
	int res = 0;
	for (int i = u; i; i -= i & -i) {
		res += fen[i];
	}
	return res;
}

ll c2(int x) {
	return x * 1ll * (x + 1) / 2;
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin >> n;

	FOR (i, 1, n) {
		cin >> p[i].x >> p[i].y;
	}

	vector<II> valX;
	FOR (i, 1, n) {
		valX.pb({p[i].x, i});
	}

	sort(all(valX));
	int C = 0;
	for (int i = 0; i < valX.size(); i++) {
		if (!i || valX[i].first != valX[i - 1].first) C++;
		p[valX[i].second].x = C;
	}

	sort(p + 1, p + n + 1, [](Point &a, Point &b) {
		if (a.y == b.y) return a.x < b.x;
		return a.y > b.y;
	});

	int pos = 1;
	ll res = 0;

	while (pos <= n) {
		vector<int> v;
		v.pb(0);
		
		if (!dd[p[pos].x]) add(p[pos].x, 1);
		dd[p[pos].x] = 1;
		v.pb(p[pos].x);

		while (pos <= n && p[pos + 1].y == p[pos].y) {
			pos++;

			if (!dd[p[pos].x]) add(p[pos].x, 1);
			dd[p[pos].x] = 1;
			v.pb(p[pos].x);
		}

		v.pb(n + 1);

		// for (auto i: v) cout << i << " "; cout << endl;

		int sz = getSum(n);	
		ll sum = 0;

		for (int i = 0; i + 1 < v.size(); i++) {
			sum += c2(getSum(v[i + 1] - 1) - getSum(v[i]));
		}
		res += sz * 1ll * (sz + 1) / 2 - sum;
		pos++;
 	}

 	cout << res << endl;
	return 0;
}