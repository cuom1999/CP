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



int main()
{IN;
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	string s;
	int n;

	cin >> s >> n;

	if (s[0] == 'r') {
		if (n == 1) {
			cout << 0;
		}
		else if (n <= 5) {
			cout << 1;
		}
		else if (n <= 10) {
			cout << 2;
		}
		else if (n <= 15) {
			cout << 3;
		}
		else {
			cout << 4;
		}
	}
	else if (s[0] == 'c') {
		if (n == 1) {
			cout << 0;
		}
		else if (n <= 7) {
			cout << 1;
		}
		else if (n <= 14) {
			cout << 2;
		}
		else {
			cout << 3;
		}
	}
	else {
		if (n == 1) {
			cout << 0;
		}
		else if (n <= 4) {
			cout << 1;
		}
		else if (n <= 8) {
			cout << 2;
		}
		else if (n <= 12) {
			cout << 3;
		}
		else if (n <= 16) {
			cout << 4;
		}
		else cout << 5;
	}

	return 0;
}