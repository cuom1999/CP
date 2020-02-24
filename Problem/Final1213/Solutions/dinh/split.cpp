#include <bits/stdc++.h>

#define ld long double
#define sf scanf
#define pf printf
#define pb push_back
#define mp make_pair
#define PI ( acos(-1.0) )
#define IN freopen("split.inp","r",stdin)
#define OUT freopen("split.out","w",stdout)
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

int cnt[10005];
ll res;
int a[30005];
int L = 1, R;

void add(int x) {
	res += cnt[x];
	cnt[x]++;
}

void remove(int x) {
	cnt[x]--;
	res -= cnt[x];
}

ll calc(int l, int r) {
	while (R < r) {
		R++;
		add(a[R]);
	}
	while (L > l) {
		L--;
		add(a[L]);
	} 
	while (L < l) {
		remove(a[L]);
		L++;
	}
	while (R > r) {
		remove(a[R]);
		R--;
	}
	return res;
}

ll d[125][30005];

void dp(int k, int l, int r, int optL, int optR) {
	if (r < l) return;
	int optM = -1;
	int mid = (l + r) / 2;
	d[k][mid] = 1e18;
	for (int i = optL; i < mid && i <= optR; i++) {
		ll Q = d[k - 1][i] + calc(i + 1, mid);
		if (d[k][mid] > Q) {
			d[k][mid] = Q;
			optM = i;
		}
	}
	dp(k, l, mid - 1, optL, optM);
	dp(k, mid + 1, r, optM, optR);
}

int main()
{
	IN; OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    FOR (i, 1, n) cin >> a[i];
	FOR (i, 1, n) {
		d[1][i] = calc(1, i);
	}
	FOR (i, 2, k) dp(i, 1, n, 0, n);
	cout << d[k][n] << endl;

    return 0;
}