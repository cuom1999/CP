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

int d[500], e[500];
string s, a, b;
int n;
int k;

bool calc(int i) {
	if (i == n) return 1;
	
	if (d[s[i]]) {
		if (d[s[i]] == a[i]) {
			return calc(i + 1);
		}
		else if (d[s[i]] > a[i]) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		if (!e[a[i]]) {
			d[s[i]] = a[i];
			e[a[i]] = s[i];
			if (calc(i + 1)) return 1;
			d[s[i]] = 0;
			e[a[i]] = 0;
		}
		FOR (j, a[i] + 1, 'a' + k - 1) {
			if (!e[j]) {
				d[s[i]] = j;
				e[j] = s[i];
				return 1;
			}
		}
		return 0;
	}
}


bool calc1(int i) {
	if (i == n) return 1;

	if (d[s[i]]) {
		if (d[s[i]] == b[i]) {
			return calc1(i + 1);
		}
		else if (d[s[i]] < b[i]) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		if (!e[b[i]]) {
			d[s[i]] = b[i];
			e[b[i]] = s[i];
			if (calc1(i + 1)) return 1;
			d[s[i]] = 0;
			e[b[i]] = 0;
		}
		FOR (j, 'a', b[i] - 1) {
			if (!e[j]) {
				d[s[i]] = j;
				e[j] = s[i];
				return 1;
			}
		}
		return 0;
	}
}

mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());

ll Rand(ll l, ll r){
	uniform_int_distribution<ll> rnd(l,r);
	return rnd(gen);
}


bool cmp(string a, string b) {
	int n = a.size();
	FOR (i, 0, n - 1) {
		if (a[i] < b[i]) return 0;
		if (a[i] > b[i]) return 1;
	}
	return 0;
}


void test() {

}



void gentest() {
	//k = Rand(1, 8);

	//n = Rand(5, 1000000);
	n = 1e6;
	k = 26;
	s.clear(); a.clear(); b.clear();
	FOR (i, 1, n) {
		s += (char) (Rand(0, k - 1) + 'a');
		a += (char) (Rand(0, k - 1) + 'a');
		b += (char) (Rand(0, k - 1) + 'a');
	}
	if (cmp(a, b)) swap(a, b);
	//cout << k << endl;
	//cout << s << " " << a << " " << b << endl;

}
char C[1000005];
vector<int> v;
int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	//cin >> t;
	sf("%d", &t);
	FOR (z, 1, t) {
		FOR (i, 'a', 'z') d[i] = e[i] = 0;
		//cin >> k;		
		sf("%d", &k);
		//cin >> s;
		sf("%1000000s", C);
		s = C;
		sf("%1000000s", C);
		a = C;
		sf("%1000000s", C);
		b = C;
		//cin >> a;
		//cin >> b;
		//gentest();
		n = s.size();
		if (calc(0) && calc1(0)) {
			//cout << "YES" << endl;
			pf("YES\n");
			FOR (i, 'a', 'a' + k - 1) {
				if (!e[i]) v.pb(i);
			}
			int cnt = 0;
			FOR (i, 'a', 'a' + k - 1) {
				if (!d[i]) {
					d[i] = v[cnt];
					cnt++;
				}
			}
			FOR (i, 'a', 'a' + k - 1) {
				//cout << (char)d[i];
				pf("%c",d[i]);
			}
			//cout << endl;
			pf("\n");
			//FOR (i, 'a', 'c') cout << (char)e[i]; cout << endl;
		}
		else {
			//cout << "NO" << endl;
			pf("NO\n");
		}
		v.clear();
	}
	
	return 0;
}