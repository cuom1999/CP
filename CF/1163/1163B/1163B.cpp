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

int num[100005], val[100005];
set<int> s, s1;

bool check() {
	// for (auto i: s) cout << i << " "; cout << endl;
	// cout << val[1] << " " << val[2] << endl;
	if (s.size() == 2) {
		if (val[1] == 1) {
			return 1;
		}
		else {
			int u = *s.begin();
			if (val[u + 1] == 1) return 1;
		}
	}
	if (s.size() == 1 && val[1]) return 1;
	if (s1.size() == 1) return 1;
	return 0;
}
int a[100005];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	FOR (i, 1, n) {
		cin >> a[i];
	}

	int res = 1;
	FOR (i, 1, n) {
		num[a[i]]++;
		s1.insert(a[i]);
		int u = num[a[i]];
		val[u]++;
		val[u - 1]--;
		if (!val[u - 1] && u > 1) {
			s.erase(u - 1);
		}
		s.insert(u);
		// if (i == 5) cout << "! " << u << " " << val[u] << endl; 
		// if (check()) cout << i << " ";
		// if (i == 5) return 0;

		if (check()) {
			res = i;
		}
	}
	cout << res << endl;



	return 0;
}