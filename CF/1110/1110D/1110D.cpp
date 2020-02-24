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
/*
const int N = 5;
int c[N + 1];

struct data {
	int a[N + 1];
	int val;

	data(){}

	data(int b[N + 1]) {
		val = 0;
		FOR (i, 1, N) {
			a[i] = b[i];
			val += a[i] * c[i];
		}
	}

	data operator + (data b) {
		data res;
		FOR (i, 1, N) {
			res.a[i] = a[i] + b.a[i];
		}
		res.val = val + b.val;
		return res;
	}

	data operator - (data b) {
		data res;
		FOR (i, 1, N) {
			res.a[i] = a[i] - b.a[i];
		}
		res.val = val - b.val;
		return res;
	}

	bool operator == (data b) {
		return val == b.val;
	}
	friend ostream& operator << (ostream &os, const data &a) {
		os << "[";
		FOR (i, 1, N) {
			if (i != N) os << a.a[i] << ", "; 
			else os << a.a[i] << "]";
		}
		return os;
	}
};

ll has(vector<data> &v) {
	ll res = 0;
	ll b = 1;
	FOR (i, 1, N) {
		res = res + b * v[i].val;
		b = b * 100;
	}
	return res;
}

unordered_map<ll, bool> dd; 

void dfs(vector<data> &v) {
	ll u = has(v);
	if (dd[u]) return;
	FOR (i, 1, N) {
		cout << v[i].val << " "; 
	}
	cout << endl;
	FOR (i, 1, N) {
		cout << v[i] << " ";
	}
	cout << endl;

	dd[u] = 1;

	FOR (i, 2, N - 1) {
		v[i] = v[i - 1] + v[i + 1] - v[i];
		dfs(v);
		v[i] = v[i - 1] + v[i + 1] - v[i];
	}
}


vector<data> V;
int a[N + 1];
*/
ll c[1000005], t[1000005];
vector<ll> C, T;

int main()
{IN;OUT;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    FOR (i, 1, n) cin >> c[i];
    FOR (i, 1, n) cin >> t[i];
    /*
    V.pb(data());
    FOR (i, 1, N) {
    	a[i] = 1;
    	V.pb(data(a));
    	a[i] = 0;
    }

    dfs(V);
    */
    if (c[1] != t[1] || c[n] != t[n]) {
    	cout << "NO";
    	return 0;
    }

    FOR (i, 1, n - 1) {
    	C.pb(c[i + 1] - c[i]);
    	T.pb(t[i + 1] - t[i]);
    } 

    sort(all(C));
    sort(all(T));

    FOR (i, 0, n - 2) {
    	if (C[i] != T[i]) {
    		cout << "NO";
    		return 0;
    	}
    }
	cout << "YES";
    return 0;
}