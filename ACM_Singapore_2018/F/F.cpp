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

int a[400005];
int d[400005];
set<int> S;
vector<int> v[400005];

struct query {
	int l, r;
	query(int __l = 0, int __r = 0) {
		l = __l;
		r = __r;
	}
	bool operator < (query a) {
		if (r == a.r) return l < a.l;
		return r < a.r;
	}
};

vector<query> Q;

int fen[400005];
int n;

void add(int u, int v) {
	for (int i = u; i <= n; i += i & -i) {
		fen[i] += v;
	}
}

int sum(int u) {
	int res = 0;
	for (int i = u; i; i -= i & -i) {
		res += fen[i];
	}
	return res;
}

int last[400005];
set<int> S1;
int cnt[400005];
int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    FOR (i, 1, n) {
    	cin >> a[i];
    }
    reverse(a + 1, a + n + 1);

    FOR (i, 1, n) {
    	S.insert(a[i]);
    	d[i] = S.size();
    	v[a[i]].pb(i);
    }

    FOR (i, 1, n) { 
    	if (v[i].size() <= 1) continue;
    	int b = v[i].back();
    	for (int j = 0; j + 1 < v[i].size(); j++) {
    		Q.pb(query(v[i][j], b));
    	}
    }

    FOR (i, 1, n) {
    	Q.pb(query(0, i));
    }
    sort(all(Q));

    int M = INF;


    for (auto i: Q) {
    	if (i.l == 0) {
    		int u = a[i.r];
    		if (last[u] == 0) {
    			add(i.r, 1);
    		}
    		else {
    			add(last[u], -1);
    			add(i.r, 1);
    		}
    		last[u] = i.r;
    	}
    	else {
    		int res = sum(i.r) - sum(i.l - 1);
    		//cout << i.l << " " << i.r << " " << res << endl;
    		if (res + d[i.l] - 1 != d[i.r]) M = min (M, a[i.r]);
    	}
    	//FOR (j, 1, n) cout << sum(j) - sum(j - 1) << " "; cout << endl;
    }

    if (M == INF) {
    	cout << -1;
    	return 0;
    }
    int N = INF;

    FOR (i, 1, v[M][0] - 1) {
    	S1.insert(a[i]);
    }

    for (auto j: S1) cnt[j]++;

    for (int j = 0; j + 1 < v[M].size(); j++) {
    	S1.clear();
    	FOR (i, v[M][j] + 1, v[M][j + 1] - 1) {
    		S1.insert(a[i]);
    	}
    	for (auto i: S1) cnt[i]++;
    }
	

	FOR (i, 1, n) {
		if (cnt[i] > 1) {
			cout << M << " " << i << endl;
			return 0;
		}
	}

    
	
    return 0;
}