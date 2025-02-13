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
{IN; OUT;
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;
	
	FOR (z, 1, t) {
		cout << "Case #" << z << ": ";   
		string s;
		cin >> s;
		
		int n = s.length();

		int a = 0, b = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '.') {
				a++;
			}
			else if (s[i] == 'B') {
				b++;
			}
		}

		if (a == 1 && b) {
			cout << "Y" << endl;
		}
		else if (a && b >= 2) {
			cout << "Y" << endl;
		}
		else {
			cout << "N" << endl;
		}
	}

	return 0;
}