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

int a[6] = {4 , 8, 15, 16, 23, 42};
int b[6], m[6];
vector<int> v[10000000];

int ask(int i, int j) {
	// return a[i] * a[j];
	int x;
	cout << "? " << i + 1 << " " << j + 1 << endl;
	cin >> x;
	return x;
}


int main()
{//IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int prod = 1;
	FOR (i, 0, 5) prod *= a[i];

	FOR (i, 0, 5) {
		FOR (j, i + 1, 5) {
			v[a[i] * a[j]].pb(i);
			v[a[i] * a[j]].pb(j);
		}
	}

	FOR (i, 1, 4) {
		m[i] = ask(0, i);
	}	

	for (auto i: v[m[1]]) {
		for (auto j: v[m[2]]) {
			if (i == j) {
				b[0] = a[i];
				break;
			}
 		}
	}
	FOR (i, 1, 4) b[i] = m[i] / b[0];

	FOR (i, 0, 4) {
		prod /= b[i];
	}
	b[5] = prod;

	cout << "! ";
	FOR (i, 0, 5) {
		cout << b[i] << " ";
	}
	cout << endl;

	return 0;
}