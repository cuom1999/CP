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

//const int M = 3;
//const int n = 5;
/*
ll vecToNum(vector<int> &v) {
	ll res = 0;
	FOR (i, 0, v.size() - 1) {
		res = 10 * res + v[i]; 
	}
	return res;
}

vector<int> numToVec(ll x) {
	vector<int> v;
	while (x) {
		v.pb(x % 10);
		x /= 10;
	}
	reverse(all(v));
	return v;
}

map<ll, int> d;

void gen(int index, int pre, vector<int> &v) {
	if (index == n) {
		//for (auto i: v) cout << i << " "; cout << endl;
		//FORD(i, n - 1, 0) cout << v[i] << " "; cout << endl;
		
		vector<int> p;

		FOR (i, 0, (1 << M) - 1) {
			int indMax = 0, maxVal = -1;
			FOR (j, 0, n - 1) {
				if (maxVal < (v[j] ^ i)) {
					maxVal = v[j] ^ i;
					indMax = j;
				}
			}
			//cout << n - indMax << " "; 
			p.pb(n - indMax);
		}
		//cout << endl << endl;
		d[vecToNum(p)]++;

		return;
	}

	FOR (i, pre + 1, (1 << M) - 1) {
		v.pb(i);
		gen(index + 1, i, v);
		v.pop_back();
	}
}

vector<int> rong;
*/

const ll K = 1e9 + 7;
int p[(1 << 16) + 5];

int dd[(1 << 16) + 5];

ll solve(int l, int r) {
	if (l == r) return 1;
	int mid = (l + r) / 2;

	bool isPalin = 1;

	FOR (k, l, mid) {
		if (p[k] != p[mid - l + 1 + k]) {
			isPalin = 0;
			break;
		}
	}

	bool isTrue = 1;

	if (!isPalin) {
		vector<int> vals;

		FOR (i, l, mid) {
			dd[p[i]] = 1;
			vals.pb(p[i]);
		}

		FOR (i, mid + 1, r) {
			if (dd[p[i]] == 1) {
				isTrue = 0;
			}
		}

		for (auto i: vals) dd[i] = 0;
	}

	if (isPalin) {
		return 2ll * solve(l, mid) % K;
	}

	if (isTrue) return solve(l, mid) * solve(mid + 1, r) % K;

	return 0;
}

int main()
{IN; //OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    //gen(0, -1, rong);

    //cout << endl;

    
    /*for (auto i: d) {
    	vector<int> v = numToVec(i.first);
    	for (auto j: v) {
    		cout << j << " ";
    	}
    	cout << ": " << i.second << endl;
    }*/

    int n, m;

    cin >> m >> n;

    FOR (i, 0, (1 << m) - 1) {
    	cin >> p[i];
    }

    cout << solve(0, (1 << m) - 1) << endl;



	
    return 0;
}