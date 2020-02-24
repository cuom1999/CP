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

using namespace std;

typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

struct data {
	int s, f, r;
	ll c;
	data(){}
	data(int __s, int __f, ll __c, int __r) {
		s = __s;
		f = __f;
		c = __c;
		r = __r;
	}
};

vector<data> trucks;

int n, m;
ll a[250005], c[250005];
int s[250005], f[250005], r[250005];

bool check(int i, ll V) {
	int pos = s[i];
	int R = r[i];
	int initPos = pos;
	while (pos <= f[i] && R >= 0) {
		ll u = V / c[i];
		int dist = a[pos];
		while (dist + u >= a[pos] && pos <= f[i]) pos++;
		pos--;
		if (pos == initPos) break;
		R--;
	}
	if (pos == f[i]) return 1;
	return 0;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    srand(time(NULL));
	cin >> n >> m;
	FOR (i, 1, n) cin >> a[i];
	FOR (i, 1, m)  {
		int s, f, r;
		ll c;
		cin >> s >> f >> c >> r;
		trucks.pb(data(s, f, c, r));
	}
	random_shuffle(all(trucks));

	int C = 0;
	for (auto i: trucks) {
		C++;
		s[C] = i.s;
		f[C] = i.f;
		c[C] = i.c;
		r[C] = i.r;
	}
	
	ll res = 0;
	//cout << check(1, 100000) << endl;
	//return 0;

	FOR (i, 1, m) {
		if (!check(i, res)) {
			ll L = res + 1, R = 1e18 + 10;
			while (L < R) {
				ll mid = (L + R) / 2;
				if (check(i, mid)) {
					R = mid;
				}
				else L = mid + 1;
			}
			res = L;
			//cout << i << " " << L << endl;
		}
	}
	cout << res << endl;

	
    return 0;
}