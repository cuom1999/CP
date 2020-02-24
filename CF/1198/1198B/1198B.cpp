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

const int MAXN = 200005;

int last[MAXN];
int money[MAXN];
vector<int> event2;
int a[MAXN], ma[MAXN];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n, q;
	cin >> n;

	FOR (i, 1, n) {
		cin >> money[i];
	}
	cin >> q;
	FOR (i, 1, q) {
		int t;
		cin >> t;

		if (t == 1) {
			int p, x;
			cin >> p >> x;
			last[p] = i;
			money[p] = x;
		}
		else {
			int p;
			cin >> p;
			event2.pb(i);
			a[event2.size()] = p;
		}
	}

	int m = event2.size();

	ma[m] = a[m];

	FORD (i, m - 1, 1) {
		ma[i] = max(ma[i + 1], a[i]);
	}

	FOR (i, 1, n) {
		int l = lower_bound(all(event2), last[i]) - event2.begin() + 1;
		cout << max(ma[l], money[i]) << " ";
	}




	return 0;
}