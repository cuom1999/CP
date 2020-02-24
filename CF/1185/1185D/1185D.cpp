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
typedef pair < ll, ll > pll;

int b[200005], a[200005];

bool check(vector<int> &v) {
	if (v.size() == 1) return 1;
	int d = v[1] - v[0];

	for (int i = 1; i < v.size(); i++) {
		if (v[i] - v[i - 1] != d) return 0;
	}
	return 1;
}

bool checkIndex(int k, int n) {
	vector<int> v;
	FOR (i, 1, n) {
		if (i != k) {
			v.pb(b[i]);
		}
	}

	return check(v);
}
int res;
void print(int n) {
	FOR (i, 1, n) {
		if (a[i] == res) {
			cout << i << endl;
			return;
		}
	}
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin >> n;

	FOR (i, 1, n) {
		cin >> b[i];
		a[i] = b[i];
	}

	sort(b + 1, b + n + 1);

	res = INF + 1;

	FOR (i, 1, 2) {
		if (checkIndex(i, n)) {
			res = b[i];
			break;
		}
	}

	if (res < INF + 1) {
		print(n);
		return 0;
	}

	int d = b[2] - b[1];

	FOR (i, 2, n) {
		if (b[i] - b[i - 1] != d) {
			if (checkIndex(i, n)) {
				res = b[i];
				print(n);
				return 0;
			}
			else {
				cout << -1;
				return 0;
			}
		}
	}

	cout << 1 << endl;
	return 0;
}