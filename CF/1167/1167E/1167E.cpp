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
const int MAXN = 1000005;

int n, x;
int a[1000005], firstOcc[MAXN], lastOcc[MAXN];
int lastHead[MAXN], firstTail[MAXN];
ll fen[MAXN];

void add(int u, int v) {
	for (int i = u; i <= MAXN - 1; i += i & -i) {
		fen[i] += v;
	}
}

ll getSum(int u) {
	ll res = 0;
	for (int i = u; i; i -= i & -i) {
		res += fen[i];
	}
	return res;
}

ll getSum(int u, int v) {
	if (u > v) return 0;
	if (u == 0) return getSum(v);
	return getSum(v) - getSum(u - 1);
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> x;

	int minVal = INF, maxVal = 0;
	int maxHead = x - 1, maxTail = 2;

	FOR (i, 1, n) {
		cin >> a[i];
		if (!firstOcc[a[i]]) {
			firstOcc[a[i]] = i;
		}
		lastOcc[a[i]] = i;
		minVal = min(minVal, a[i]);
		maxVal = max(maxVal, a[i]);
	}

	FOR (i, minVal, maxVal) {
		if (!firstOcc[i] || firstOcc[i] > lastHead[i - 1]) {
			if (lastOcc[i]) lastHead[i] = lastOcc[i];
			else lastHead[i] = lastHead[i - 1];
		}
		else {
			maxHead = i - 1;
			break;
		}
	}
	firstTail[maxVal + 1] = n + 1;

	FORD (i, maxVal, minVal) {
		if (lastOcc[i] < firstTail[i + 1]) {
			if (firstOcc[i]) firstTail[i] = firstOcc[i];
			else firstTail[i] = firstTail[i + 1];
		}
		else {
			maxTail = i + 1;
			break;
		}
	}

	FOR (i, 0, minVal - 1) lastHead[i] = -1;
	FOR (i, 1, x - 1) if (!lastHead[i]) lastHead[i] = n;

	FORD (i, x + 1, maxVal + 1) firstTail[i] = n + 1;

	ll res = 0;

	// [1, i] and [j, x] (i + 1 < j), del [i + 1, j - 1] (0 <= i, j <= x + 1)

	// cout << lastHead[1] << endl;
	// cout << firstTail[4] << endl;

	// cout << maxTail << endl;

	FORD (i, x - 1, 0) {
		if (i + 2 >= maxTail) add(firstTail[i + 2] + 1, 1);
		if (i <= maxHead) res += (ll) getSum(lastHead[i] + 2, n + 2);
	}


	cout << res << endl;
	return 0;
}
