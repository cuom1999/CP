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

	int n, x;
	cin >> n >> x;

	if ((1 << n) <= x) {
		cout << (1 << n) - 1 << endl;
		FOR (i, 1, (1 << n) - 1) {
			int a = i ^ (i - 1);
			cout << a << " ";
		}
	}
	else {
		cout << (1 << (n - 1)) - 1 << endl;
		
		vector<int> res;
		res.pb(0);
		FOR (i, 1, (1 << n) - 1) {
			if (i < (i ^ x)) res.pb(i);
		}

		for (int i = 1; i < res.size(); i++) {
			int a = res[i] ^ res[i - 1];
			cout << a << " ";
		}
	}

	return 0;
}