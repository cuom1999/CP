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

int n, BLOCK_SIZE;
int a[30005];

vector<int> block[1000];

void build() {
	FOR (i, 1, n) {
		block[(i - 1) / BLOCK_SIZE].pb(a[i]);
	}
	FOR (i, 0, (n - 1) / BLOCK_SIZE) {
		sort(all(block[i]));
	}
}

void update(int i, int v) {
	int blockPos = (i - 1) / BLOCK_SIZE;

	for (auto j = block[blockPos].begin(); j != block[blockPos].end(); j++) {
		if (*j == a[i]) {
			block[blockPos].erase(j);
			break;
		}
	}

	int newPos = lower_bound(all(block[blockPos]), v) - block[blockPos].begin();
	block[blockPos].insert(block[blockPos].begin() + newPos, v);
	a[i] = v;
}

int getAns(int i, int j, int k) {
	int firstBlock = (i - 1) / BLOCK_SIZE;
	int lastBlock = (j - 1) / BLOCK_SIZE;

	int res = 0;
	if (firstBlock == lastBlock) {
		FOR (u, i, j) {
			if (a[u] > k) res++;
		}
		return res;
	}
	else {
		FOR (u, firstBlock + 1, lastBlock - 1) {
			res += block[u].end() - upper_bound(all(block[u]), k);
		}
		FOR (u, i, (firstBlock + 1) * BLOCK_SIZE) {
			if (a[u] > k) res++;
		}
		FOR (u, lastBlock * BLOCK_SIZE + 1, j) {
			if (a[u] > k) res++;
		}
		return res;
	}
}

int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	scanf("%d", &n);
	BLOCK_SIZE = sqrt(log2(200000)) * sqrt(n);
	FOR (i, 1, n) {
		scanf("%d", &a[i]);
	}

	build();

	int q;
	scanf("%d", &q);

	FOR (z, 1, q) {
		int type;
		scanf("%d", &type);

		if (type == 0) {
			int i, v;
			scanf("%d%d", &i, &v);
			update(i, v);
		}
		else {
			int i, j, k;
			scanf("%d%d%d", &i, &j, &k);
			printf("%d\n", getAns(i, j, k));
		}
	}


	return 0;
}