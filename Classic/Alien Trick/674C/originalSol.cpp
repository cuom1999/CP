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

ld a[200005], s[200005], f[200005], u[200005];
ld d[200005][55];

ld cost(int i, int j) {
	return f[j] - f[i - 1] - s[i - 1] * (u[j] - u[i - 1]);
}

void compute(int k, int l, int r, int optL, int optR) {
	if (l > r) {
		return;
	}

	int m = (l + r) / 2;

	d[m][k] = 1e18;
	int optM = -1;

	FOR (i, optL, min(m - 1, optR)) {
		ld val = d[i][k - 1] + cost(i + 1, m);
		if (d[m][k] > val) {
			d[m][k] = val;
			optM = i;
		}
	}

	compute(k, l, m - 1, optL, optM);
	compute(k, m + 1, r, optM, optR);
}


int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	FOR (i, 1, n) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
		f[i] = f[i - 1] + s[i] / a[i];
		u[i] = u[i - 1] + 1 / a[i];
 	}

 	FOR (i, 1, n) {
 		d[i][1] = cost(1, i);
 	}

 	FOR (i, 2, k) {
 		compute(i, 1, n, 0, n);
 	}

 	cout << fixed << setprecision(8) << d[n][k] << endl;


	return 0;
}