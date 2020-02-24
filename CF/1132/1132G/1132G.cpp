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

const int MAXN = 1000005;

int a[1000005];
int p[1000005], tin[MAXN], tout[MAXN];

vector<int> decreaseSeq, v[1000005], eulerTour;

void dfs(int a) {
	tin[a] = eulerTour.size();
	eulerTour.pb(a);

	for (auto i: v[a]) {
		dfs(i);
	}
	
	tout[a] = eulerTour.size();
	eulerTour.pb(a);
}

int st[MAXN * 8], lz[MAXN * 8];

void down(int id, int l, int r) {
	if (l == r || !lz[id]) return;

	st[id * 2] += lz[id];
	lz[id * 2] += lz[id];
	
	st[id * 2 + 1] += lz[id];
	lz[id * 2 + 1] += lz[id];

	lz[id] = 0;
}

void update(int id, int l, int r, int u, int v, int k) {
	if (v < l || r < u) return;
	if (u <= l && r <= v) {
		st[id] += k;
		lz[id] += k;
		return;
	}

	int mid = (l + r) / 2;
	down(id, l, r);

	update(id * 2, l, mid, u, v, k);
	update(id * 2 + 1, mid + 1, r, u, v, k);

	st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n, k;

    cin >> n >> k;

    FOR (i, 1, n) {
    	cin >> a[i];
    }

    FORD (i, n, 1) {
    	while (decreaseSeq.size() && a[decreaseSeq.back()] <= a[i]) {
    		decreaseSeq.pop_back();
    	}
    	if (decreaseSeq.size()) p[i] = decreaseSeq.back();
    	else p[i] = n + 1;
    	decreaseSeq.pb(i);
    }

    FOR (i, 1, n) {
    	v[p[i]].pb(i);
    }

    eulerTour.pb(0);
    dfs(n + 1);

    //for (auto i: eulerTour) cout << i << " "; cout << endl;
    //FOR (i, 1, n) cout << tin[i] << " " << tout[i] << endl;

    int N = 2 * (n + 1);

    FOR (i, 1, k) {
    	update(1, 1, N, tin[i], tout[i], 1);
    }
    cout << st[1] << " ";

    FOR (i, k + 1, n) {
    	int j = i - k;

    	update(1, 1, N, tin[j], tout[j], -1000);
    	update(1, 1, N, tin[i], tout[i], 1);
    	
    	cout << st[1] << " ";
    }

	
    return 0;
}