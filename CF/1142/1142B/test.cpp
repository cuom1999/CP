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

const int MAXN = 200005;
int a[MAXN], pos[MAXN], d[MAXN];

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
	int n, m, q;
	cin >> n >> m >> q;

	FOR (i, 1, n) {
		int x;
		cin >> x;
		pos[x] = i;
	}	

	FOR (i, 1, m) {
		int x;
		cin >> x;
		a[i] = pos[x];
	}

	FOR (z, 1, q) {
		int l, r;
		cin >> l >> r;
		
		FOR (i, 1, n) d[i] = 0;
		bool res = 0;
		FOR (i, l, r) {
			int u = a[i] - 1;
			if (!u) u = n;
			d[a[i]] = max(d[a[i]], d[u] + 1);
			if (d[a[i]] >= n) res = 1;
		}

		cout << res;
	}


    return 0;
}