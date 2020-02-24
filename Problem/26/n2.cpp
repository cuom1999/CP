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
#define flog2(n) 32 - __builtin_clz(n) - 1
#define popcnt(n) __builtin_popcountll(n)

using namespace std;

typedef pair < int, int > II;
typedef pair < ll, ll > pll;

int a[2005][2005], s[2005][2005];

int l[2005][2005]; // the longest 1 to the left from (i,j)
int preMin[2005], sufMin[2005];

struct RMQ {
	vector< vector<int> > spt; 
	RMQ() {

	}

	RMQ(const vector<int> &v) {
		spt.resize(v.size());
		int n = v.size();
		int logN = flog2(n);
		
		for (int i = 0; i < n; i++) {
			spt[i].resize(logN + 1);
		}

		for (int len = 0; (1 << len) <= n; len++) {
			for (int i = 0; i + (1 << len) - 1 < n; i++) {
				if (!len) {
					spt[i][len] = v[i];
				}
				else {
					spt[i][len] = min(spt[i][len - 1], spt[i + (1 << (len - 1))][len - 1]);
				}
			}
		}
	}

	int getMin(int u, int v) {
		int k = flog2(v - u + 1);
		return min(spt[u][k], spt[v - (1 << k) + 1][k]); 
	} 
};

ll solve(vector<int> &v) {
	ll res = 0;
	int n = v.size();

	// res = sum_j ( min[0 -> j] + min[1 -> j] + ... + min[j -> j] );

	RMQ rmq(v);

	for (int i = 0; i < n; i++) {

		int left, right;

		if (i == 0 || v[i - 1] <= v[i]) {
			left = i ;
		}
		else {
			int L = 0, R = i - 1;
			while (L < R) {
				int mid = (L + R) / 2;
				if (rmq.getMin(mid, i - 1) <= v[i]) {
					L = mid + 1;
				}
				else {
					R = mid;
				}
			}

			left = L;
		}

		int L = i, R = n - 1;
		while (L < R) {
			int mid = (L + R + 1) / 2;
			if (rmq.getMin(i, mid) < v[i]) {
				R = mid - 1;
			}
			else {
				L = mid;
			}
		}

		right = L;
		//cout << i << " " << left << " " << right << endl;

		res += (i - left + 1) * 1ll * (right - i + 1) * v[i];
	}

	return res;
}


int main()
{IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    FOR (i, 1, n) {
    	FOR (j, 1, m) {
    		char c;
    		cin >> c;
    		if (c == '1') a[i][j] = 1;
    	}
    }

    FOR (i, 1, n) {
    	FORD (j, m, 1) {
    		if (a[i][j] == 1) {
    			l[i][j] = l[i][j + 1] + 1;
    		}
    	}
    }

    ll res = 0;

    FOR (j, 1, m) {
    	vector<int> v;

    	FOR (i, 1, n + 1) {
    		if (a[i][j] == 0) {
    			res += solve(v);
    			v.clear();
    		}
    		else {
    			v.pb(l[i][j]);
    		}
    	}
    }

    cout << res << endl;




	
    return 0;
}