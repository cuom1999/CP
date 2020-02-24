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

int n, k;
ll A, B;
vector<int> v;

int calc(int l, int r) {
	int u = upper_bound(all(v), r) - upper_bound(all(v), l - 1);
	return u;
}

ll solve(int l, int r) {
	ll u = calc(l, r);
	if (u == 0) return A;
	if (l == r) return B * u;

	int mid = (l + r) / 2;
	ll val = min(solve(l, mid) + solve(mid + 1, r), B * u * (r - l + 1));
	return val;
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	cin >> n >> k >> A >> B;

	FOR (i, 1, k) {
		int x;
		cin >> x;
		v.pb(x);
	}    

	sort(all(v));

	cout << solve(1, (1 << n)) << endl;


	
    return 0;
}