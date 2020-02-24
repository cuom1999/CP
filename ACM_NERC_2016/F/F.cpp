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

typedef pair < ld, int > DI;
typedef pair < int, int > II;

ll x[1005], y[1005];

ld a[1005], b[1005];

priority_queue< DI, vector<DI>, greater<DI> > pq;
ll w;
int n;

ld dist(int i, int j) {
	if (i > j) swap(i, j);
	if (i == 0) {
		if (j == n + 1) return w;
		return x[j];
	}
	if (j == n + 1) {
		return w - x[i];
	}
	return sqrt(sq(x[i] - x[j]) + sq(y[i] - y[j]));
}

void dijsktra(int a, ld d[1005]) {
	FOR (i, 1, n) {
		d[i] = dist(a, i);
		pq.push({d[i], i});
	}

	while (pq.size()) {
		auto u = pq.top();
		pq.pop();

		if (d[u.second] != u.first) continue;
		FOR (i, 1, n) {
			if (i == u.second) continue;
			// cout << u.second << " " << u.first << " " << i << " " << d[i] << endl;
			if (d[i] > max(d[u.second], dist(u.second, i))) {
				d[i] = max(d[u.second], dist(u.second, i));
				pq.push({d[i], i}); 
			}
		}
	}
}

int main()
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout << fixed << setprecision(5);
	cin >> w >> n;

	FOR (i, 1, n) {
		cin >> x[i] >> y[i];
	}
	x[n + 1] = w;

	dijsktra(0, a);
	dijsktra(n + 1, b);


	ld minVal = 1e18;
	II res = {0, 0};

	a[n + 1] = w;
	b[0] = w;


 	FOR (i, 0, n) {
		FOR (j, i + 1, n + 1) {
			ld val = max(a[i], b[j]);
			val = max(val, dist(i, j) / 2.0);
			// cout << i << " " << j << " " << val << endl;

			if (val < minVal) {
				minVal = val;
				res = {i, j};
			}

			val = max(a[j], b[i]);
			val = max(val, dist(i, j) / 2.0);

			if (val < minVal) {
				minVal = val;
				res = {i, j};
			}
			// cout << i << " " << j << " " << val << endl;
		}
	}

	int X = res.first, Y = res.second;
	if (X > Y) swap(X, Y);

	if (X == 0) {
		if (Y == n + 1) {
			cout << w / 2.0 << " " << 0 << endl;
		}
		else {
			cout << x[Y] / 2.0 << " " << y[Y] << endl; 
		}
	}
	else if (Y == n + 1) {
		cout << (w + x[X]) / 2.0 << " " << y[X] << endl;
	}
	else {
		cout << (x[X] + x[Y]) / 2.0 << " " << (y[X] + y[Y]) / 2.0 << endl;
	}
	// cout << setprecision(5) << (x[res.first] + x[res.second]) / 2.0 << " " << (y[res.first] + y[res.second]) / 2.0 << endl;
	// cout << dist(1, 6) << " " << dist(2, 6) << endl;

	return 0;
}