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

vector<ll> v;
ll p[100005];
bool over[100005];

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int l;
	cin >> l;
	ll prod = 1;
	ll res = 0;
	p[0] = 1;
	ll MAXN = (1LL << 32) - 1;
	FOR (z, 1, l) {
		string s;
		cin >> s;
		if (s[0] == 'f') {
			ll n;
			cin >> n;
			v.pb(n);
			int m = v.size();
			p[v.size()] = p[v.size() - 1] * n;
			over[m] = over[m - 1];
			if (!over[m]) {
				if (p[m] > MAXN) over[m] = 1;
			}
		}
		else if (s[0] == 'a') {
			int m = v.size();
			if (over[m]) {
				cout << "OVERFLOW!!!";
				return 0;
			}
			res += p[m];
			if (res > MAXN) {
				cout << "OVERFLOW!!!";
				return 0;
			}
		}
		else {
			over[v.size()] = 0;
			v.pop_back();
		}
	}

	cout << res << endl;


	return 0;
}