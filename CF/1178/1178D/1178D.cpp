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

bool isPrime(int n) {
	if (n == 1) return 0;
	for (int i = 2; i <= n / i; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

vector<II> edges;

vector<II> createEdges(vector<int> &v, int numEdges) {
	vector<II> cur;
	for (int i = 0; i + 1 < v.size(); i++) {
		cur.pb({v[i], v[i + 1]});
	}
	cur.pb({v.back(), v[0]});

	if (v.size() == 4) {
		if (numEdges == 4) return cur;

		cur.pb({v[0], v[2]});
		if (numEdges == 5) {
			return cur;
		}

		cur.pb({v[1], v[3]});
		return cur;
	}
	else {
		return cur;
	}
} 

void solve(int n, int numEdges) {
	if (n == 0) return;
	int a[1005];

	FOR (i, 0, n / 4 - 1) {
		a[i] = 4;
		numEdges -= 4;
	}

	FOR (i, 0, n / 4 - 1) {
		if (numEdges >= 2) {
			numEdges -= 2;
			a[i] += 2;
		}
		else if (numEdges == 1) {
			numEdges--;
			a[i]++;
		}
		else break;
	}

	FOR (i, 0, n / 4 - 1) {
		vector<int> v;
		FOR (j, i * 4 + 1, i * 4 + 4) {
			v.pb(j);
		}
		vector<II> cur = createEdges(v, a[i]);
		for (auto j: cur) {
			edges.pb(j);
		}
	}
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	if (n == 3) {
		vector<int> v = {1, 2, 3};
		edges = createEdges(v, 3);
	}
	else if (n == 6) {
		vector<int> v = {1, 2, 3, 4, 5, 6};
		edges = createEdges(v, 6);

		edges.pb({1, 3});
	}
	else {
		int numEdges = 0;
		FOR (i, n, 3 * n / 2) {
			if (isPrime(i)) {
				numEdges = i;
				break;
			}
		}
		
		if (n % 4 == 0) {
			solve(n, numEdges);
		}
		if (n % 4 == 1) {
			solve(n - 5, numEdges - 5);
			vector<int> v;
			FOR (i, n - 4, n) v.pb(i);
			vector<II> cur = createEdges(v, 5);
			for (auto i: cur) edges.pb(i);
		}
		if (n % 4 == 2) {
			solve(n - 6, numEdges - 6);
			vector<int> v;
			FOR (i, n - 5, n) v.pb(i);
			vector<II> cur = createEdges(v, 6);
			for (auto i: cur) edges.pb(i);
		}
		if (n % 4 == 3) {
			solve(n - 3, numEdges - 3);
			vector<int> v;
			FOR (i, n - 2, n) v.pb(i);
			vector<II> cur = createEdges(v, 3);
			for (auto i: cur) edges.pb(i);	
		}
	}

	cout << edges.size() << endl;

	int d[1005];
	memset(d, 0, sizeof(d));
	for (auto i: edges) {
		cout << i.first << " " << i.second << endl;
		d[i.first]++;
		d[i.second]++;
	}

	// FOR (i, 1, n) cout << d[i] << " ";

	return 0;
}