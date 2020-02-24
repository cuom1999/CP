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

struct ST {
	const int MAXN = 400005;
	int st[MAXN];
	bool lzFlip[MAXN];
	bool lzSet[MAXN];
	bool lzSetAlready[MAXN];

	ST() {
		FOR (i, 1, 400000) lzSetAlready[i] = 1;
	}

	void down(int id, int l, int r) {
		if (l == r) return;

		if (!lzSetAlready[id]) {
			st[id * 2] = lzSet[id];
			st[id * 2 + 1] = lzSet[id];

			lzSet[id * 2] = lzSet[id];
			lzSet[id * 2 + 1] = lzSet[id];
			lzFlip[id * 2] = lzFlip[id * 2 + 1] = 0;
			
			lzSetAlready[id * 2] = lzSetAlready[id * 2 + 1] = 0;

			lzSetAlready[id] = 1;
		}
		
		st[id * 2] ^= lzFlip[id];
		st[id * 2 + 1] ^= lzFlip[id];

		lzFlip[id * 2] ^= lzFlip[id];
		lzFlip[id * 2 + 1] ^= lzFlip[id];

		lzFlip[id] = 0;
	}

	void updateFlip(int id, int l, int r, int u, int v) {
		if (v < l || r < u || u > v) return;
		if (u <= l && r <= v) {
			st[id] ^= 1;
			lzFlip[id] ^= 1;
			return;
		}

		down(id, l, r);
		int mid = (l + r) / 2;

		updateFlip(id * 2, l, mid, u, v);
		updateFlip(id * 2 + 1, mid + 1, r, u, v);
	}

	void updateSet(int id, int l, int r, int u, int v, int k) {
		if (v < l || r < u || u > v) return;
		if (u <= l && r <= v) {
			st[id] = k;
			lzSet[id] = k;
			lzFlip[id] = 0;
			lzSetAlready[id] = 0;

			return;
		}

		down(id, l, r);
		int mid = (l + r) / 2;

		updateSet(id * 2, l, mid, u, v, k);
		updateSet(id * 2 + 1, mid + 1, r, u, v, k);	
	}

	int getVal(int id, int l, int r, int u) {
		if (l == r) {
			return st[id];
		}
		down(id, l, r);

		int mid = (l + r) / 2;
		if (u <= mid) {
			return getVal(id * 2, l, mid, u);
		}
		return getVal(id * 2 + 1, mid + 1, r, u);
	}
}seg[2];

int a[100005];
const int N = 100000;

int n;
int b[100005];

void printArray() {
	FOR (i, 1, n) {
		int x = abs(a[i]);
		int u = seg[1].getVal(1, 1, N, x) * 2 + seg[0].getVal(1, 1, N, x);

		if (u == 0) {
			b[i] = a[i];
		}
		else if (u == 1) {
			b[i] = -a[i];
		}
		else if (u == 2) {
			b[i] = x;
		}
		else if (u == 3) {
			b[i] = -x;
		}
		// cout << u << " ";
	}
	// cout << endl;

	FOR (i, 1, n) cout << b[i] << " ";
	cout << endl;
}

int main()
{//IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int q;
	cin >> n >> q;

	FOR (i, 1, n) {
		cin >> a[i];
	}

	FOR (z, 1, q) {
		char s;
		int x;
		cin >> s >> x;

		if (s == '<') {
			if (x >= 0) {
    			// 1 -> x-1: flip, x->1e5: 2
				seg[0].updateFlip(1, 1, N, 1, x - 1);
				seg[0].updateSet(1, 1, N, x, N, 0);
				seg[1].updateSet(1, 1, N, x, N, 1); 
			}
			else {
				seg[0].updateSet(1, 1, N, -x + 1, N, 0);
				seg[1].updateSet(1, 1, N, -x + 1, N, 1); 	
			}
		}
		else {
			if (x >= 0) {
				seg[0].updateSet(1, 1, N, x + 1, N, 1);
				seg[1].updateSet(1, 1, N, x + 1, N, 1);
			}
			else {
				seg[0].updateFlip(1, 1, N, 1, -x - 1);
				seg[0].updateSet(1, 1, N, -x, N, 1);
				seg[1].updateSet(1, 1, N, -x, N, 1);
			}
		}
		// cout << seg[1].getVal(1, 1, N, 3) << endl;
		// printArray();

	}

	printArray();
	
	return 0;
}