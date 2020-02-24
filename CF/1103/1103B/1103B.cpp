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

int a;
char query(int x, int y, int a) {
	if ((x % a) >= (y % a)) return 'x';
	return 'y';
}

void ask(int x, int y) {
	cout << "? " << x << " " << y << endl;
	//cout << query(x, y, a) << endl;
}

int solve(int l, int r) {
	if (r - l == 1) {
		ask(l, r);
		char ans;
		cin >> ans;
		if (ans == 'x') return r;
		return l;
	}
	int mid = (l + r) / 2;
	ask(mid, r);
	char ans;
	cin >> ans;
	if (ans == 'x') {
		return solve(mid + 1, r);
	}
	return solve(l, mid);
}

int preSolve() {
	ask(0, 1);
	char ans;
	cin >> ans;
	if (ans == 'x') return 1;
	ask(1, 2);
	cin >> ans;
	if (ans == 'x') return 2;

	FOR (i, 1, 29) {
		ask((1 << i), 1 << (i + 1));
		cin >> ans;
		if (ans == 'x') {
			return solve((1 << i) + 1, 1 << (i + 1));
		}
	}
	return 0;
}

int main()
{//IN;
    ios::sync_with_stdio(0);
    cin.tie(NULL);
	while (1) {
		//cin >> a;
		string st;
		cin >> st;
		if (st[0] == 'e') return 0; 
		if (st[0] == 'm') return 0;
		int res = preSolve();
		cout << "! " << res << endl; 
	}
	
    return 0;
}