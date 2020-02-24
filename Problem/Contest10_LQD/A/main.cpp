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

int main()
{//IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	int dist = 1;
	char space = '-';

	FOR (i, 1, (n - 1) / 2) {
		if (i == 1) {
			FOR (j, 1, (n - 1) / 2) cout << space;
			cout << "*";
			FOR (j, 1, (n - 1) / 2) cout << space;
			cout << endl;
		}
		else {
			FOR (j, 1, (n - 1) / 2 - i + 1) cout << space;

			cout << "*";
			FOR (j, 1, dist) cout << space;
			cout << "*";

			FOR (j, 1, (n - 1) / 2 - i + 1) cout << space;

			cout << endl;
			dist += 2;
		}
	}

	FOR (i, 1, n) cout << "*"; cout << endl;

	int a = 2, b = n - 1;

	FOR (i, 1, n - 2) {
		cout << "*";
		FOR (j, 2, n - 1) {
			if (j == a || j == b) cout << "*";
			else cout << space;
		}
		a++;
		b--;
		cout << "*" << endl;
	}

	FOR (i, 1, n) cout << "*"; cout << endl;

	return 0;
}