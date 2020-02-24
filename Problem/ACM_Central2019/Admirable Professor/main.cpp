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

// Given m people and m candy bags. 
// m people are divided into n equal groups.
// Number of candies in m bags are a[1]->a[m]
// Each person takes one bag
// Each group will sum all their bags and divide equally to their member
// The remaining candies in each group will be returned to Oo
// What is the min candies Oo can have? Print a way to achieve 
// Input: m g
// a[1] a[2] ... a[m]
// m <= 5*10^4, m mod g = 0

int a[50005], trace[50005]; // trace[i] = min divisor of i
vector<int> v[50005];
vector<int> res[50005];

void sieve() {
	int n = 50000;
	for (int i = 2; i <= n; i++) {
		if (trace[i]) continue;
		for (int j = 1; j * i <= n; j++) {
			if (!trace[i * j]) trace[i * j] = i;
		}
	}
}

// check if there are n equal-when-mod-n numbers
bool processEasyCase(vector<int>& res, vector<int>& bag, int n) {
	vector< vector<int> > r(n);
	for (auto i: bag) {
		r[i % n].pb(i);
	}

	int index = -1;
	FOR (i, 0, n - 1) {
		if (r[i].size() >= n) {
			index = i;
			break;
		} 
	}
	bag.clear();
	FOR (i, 0, n - 1) {
		for (auto j: r[i]) bag.pb(j);
	}
	if (index == -1) return 0;

	bag.clear();

	FOR (i, 0, n - 1) {
		if (i == index) {
			for (int j = 0; j < r[i].size(); j++) {
				if (j <= n - 1) {
					res.pb(r[i][j]);
				}
				else {
					bag.pb(r[i][j]);
				}
			}
		}
		else {
			for (auto j: r[i]) {
				bag.pb(j);
			}
		}
	}
	return 1;
}

// n has to be prime
// prime case: use Cauchy-Davenport lemma idea
void dividePrime(vector<int>& res, vector<int>& bag, int n) {
	if (processEasyCase(res, bag, n)) return;

	vector< vector<int> > bucket(n);
	vector<int> remain;

	for (int i = 0; i < bag.size(); i++) {
		bucket[i % n].pb(bag[i]);
	}

	bitset<25000> bs[n][2];

	FOR (i, 0, 1) bs[0][i][bucket[0][i] % n] = 1;

	FOR (i, 1, n - 1) {
		for (int j = 0; j < bucket[i].size(); j++) {
			int u = bucket[i][j] % n;
			FOR (k, 0, 1) {
				bs[i][j] |= (bs[i - 1][k] << u);
				bs[i][j] |= (bs[i - 1][k] >> (n - u));
			}
		}
	}
	assert(bs[n - 1][0][0] == 1);
	int chosen = 0;
	int val = 0;
	
	res.pb(bag[n - 1]);

	FORD (i, n - 1, 1) {
		int u = bucket[i][chosen] % n;

		val = (val + n - u) % n;
		if (bs[i - 1][0][val]) {
			chosen = 0;
		}
		else {
			chosen = 1;
		}
		remain.pb(bag[(chosen ^ 1) * n + i - 1]);
		res.pb(bag[chosen * n + i - 1]);
	} 
	bag = remain;
} 

// general case 
// use multiplicative idea
void divide(vector<int>& res, vector<int>& bag, int n) {
	if (processEasyCase(res, bag, n)) {
		return;
	}
	if (n == trace[n]) {
		dividePrime(res, bag, n);
		return;
	}


	int a = trace[n];
	int b = n / a;

	vector<int> curBag;
	vector< vector<int> > bucket(2 * b - 1);

	int cur = 0;

	FOR (i, 0, 2 * b - 2) {
		while (curBag.size() < 2 * a - 1) {
			curBag.pb(bag[cur]);
			cur++;
		}

		divide(bucket[i], curBag, a);
	}
	bag = curBag;

	vector< vector<int> > bucketOfRemainder(b);
	vector<int> bucketForB;

	FOR (i, 0, 2 * b - 2) {
		ll sum = 0;
		for (auto j: bucket[i]) {
			sum += j;
		}
		ll val = (sum / a) % b;
		bucketOfRemainder[val].pb(i);
		bucketForB.pb(val);
	}

	vector<int> resB;
	divide(resB, bucketForB, b);

	for (auto i: resB) {
		int u = bucketOfRemainder[i].back();
		bucketOfRemainder[i].pop_back();

		for (auto j: bucket[u]) {
			res.pb(j);
		}
	}
	for (auto i: bucketForB) {
		int u = bucketOfRemainder[i].back();
		bucketOfRemainder[i].pop_back();

		for (auto j: bucket[u]) {
			bag.pb(j);
		}	
	}
}


int main()
{//IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	sieve();

	int m, g, n;
	cin >> n >> g;
    m = n * g;

	int ans = 0;

	FOR (i, 1, m) {
		cin >> a[i];
		v[a[i] % n].pb(a[i]);
		ans = (ans + a[i]) % n;
	}

	int group = 0;

	// simplify all vectors by grouping n numbers in a vector
	FOR (i, 0, n - 1) {
		int sz = v[i].size();
		FOR (j, 1, sz / n) {
			group++;
			FOR (k, 0, n - 1) {
				res[group].pb(v[i][n * (j - 1) + k]);
			}
		}

		reverse(all(v[i]));
		FOR (j, 1, (sz / n) * n) {
			v[i].pop_back();
		}
	}

	vector<int> allBag;
	FOR (i, 0, n - 1) {
		for (auto j: v[i]) allBag.pb(j);
	}
	
	// start algorithm
	vector<int> bag;
	int cur = 0;		
	while (group < g - 1) {
		group++;
		while (bag.size() < 2 * n - 1) {
			bag.pb(allBag[cur]);
			cur++;
		}

		divide(res[group], bag, n);
	}

	// the final remaining bags
	if (group < g) {
		group++;
		for (int i = cur; i < allBag.size(); i++) {
			bag.pb(allBag[i]);
		}
		res[group] = bag;
	}

	cout << ans << endl;

	FOR (i, 1, g) {
		for (auto j: res[i]) cout << j << " ";
		cout << "\n";
	}
	return 0;
}